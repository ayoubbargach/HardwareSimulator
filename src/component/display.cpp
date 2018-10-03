/**
    CS-11 Asn 2
    display.cpp
    Purpose: Display specs.

    @author Ayoub Bargach
    @version 1.0
*/

#include "display.hpp"

Display::Display(Config c)
    : Component(DISPLAY), sourceLabel(c.entries["SOURCE"]), l(c.entries["LABEL"]), currentRefresh(0), refresh(std::stoi(c.entries["REFRESH"])) {

}

void Display::simulate() {

    if (currentRefresh == 0) { // we can read
        DataValue temp = (*source).read(); // first read

        std::cout << "--- DISPLAY begin ---" << std::endl ;

        while(temp.valid) {
            
            temp = (*source).read();

            std::cout << temp.value << " // ";
        }

        std::cout << "  " << std::endl ;

        std::cout << "--- end ---" << std::endl ;

        currentRefresh = refresh;
    }
    else {
        currentRefresh--;
    }
}