// Copyright 2016 Belyaeva Daria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Belyaeva_Daria_ComplexNumberTest, Sum_With_Conjugate) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(z.getRe(), 6.0);
}

TEST(Belyaeva_Daria_ComplexNumberTest, Can_Do_Some_Operation) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(1.0, 2.0);
    ComplexNumber result(-24.0, 39.0);

    // Act
    ComplexNumber z = ((z1 + z2) * z1) - z2;

    // Assert
    EXPECT_EQ(z, result);
}

TEST(Belyaeva_Daria_ComplexNumberTest, Can_Do_Operation_With_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber result = (z1 * z2) + (z1 / z2);

    // Assert
    EXPECT_EQ(z1, result);
}

TEST(Belyaeva_Daria_ComplexNumberTest, Multiplication_With_Conjuate) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    double abs_z1 = sqrt(pow(z1.getRe(), 2) + pow (z1.getIm(), 2));
    ComplexNumber result_of_mult = z1 * z2;
    ComplexNumber result_abs(pow (abs_z1, 2), 0.0);

    // Assert
    EXPECT_EQ(result_of_mult, result_abs);
}

TEST(Belyaeva_Daria_ComplexNumberTest, Calculation_Im_With_Conjugate) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(z.getIm(), 10.0);
}