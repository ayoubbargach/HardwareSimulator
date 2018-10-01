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
#include "Component.hpp"
#include "Readable.hpp"
#include "io/config.hpp"


class Memory : public Component, public Readable {
private:
  Label l;
  int size;
  int access;
  std::string source;
  std::list<DataValue> buffer; // FIFO structure limited to 32 cases
public:
  Memory(Config c);
  void simulate();
  DataValue read();
};

#endif