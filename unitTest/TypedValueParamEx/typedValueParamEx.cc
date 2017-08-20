#include "gtest/gtest.h"

using ::testing::Range;
using ::testing::Values;
using ::testing::ValuesIn;
using ::testing::Bool;
using ::testing::Combine;

template<class T>
class Generic : public ::testing::Test{
public:
  T value_;
};

TYPED_TEST_CASE_P(Generic);

TYPED_TEST_P(Generic, TestOne) {
}

TYPED_TEST_P(Generic, TestTwo) {
}

REGISTER_TYPED_TEST_CASE_P(Generic,TestOne, TestTwo);

typedef testing::Types<int, char> MyTypes;

INSTANTIATE_TYPED_TEST_CASE_P(Todos,Generic,MyTypes);
