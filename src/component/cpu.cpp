/**
    CS-11 Asn 2
    cpu.cpp
    Purpose: CPU implementation.

    @author Ayoub Bargach
    @version 1.0
*/

#include "cpu.hpp"

// CTRO of Cpu from config

Cpu::Cpu(Config c) 
    : l(c.entries["LABEL"]), coreFlag(0), cores(std::stoi(c.entries["CORES"])), frequency(std::stoi(c.entries["FREQUENCY"])), programPath(c.entries["PROGRAM"]) {
    
}

// TODO simulate and read