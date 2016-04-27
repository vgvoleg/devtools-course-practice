// Copyright 2016 Malkov Stanislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Malkov_Stanislav_ComplexNumberTest, Is_Sum_Correct) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber b(2.0, 2.0);
    ComplexNumber expected_result(3.0, 3.0);

    // Act
    ComplexNumber sum = a + b;

    // Assert
    EXPECT_EQ(sum, expected_result);
}

TEST(Malkov_Stanislav_ComplexNumberTest, Is_Divide_Correct) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber b(2.0, 2.0);
    ComplexNumber expected_result(0.5, 0);

    // Act
    ComplexNumber divide = a / b;

    // Assert
    EXPECT_EQ(divide, expected_result);
}

TEST(Malkov_Stanislav_ComplexNumberTest, Is_Multiply_Correct) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber b(2.0, 2.0);
    ComplexNumber expected_result(0, 4.0);

    // Act
    ComplexNumber mul = a * b;

    // Assert
    EXPECT_EQ(mul, expected_result);
}

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

TEST(Malkov_Stanislav_ComplexNumberTest, Can_Get_Correct_Im_And_Re) {
    // Arrange
    double re = 10;
    double im = 20;
    ComplexNumber a(re, im);

    // Act
    ComplexNumber b(a.getRe(), a.getIm());

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Malkov_Stanislav_ComplexNumberTest, Cant_Divide_By_Zero) {
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
