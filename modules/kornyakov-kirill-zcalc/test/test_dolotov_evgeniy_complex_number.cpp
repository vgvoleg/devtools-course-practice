// Copyright 2016 Dolotov Evgeniy

#include <gtest/gtest.h>

#include "include/complex_number.h"

const double epsilon = 1e-6;

TEST(Dolotov_Evgeniy_ComplexNumberTest, Imaginary_Unit_Square_Is_Minus_One) {
    // Arrange
    ComplexNumber z(0.0, -1.0);

    // Act
    ComplexNumber multiplied = z * z;

    // Assert
    EXPECT_NEAR(multiplied.getRe(), -1.0, epsilon);
    EXPECT_NEAR(multiplied.getIm(), 0.0, epsilon);
}

TEST(Dolotov_Evgeniy_ComplexNumberTest, Multiplied_By_Zero_Is_Zero) {
    // Arrange
    ComplexNumber z(23.0, -42.0);
    ComplexNumber zero(0.0, 0.0);

    // Act
    ComplexNumber multiplied = z * zero;

    // Assert
    EXPECT_DOUBLE_EQ(multiplied.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(multiplied.getIm(), 0.0);
}

TEST(Dolotov_Evgeniy_ComplexNumberTest, Devided_By_Itself_Is_Equal_To_One) {
    // Arrange
    ComplexNumber z(34.0, 29.0);

    // Act
    ComplexNumber devided = z / z;

    // Assert
    EXPECT_NEAR(devided.getRe(), 1.0, epsilon);
    EXPECT_NEAR(devided.getIm(), 0.0, epsilon);
}

TEST(Dolotov_Evgeniy_ComplexNumberTest, Addition_Is_Commutative) {
    // Arrange
    ComplexNumber z1(22.0, -9.0);
    ComplexNumber z2(-56.0, 3.0);

    // Act
    ComplexNumber z1Addz2 = z1 + z2;
    ComplexNumber z2Addz1 = z2 + z1;

    // Act & Assert
    EXPECT_NEAR(z1Addz2.getRe(), z2Addz1.getRe(), epsilon);
    EXPECT_NEAR(z1Addz2.getIm(), z2Addz1.getIm(), epsilon);
}

TEST(Dolotov_Evgeniy_ComplexNumberTest, Substract_With_Conjugate_Is_Imaginary) {
    // Arrange
    double re = 36.0;
    double im = -29.0;

    ComplexNumber z(re, im);
    ComplexNumber conjugate(re, -im);

    // Act
    ComplexNumber substract = z - conjugate;

    // Assert
    EXPECT_NEAR(substract.getRe(), 0.0, epsilon);
    EXPECT_NEAR(substract.getIm(), 2*im, epsilon);
}

