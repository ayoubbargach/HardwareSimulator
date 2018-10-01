#ifndef READABLE_HPP
#define READABLE_HPP

#include "platform/type.hpp"

class Readable {
protected:
  virtual DataValue read() = 0;
};

#endif