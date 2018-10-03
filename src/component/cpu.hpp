/**
    CS-11 Asn 2
    cpu.cpp
    Purpose: CPU specs.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef CPU_HPP
#define CPU_HPP

#include <iostream>
#include <string>
#include <list>
#include "component.hpp"
#include "readable.hpp"
#include "../io/config.hpp"
#include "../program/program.hpp"


class Cpu : public Component, public Readable {
private:
  bool verbose;
  Label l;
  int coreFlag;
  int cores;
  int frequency;
  std::list<DataValue> * cpuRegister; // FIFO register with unlimited capacity

public:
  std::string programPath;
  Program p;
  Cpu(Config & c, bool verbose);
  void simulate();
  DataValue read();
};

#endif