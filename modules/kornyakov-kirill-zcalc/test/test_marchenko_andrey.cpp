// Copyright 2016 Marchenko Andrey

#include <gtest/gtest.h>
#include "cmath"
#include "include/complex_number.h"

TEST(Marchenko_Andrey_ComplexNumberTest, Can_Create_Int_Char_Variable) {
    // Arrange
    int re = 0;
    char im = 0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Marchenko_Andrey_ComplexNumberTest, Can_Add_Big_Complex_Numbers) {
    // Arrange
    double a = sqrt(1000);
    double b = sqrt(2000);
    ComplexNumber z1(a, b);
    ComplexNumber z2(2 * a, 2 * b);

    // Act
    ComplexNumber result = z1 + z2;
    ComplexNumber expected_result(3 * a, 3 * b);

    // Assert
    EXPECT_EQ(result, expected_result);
}

TEST(Marchenko_Andrey_ComplexNumberTest, Check_The_Triangle_Inequality) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);

    // Act
    ComplexNumber result_sum = z1 + z2;
    double abs_of_sum = hypot(result_sum.getRe(), result_sum.getIm());
    double sum_of_abs = hypot(z1.getRe(), z1.getIm()) +
        hypot(z2.getRe(), z2.getIm());

    // Assert
    EXPECT_LE(abs_of_sum, sum_of_abs);
}

TEST(Marchenko_Andrey_ComplexNumberTest, Multiplication_Is_Distibutive) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);
    ComplexNumber z3(5, 6);

    // Act
    ComplexNumber first_result = (z1 + z2)*z3;
    ComplexNumber second_result = z1*z3+z2*z3;

    // Assert
    EXPECT_EQ(first_result, second_result);
}

TEST(Marchenko_Andrey_ComplexNumberTest, Summation_Is_Commutative) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(3, 4);

    // Act
    ComplexNumber first_result = z1 + z2;
    ComplexNumber second_result = z2 + z1;

    // Assert
    EXPECT_EQ(first_result, second_result);
}






