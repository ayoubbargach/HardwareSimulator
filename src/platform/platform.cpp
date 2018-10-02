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
        


        if (typeComponent == "CPU") {
            Component * tempComponent = new Cpu( Config(line), verbose) );
            components.insert(std::pair<std::string,Component>(labelComponent, tempComponent));
        }
        else if (typeComponent == "BUS") {
            components.insert(std::pair<std::string,Component>(labelComponent, &Bus( Config(line), verbose) ));
        }
        else if (typeComponent == "MEMORY") {
            components.insert(std::pair<std::string,Component>(labelComponent, &Memory( Config(line), verbose) ));
        }
        else if (typeComponent == "DISPLAY") {
            components.insert(std::pair<std::string,Component>(labelComponent, &Display( Config(line)) ));
        }
        else {
            std::cout << "A component have not been recognized, this issue may occur on failures. Please review your config platform file" << std::endl;
        }
        
    }
}