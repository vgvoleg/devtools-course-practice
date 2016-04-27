// Copyright 2016 Lebedev Ilya

#include <gtest/gtest.h>

#include <string>

#include "include/function.h"
#include "include/random_search.h"

TEST(RandomSearch, Can_Create) {
    // Arrange
    RandomSearch* a;

    // Act
    a = new RandomSearch(RastriginFunction);

    // Assert
    EXPECT_NE(nullptr, a);
}

TEST(RandomSearch, Throws_When_Dimension_Is_Negative) {
    // Arrange
    int bad_dimension = -1;

    // Act & Assert
    EXPECT_THROW(RandomSearch(RastriginFunction, bad_dimension), std::string);
}

TEST(RandomSearch, Throws_When_Iteration_Count_Is_Negative) {
    // Arrange
    int bad_count = -1;

    // Act & Assert
    EXPECT_THROW(RandomSearch(RastriginFunction, 1, bad_count), std::string);
}

TEST(RandomSearch, Throws_When_Set_Negative_Dimension) {
    // Arrange
    RandomSearch a(RastriginFunction, 1, 10000);
    int bad_dimension = -1;

    // Act & Assert
    EXPECT_THROW(a.SetDimension(bad_dimension), std::string);
}

TEST(RandomSearch, Can_Set_And_Get_Dimension) {
    // Arrange
    RandomSearch a(RastriginFunction, 1, 10000);
    int new_dimension = 2;

    // Act
    a.SetDimension(new_dimension);

    // Assert
    EXPECT_EQ(new_dimension, a.GetDimension());
}

TEST(RandomSearch, Can_Set_And_Get_Iteration_Count) {
    // Arrange
    RandomSearch a(RastriginFunction, 1, 10000);
    int new_count = 10;

    // Act
    a.SetIterationCount(new_count);

    // Assert
    EXPECT_EQ(new_count, a.GetIterationCount());
}

TEST(RandomSearch, Can_Find_Global_Minimum) {
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
