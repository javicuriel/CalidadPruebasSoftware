#include "gtest/gtest.h"
#include <iostream>
#include "valueParameterized.h"

using ::testing::Range;
using ::testing::Values;
using ::testing::ValuesIn;
using ::testing::Bool;
using ::testing::Combine;


class Fixture : public ::testing::TestWithParam<int>{};
class Chars : public ::testing::TestWithParam<char>{};
class Bools : public ::testing::TestWithParam<bool>{};
class Combinations : public ::testing::TestWithParam<::testing::tuple<int,int>>{
public:
  int x = ::testing::get<0>(GetParam());
  int y = ::testing::get<1>(GetParam());

};

TEST_P(Fixture,testA){
  printValue(GetParam());
}

TEST_P(Chars,testB){
  printValue(GetParam());
}

TEST_P(Bools,testC){
  printValue(GetParam());
}

TEST_P(Combinations,testD){
  printValues(x,y);
}

char a[] = {'a','e','i','o','u'};

INSTANTIATE_TEST_CASE_P(ints, Fixture, Values(1,2,3,4,5));

INSTANTIATE_TEST_CASE_P(chars, Chars, ValuesIn(a));

INSTANTIATE_TEST_CASE_P(bools, Bools, Bool());

INSTANTIATE_TEST_CASE_P(combs, Combinations, Combine(Range(1,10,1),Range(1,10,1)));
