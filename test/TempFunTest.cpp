#include <gtest/gtest.h>
#include "TempFun.hpp"

// Простой тест для tempFun
TEST(TempFunTest, SimpleAddition) {
    EXPECT_EQ(tempFun(3, 4), 7);
    EXPECT_EQ(tempFun(-1, 1), 0);
}
