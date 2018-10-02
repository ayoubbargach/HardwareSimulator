/**
    CS-11 Asn 2
    platform.hpp
    Purpose: The platform is the central core of our implemention.

    @author Ayoub Bargach
    @version 1.0
*/


#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <map>

#include "component/Component.hpp"
#include "format.hpp"
#include "config.hpp"

// Then we include all the components
#include "component/cpu.hpp"
#include "component/bus.hpp"
#include "component/memory.hpp"
#include "component/display.hpp"



class Platform {
private:
    int steps; // Input by the user
    bool verbose; // Input by the user
    FileManipulator myFile;
    std::map<std::string, Component *> components; // LABEL -> component
public:
    Platform(std::string generalConfigFile, int steps, bool verbose);
    void bind(); // Perform the binding of all the components
    void simulate(); // Simulate all the components
};


#endif