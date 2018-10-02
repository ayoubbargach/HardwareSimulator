#ifndef COMPONENT_HPP
#define COMPONENT_HPP


class Component {
public:
  int priority;
  virtual void simulate() = 0;
};

#endif