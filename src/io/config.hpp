/**
    CS-11 Asn 2
    config.hpp
    Purpose: Read and "translate" to a map a config file for a component. Uses FileManipulator

    @author Ayoub Bargach
    @version 1.0
*/


#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <map>
#include "format.hpp"


class Config {
private:
    FileManipulator myFile;
public:
    std::map<std::string, std::string> entries;
    Config();
    Config(std::string path);
};


#endif