/**
    CS-11 Asn 2
    type.cpp
    Purpose: Types implementation.

    @author Ayoub Bargach
    @version 1.0
*/

#include "type.hpp"

DataValue::DataValue(double value, bool valid)
    : value(value), valid(valid) {

}

Label::Label(std::string value)
    : value(value) {

    // Used to change the name of the value if already included
    int i;
    
    // We start by searching for the value in the set
    while (labels.find(value) != labels.end()) {
        this->value += std::to_string(i);
        i++;
        std::cout << "The label is already included, it have been renamed to :" << value << std::endl;
    }

    // value is unique here :
    labels.insert( this->value);
}
