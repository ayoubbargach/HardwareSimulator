/**
    CS-11 Asn 2
    component.hpp
    Purpose: Component definition.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

enum component_t { NONE, CPU, BUS, MEMORY, DISPLAY};

class Component {
public:
  int priority;
  component_t type;
  Component (component_t t);
  virtual void simulate() = 0;
};

#endif