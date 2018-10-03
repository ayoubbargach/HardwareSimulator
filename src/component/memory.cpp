/**
    CS-11 Asn 2
    memory.cpp
    Purpose: Memory specs.

    @author Ayoub Bargach
    @version 1.0
*/

#include "memory.hpp"

Memory::Memory(Config & c, bool verbose)
    : Component(MEMORY), sourceLabel(c.entries["SOURCE"]), l(c.entries["LABEL"]), currentAccess(0), size(std::stoi(c.entries["SIZE"])), access(std::stoi(c.entries["ACCESS"])), verbose(verbose) { //First access works
    
    if (verbose) {
        std::cout << "--- MEMORY Loading ---" << std::endl;
        std::cout << "Label : " << c.entries["LABEL"] << std::endl;
        std::cout << "Size : " << std::stoi(c.entries["SIZE"]) << std::endl;
        std::cout << "Access : " << std::stoi(c.entries["ACCESS"]) << std::endl;
        std::cout << "Source : " << c.entries["SOURCE"] << std::endl;
        std::cout << "--- end ---" << std::endl;
    }
}

int Memory::getUnread() {
    return circularBuffer.size();
}

int Memory::getFree() {
    if (verbose) {
        std::cout << "Number of unread values : " << this->getUnread() << std::endl;
        std::cout << "Number of free places : " << size - this->getUnread() << std::endl;
    }
    return size - getUnread();
}

void Memory::bind(Readable* cmpt) {
    this->source = cmpt;
}

void Memory::simulate() {

    if (currentAccess == 0) { // we can read
        DataValue temp = (*source).read(); // first read

        while(temp.valid) {
            
            if (this->getFree() == 0) { // If there is no more place in the buffer (more than the size specified)
                circularBuffer.pop_back();
                circularBuffer.push_front(temp);
            }
            else {
                circularBuffer.push_front(temp);
            }
            temp = (*source).read();
        }

        currentAccess = access;
    }
    else {
        currentAccess--;
    }
}

DataValue Memory::read() {
    // We check if the list is empty

    if (!circularBuffer.empty()) {
        DataValue recover = circularBuffer.back(); // We take the last value (FIFO) and then we pop it
        circularBuffer.pop_back(); // This buffer is the same as the others. Once the value is read, it will not be read another time so we pop it.
        // If there is nothing else to read we send Invalid DataValue.
        return recover;
    }

    return DataValue(0, 0); // If the list is empty, we return an invalid DataValue
}