/**
    CS-11 Asn 2
    bus.hpp
    Purpose: BUS specs.

    @author Ayoub Bargach
    @version 1.0
*/

#include "bus.hpp"

Bus::Bus(Config & c, bool verbose)
    : Component(BUS), sourceLabel(c.entries["SOURCE"]), l(c.entries["LABEL"]), counter(0), width(std::stoi(c.entries["WIDTH"])) {
    
    if (verbose) {
        std::cout << "--- BUS Loading ---" << std::endl;
        std::cout << "Label : " << c.entries["LABEL"] << std::endl;
        std::cout << "Source : " << c.entries["SOURCE"] << std::endl;
        std::cout << "Width : " << std::stoi(c.entries["WIDTH"]) << std::endl;
        std::cout << "--- end ---" << std::endl;
    }
}

void Bus::bind(Readable* cmpt) {
    this->source = cmpt;
}

void Bus::simulate() {
    int currentWidth = width;

    // We start by putting all the pending value in the ready list
    while (!pending.empty()) {
        ready.push_front(pending.back());
        pending.pop_back();
    }

    // We read as much as the width
    while (currentWidth != 0) {
        pending.push_front(source->read());

        if (pending.front().valid == 0) {
            currentWidth = 0; // The return value is valid = 0 It means that the source was not able to send us a value (there is nothing else to read)
            pending.pop_front(); // We delete this new value
        }
        else {
            currentWidth--;
        }
    }
}

DataValue Bus::read() {
    // We check if the list is empty

    if (!ready.empty()) {
        DataValue recover = ready.back(); // We take the last value (FIFO) and then we pop it
        ready.pop_back();
        return recover;
    }

    return DataValue(0, 0); // If the list is empty, we return an invalid DataValue
}
