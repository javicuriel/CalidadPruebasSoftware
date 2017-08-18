#include <iostream>

class Parent{
public:
  virtual void doSomething() = 0;
};

class Child1: public Parent {
public:
  void doSomething(){
    std::cout << "Hello something child 1\n";
  }
};

class Child2: public Parent {
public:
  void doSomething(){
    std::cout << "Hello something child 2\n";
  }
};

class Child3: public Parent {
public:
  void doSomething(){
    std::cout << "Hello something child 3\n";
  }
};
