/**
    CS-11 Asn 2
    format.cpp
    Purpose: IMPLEMENTATION. Library to format the input file. Get one like after the other.

    @author Ayoub Bargach
    @version 1.0
*/

/**
    CTOR

    @param The path of the file
*/

#include "format.hpp"

FileManipulator::FileManipulator(std::string path)
    : myfile(path), line(0), lastLine("") {

    if (myfile.is_open())
    {
        std::cout << "The file have been found." << std::endl;
    }
    else std::cout << "Unable to open file : Please specify another path." << std::endl;
}

std::string FileManipulator::getLine() {
    line++; // Increment the line pointer

    // If there is another line, return it. If not return "".
    // Note : Before sending back the line we remove all the whitespaces. TODO: Need to accept tabs.
    if (std::getline(myfile, lastLine)) {

        auto begin = lastLine.begin();
        auto end = lastLine.end();

        std::unique_copy(lastLine.begin(), lastLine.end(), std::back_insert_iterator<std::string>(lastLine), [](char a,char b){ return isspace(a) && isspace(b);}); 
                
        lastLine.erase(begin, end);

        if (lastLine.empty()) return " ";
        return lastLine;
    }
    
    return "";
}

FileManipulator::~FileManipulator() {
    if (myfile.is_open())
    {
        myfile.close();
    }
}