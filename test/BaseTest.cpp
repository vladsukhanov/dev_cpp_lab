#include <gtest/gtest.h>
#include "Base.hpp"

// Тест конструктора
TEST(BaseTest, Constructor) {
    Base obj(10, 20);
    EXPECT_EQ(obj.getX(), 10);
    EXPECT_EQ(obj.getY(), 20);
}

// Тест геттеров и сеттеров
TEST(BaseTest, GettersSetters) {
    Base obj(5, 15);

    obj.setX(25);
    EXPECT_EQ(obj.getX(), 25);

    obj.setY(30);
    EXPECT_EQ(obj.getY(), 30);
}
