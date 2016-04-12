// Copyright 2016 Lebedev Ilya

#include <gtest/gtest.h>

#include "include/function.h"
#include "include/random_search.h"

TEST(Lebedev_Ilya_ComplexNumberTest, Can_Create) {
    // Arrange
    RandomSearch* a;

    // Act
    a = new RandomSearch(RastriginFunction);

    // Assert
    EXPECT_FALSE (a == 0);

}

TEST(Lebedev_Ilya_ComplexNumberTest, Can_Find_Global_Minimum) {
    // Arrange
    RandomSearch a(RastriginFunction, 1, 10000);
    double value = 0;
    double globalMimum = 0;
    double x = 0;
    double eps = 0.01;

    // Act    
    value = a.FindMinimum(&x);

    // Assert
    EXPECT_NEAR(globalMimum, value, eps);
}