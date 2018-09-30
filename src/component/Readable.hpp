#ifndef H_READABLE
#define H_READABLE

#include "platform/type.hpp"

class Readable {
protected:
  virtual DataValue read() = 0;
};

#endif