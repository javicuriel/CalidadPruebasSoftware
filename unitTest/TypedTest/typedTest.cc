#include "gtest/gtest.h"
#include "hierarchie.h"

template<class T>
class Fixture : public ::testing::Test{
public:
  Parent * parent;
  void SetUp(){
    parent = new T;
  }
  void TearDown(){
    delete parent;
  }
};

typedef ::testing::Types<Child1,Child2,Child3> implementations;
TYPED_TEST_CASE(Fixture,implementations);

TYPED_TEST(Fixture,implementations){
  this->parent->doSomething();
}
