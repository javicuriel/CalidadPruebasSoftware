#include "gtest/gtest.h"
#include "../../PrimosCirculares/circularPrime.h"

TEST(TestCaseName,TestNameUno){
  int array[19] = {2, 3, 5, 7, 11, 13, 17, 37, 79, 113, 197, 199, 337, 1193, 3779, 11939, 19937, 193939, 199933};
  int i = 0;
  while(i < 19){
    ASSERT_TRUE(girar(array[i]));
    i++;
  }
}
