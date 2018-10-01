/**
    CS-11 Asn 2
    format.hpp
    Purpose: Library to format the input file. Get one like after the other.

    @author Ayoub Bargach
    @version 1.0
*/


#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class FileManipulator {
private:
    std::ifstream myfile;
    int line;
    std::string lastLine;

public:
    FileManipulator(std::string path);
    ~FileManipulator();
    std::string getLine();
};


#endif