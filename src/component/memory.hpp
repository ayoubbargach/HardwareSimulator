/**
    CS-11 Asn 2
    memory.hpp
    Purpose: Memory specs.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <string>
#include <list>
#include <iostream>
#include "Component.hpp"
#include "Readable.hpp"
#include "io/config.hpp"


class Memory : public Component, public Readable {
private:
  bool verbose;
  Label l;
  int size;
  int access;
  int currentAccess;
  std::string sourceLabel;
  Readable* source;
  std::list<DataValue> circularBuffer; // a circular buffer is like FIFO structure limited to N cases, this buffer can only be manipulated by put, get and del
public:
  Memory(Config c, bool verbose);
  void bind(Readable* cmpt); // Pointer is mandatory here, abstract class cannot be bind by Value and reference will be initialized and cannot be changed
  int getUnread();
  int getFree();

  void simulate();
  DataValue read();
};

#endif