/**
    CS-11 Asn 2
    bus.hpp
    Purpose: BUS specs.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <list>
#include "component.hpp"
#include "readable.hpp"
#include "../io/config.hpp"


class Bus : public Component, public Readable {
private:
  Label l;
  int counter;
  int width;
  std::list<DataValue> pending; //FIFO structure
  std::list<DataValue> ready;
public:
  std::string sourceLabel;
  Readable* source;
  Bus(Config & c, bool verbose);
  void bind(Readable* cmpt); // Pointer is mandatory here, abstract class cannot be bind by Value and reference will be initialized and cannot be changed
  void simulate();
  DataValue read();
};

#endif