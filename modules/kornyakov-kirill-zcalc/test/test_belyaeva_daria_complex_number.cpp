// Copyright 2016 Belyaeva Daria

#include <math.h>

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Belyaeva_Daria_ComplexNumberTest, Sum_With_Conjugate_Is_Twice_Real) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(z.getRe(), 6.0);
}

TEST(Belyaeva_Daria_ComplexNumberTest,
            Can_Do_Some_Operations_In_One_Assignment) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber result = ((z1 + z2) * z1) - z2;

    // Assert
    ComplexNumber expected_z(-24.0, 39.0);
    EXPECT_EQ(result, expected_z);
}

TEST(Belyaeva_Daria_ComplexNumberTest, Can_Do_Operations_With_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber result = (z1 * z2) + (z1 / z2);

    // Assert
    EXPECT_EQ(z1, result);
}

TEST(Belyaeva_Daria_ComplexNumberTest,
            Multiplication_With_Conjuate_Is_Square_Of_Absolute_Value) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    double abs_z1 = sqrt(pow(z1.getRe(), 2) + pow(z1.getIm(), 2));
    ComplexNumber result_of_mult = z1 * z2;
    ComplexNumber result_abs(pow(abs_z1, 2), 0.0);

    // Assert
    EXPECT_EQ(result_of_mult, result_abs);
}

TEST(Belyaeva_Daria_ComplexNumberTest,
            Im_Of_Subtraction_With_Conjugate_Is_Twice_Im) {
    // Arrange
    ComplexNumber z1(3.0, 5.0);
    ComplexNumber z2(3.0, -5.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(z.getIm(), 10.0);
}
