/**
    CS-11 Asn 2
    cpu.cpp
    Purpose: CPU implementation.

    @author Ayoub Bargach
    @version 1.0
*/

#include "cpu.hpp"

// CTRO of Cpu from config

Cpu::Cpu(Config & c, bool verbose) 
    : Component(CPU), l(c.entries["LABEL"]), coreFlag(1), cores(std::stoi(c.entries["CORES"])), frequency(std::stoi(c.entries["FREQUENCY"])),
     programPath(c.entries["PROGRAM"]), p(c.entries["PROGRAM"], verbose), verbose(verbose) {
    
    if(verbose) {
        // Print information about the component
        std::cout << "--- CPU Loading ---" << std::endl;
        std::cout << "Label : " << c.entries["LABEL"] << std::endl;
        std::cout << "Total number of cores : " << c.entries["CORES"] << std::endl;
        std::cout << "Frequency : " << std::stoi(c.entries["FREQUENCY"]) << std::endl;
        std::cout << "--- end ---" << std::endl;
    }
}

void Cpu::simulate() {
    int currentStep = this->frequency;
    double result = 0;

    // while we are not at the end of the program and for all the steps
    while (coreFlag <= cores && !p.end() && currentStep >= 0) {
        result = p.compute();

        if (this->verbose) {
            std::cout << result << std::endl;
        }

        // Save the result in the FIFO (A DataValue object's list)
        cpuRegister.push_front(DataValue(result, 1)); // We put it at valid 

        p.increment();
        currentStep--;
    }

    if (p.end()) {
        if (coreFlag <= cores) {
            coreFlag++;
            p.reset();
        }
    }
}

DataValue Cpu::read() {
    // We check if the list is empty

    if (!cpuRegister.empty()) {
        DataValue recover = cpuRegister.back(); // We take the last value (FIFO) and then we pop it
        cpuRegister.pop_back();
        return recover;
    }

    return DataValue(0, 0); // If the list is empty, we return an invalid DataValue
}