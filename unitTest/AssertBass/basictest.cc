#include "gtest/gtest.h"
#include <vector>

TEST(TestCaseName, TestNameUno)
{
    ASSERT_TRUE(true);
    ASSERT_FALSE(false);
    SUCCEED();
    FAIL();
    ADD_FAILURE();
}

TEST(TestCaseName, TestNameDos)
{
    ASSERT_EQ(true, true);
    ASSERT_NE(1, 2);
    ASSERT_LT(4, 2);
    ASSERT_LE(2, 2);
    ASSERT_GT(3, 2);
    ASSERT_GE(3, 3);
}

TEST(TestCaseName, TestNameTres)
{
    std::vector<int> v;
    ASSERT_STREQ("hola", "hola");
    ASSERT_STRNE("hola", "adios");
    ASSERT_STRCASEEQ("HOLA", "hola");
    ASSERT_STRCASENE("HOLa", "ADios");
    ASSERT_THROW(v.at(3), std::out_of_range);
}

TEST(TestCaseName, TestNameCuatro)
{
    std::vector<int> v;
    float one = .002, two = .0019;
    double oneD = .0002, twoD = .00019;
    ASSERT_ANY_THROW(v.at(3));
    ASSERT_NO_THROW(v.at(3));
    ASSERT_FLOAT_EQ(one, two);
    ASSERT_DOUBLE_EQ(oneD, twoD);
    ASSERT_NEAR(one, two, .0001);
}
