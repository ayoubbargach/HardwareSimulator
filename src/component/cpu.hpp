/**
    CS-11 Asn 2
    cpu.cpp
    Purpose: CPU specs.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef CPU_HPP
#define CPU_HPP

#include <string>
#include <list>
#include "Component.hpp"
#include "Readable.hpp"
#include "io/config.hpp"


class Cpu : public Component, public Readable {
private:
  Label l;
  int coreFlag;
  int cores;
  int frequency;
  std::list<double> cpuRegister;
public:
  std::string programPath;
  Cpu(Config c);
  void simulate();
  DataValue read();
};

#endif