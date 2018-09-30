
#ifndef MYHEADER_HPP
#define MYHEADER_HPP

#include <string>
#include "./Component.hpp"
#include "./Readable.hpp"

class Cpu : public Component, public Readable {
private:
  std::string label;
  int cores;
  int frequency;
public:
  std::string program_path;
  void simulate();
};

#endif