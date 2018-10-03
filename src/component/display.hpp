/**
    CS-11 Asn 2
    display.hpp
    Purpose: Display specs.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <list>
#include "Component.hpp"
#include "Readable.hpp"
#include "io/config.hpp"
#include "platform/type.hpp"


class Display : public Component {
private:
  Label l;
  int refresh;
  int currentRefresh;
  std::string sourceLabel;
  Readable* source;
public:
  Display(Config c);
  void simulate();
};

#endif