#ifndef H_COMPONENT
#define H_COMPONENT


class Component {
protected:
  int priority;
  virtual void simulate() = 0;
};

#endif