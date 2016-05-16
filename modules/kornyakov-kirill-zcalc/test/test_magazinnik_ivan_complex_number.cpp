// Copyright 2016 Magazinnik Ivan

#include <gtest/gtest.h>
#include <cmath>
#include <limits>

#include "include/complex_number.h"

const double eps = std::numeric_limits<double>::epsilon();

TEST(Magazinnik_Ivan_ComplexNumberTest, Can_Multiply_Two_Im_Number) {
    // Arrange
    double re = 0.0;
    double im = 2.0;
    double im1 = 2.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re, im1);
    ComplexNumber mult = z1 * z;
    // Assert
    double expected_re =  im * im1 * (-1.0);
    ASSERT_DOUBLE_EQ(expected_re, mult.getRe());
    ASSERT_DOUBLE_EQ(0.0, mult.getIm());
}

TEST(Magazinnik_Ivan_ComplexNumberTest, Can_Divide_By_Epsilon) {
    // Test dividing on smallest double number
    // Arrange
    double re = 0.0;
    double im = eps;
    double re1 = -1.0;
    double im1 = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);
    ComplexNumber div = z1 / z;

    // Assert
    double expected_im = 1.0 / eps;
    ASSERT_DOUBLE_EQ(re, div.getRe());
    ASSERT_DOUBLE_EQ(expected_im, div.getIm());
}

TEST(Magazinnik_Ivan_ComplexNumberTest, Can_Multiply_By_Epsilon) {
    // Arrange
    double re = eps;
    double im = eps;
    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);
    ComplexNumber mult = z1 * z;

    // Assert
    double expected_re = eps;
    double expected_im = 3 * eps;
    ASSERT_DOUBLE_EQ(expected_re, mult.getRe());
    ASSERT_DOUBLE_EQ(expected_im, mult.getIm());
}

TEST(Magazinnik_Ivan_ComplexNumberTest, Adding_Two_Epsilon_Number) {
    // Arrange
    double re = 1.0 + eps;
    double im = 1.0 + eps;
    double re1 = eps;
    double im1 = 1.0 + eps;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);
    ComplexNumber add = z1 + z;

    // Assert
    double expected_re = 1.0 + 2 * eps;
    double expected_im = 2.0 + 2 * eps;
    ASSERT_DOUBLE_EQ(expected_re, add.getRe());
    ASSERT_DOUBLE_EQ(expected_im, add.getIm());
}

TEST(Magazinnik_Ivan_ComplexNumberTest, Test_Create_Transcendental_Number) {
    // Arrange
    double re = M_E;
    double im = M_PI;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_DOUBLE_EQ(re, z.getRe());
    ASSERT_DOUBLE_EQ(im, z.getIm());
}
