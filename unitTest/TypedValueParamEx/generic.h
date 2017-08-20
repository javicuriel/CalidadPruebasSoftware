#include "gtest/gtest.h"
#include "hierarchie.h"

template<class T>
class Generic : public ::testing::Test{
public:
  // Parent * parent;
  // void SetUp(){
  //   parent = new T;
  // }
  // void TearDown(){
  //   delete parent;
  // }
};


typedef ::testing::Types <::testing::TestWithParam<int>, ::testing::TestWithParam<char>> Implementations;
TYPED_TEST_CASE(Generic,Implementations);
TYPED_TEST(Generic,Implementations){
  printValues(GetParam());
  // this->parent->doSomething();
}





typedef ::testing::Types<Child1,Child2,Child3> implementations;
TYPED_TEST_CASE(Fixture,implementations);

TYPED_TEST(Fixture,implementations){
  this->parent->doSomething();
}
