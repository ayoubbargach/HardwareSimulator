/**
    CS-11 Asn 2
    config.cpp
    Purpose: Read and "translate" to a map a config file. Uses FileManipulator

    @author Ayoub Bargach
    @version 1.0
*/


#include "config.hpp"

Config::Config(std::string path) 
    : myFile(path) {

    // All the work is done by the contructor, we generate here the list of operations
    
    std::string line;
    int flag = 0;
    
    while ((line = myFile.getLine()) != "") {

        std::istringstream iss(line);
        std::string element;
        std::string key;
        std::string value;

        while (getline( iss, element, ' ')) {

            //If the element if empty, we skip it TODO / Implement expections
            if ( !element.empty()) {
                switch (flag) {
                    case 0:
                        // We delete the last char ':'
                        element.pop_back();
                        key = element;
                        flag++;
                        break;
                    case 1:
                        value = element;
                        flag++;
                        break;
                    default:
                        break;
                }                    
            }
        }

        entries.insert( std::pair<std::string, std::string>(key, value));

        flag=0;
    }
}

