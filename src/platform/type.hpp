/**
    CS-11 Asn 2
    type.hpp
    Purpose: Types declaration.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <set>
#include <iostream>

// DataValue Struct by class
class DataValue {
public:
    double value;
    bool valid;
};

// Label management
class Label {
private:
    static std::set<std::string> labels;
public:
    std::string value;
    Label(std::string value);
};

#endif