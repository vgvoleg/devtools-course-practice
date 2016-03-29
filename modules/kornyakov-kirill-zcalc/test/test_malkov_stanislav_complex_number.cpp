// Copyright 2016 Malkov Stanislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Malkov_Stanislav_ComplexNumberTest, Is_Comparsion_Correct) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Malkov_Stanislav_ComplexNumberTest, Can_Divide_By_Zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber b(0, 0);

    // Assert
    EXPECT_ANY_THROW(a / b);
}

TEST(Malkov_Stanislav_ComplexNumberTest, Can_Set_Large_Value) {
    // Arrange
    double re = DBL_MAX;

    // Act
    ComplexNumber a(re, 0);

    // Assert
    EXPECT_EQ(DBL_MAX, a.getRe());
}

TEST(Malkov_Stanislav_ComplexNumberTest, Can_Set_Small_Value) {
    // Arrange
    double im = DBL_MIN;

    // Act
    ComplexNumber a(0, im);

    // Assert
    EXPECT_EQ(DBL_MIN, a.getIm());
}

TEST(Malkov_Stanislav_ComplexNumberTest, Can_Multiply) {
    // Arrange
    double re1 = 1;
    double im1 = 1;
    double re2 = 2;
    double im2 = 2;
    ComplexNumber res(0, 4);

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);

    // Assert
    EXPECT_EQ(res, a * b);
}