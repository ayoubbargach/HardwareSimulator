/**
    CS-11 Asn 2
    platform.cpp
    Purpose: This implementation control the initialisation of all components and their simulation.

    @author Ayoub Bargach
    @version 1.0
*/

#include "platform.hpp"

Platform::Platform(std::string generalConfigFile, int steps, bool verbose)
    : myFile(generalConfigFile), steps(steps), verbose(verbose) {
    
    // Here we init all the components of the platform, thus, we start by extracting the paths
    std::string line;
    Config *c;
    std::string typeComponent;
    std::string labelComponent;
    
    while ((line = myFile.getLine()) != "") {

        c = new Config(line);

        typeComponent = c->entries["TYPE"];
        labelComponent = c->entries["LABEL"];
        
        // We add to components and to readables lists. Will be used respectively for simulate() and bind()
        if (typeComponent == "CPU") {
            Cpu * myCpu = new Cpu( *c, verbose);
            components.insert(std::pair<std::string,Component *>(labelComponent, myCpu));
            readables.insert(std::pair<std::string,Readable *>(labelComponent, myCpu));
        }
        else if (typeComponent == "BUS") {
            Bus * myBus = new Bus( *c, verbose);
            components.insert(std::pair<std::string,Component *>(labelComponent, myBus));
            readables.insert(std::pair<std::string,Readable *>(labelComponent, myBus));
        }
        else if (typeComponent == "MEMORY") {
            Memory * myMemory = new Memory( *c, verbose);
            components.insert(std::pair<std::string,Component *>(labelComponent, myMemory));
            readables.insert(std::pair<std::string,Readable *>(labelComponent, myMemory));
        }
        else if (typeComponent == "DISPLAY") {
            Display * myDisplay = new Display( *c);
            components.insert(std::pair<std::string,Component *>("Display", myDisplay));
        }
        else {
            std::cout << "A component have not been recognized, this issue may occur on failures. Please review your config platform file" << std::endl;
        }
        
    }

    std::cout << "--- INIT of all components : OK ---" << std::endl;
}

void Platform::bind() {
    // We analyse the list of configs to add read if a source is needed
    // We use iterator to explore all the array

    component_t type = NONE;
    std::string source;
    Bus *b;
    Memory *m;
    Display *d;

    for (auto & mapPair : components ) {
        std::cout << "Analysis of label : " << mapPair.first << std::endl;

        type = mapPair.second->type;


        // If any of the types that need to be sourced :
        switch (type) {
            case BUS:
                b = dynamic_cast<Bus *>(mapPair.second);
                source = b->sourceLabel;
                b->source = readables[source];
                break;
            case MEMORY:
                m = dynamic_cast<Memory *>(mapPair.second);
                source = m->sourceLabel;
                m->source = readables[source];
                break;
            case DISPLAY:
                d = dynamic_cast<Display *>(mapPair.second);
                source = d->sourceLabel;
                d->source = readables[source];
                break;
            default:
                source = "none";
                break;
        }
        std::cout << "Aim of binding : " << source << std::endl;
    }

    std::cout << "--- BINDING operation : OK ---" << std::endl;
}

void Platform::simulate() {
    // We iterate over all components to simulate them all !

    std::cout << "--- START simulation ---" << std::endl;
    int i;

    for(i=0; i<steps; i++) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "/!\\ STEP /!\\ : " << i << " >" <<std::endl;
        for (auto & mapPair : components ) {
            std::cout << std::endl;
            std::cout << "-- Simulation of component : " << mapPair.first << " -- " << std::endl;
            mapPair.second->simulate();
        }
    }

}