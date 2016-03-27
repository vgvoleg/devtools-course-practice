// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kursakov_Evgeny_ComplexNumberTest, Multiplication_Of_Complex_Number_And_Conjugate_Is_Positive_Real) {
    // Arrange
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(2.0, -3.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    ComplexNumber expected_z(13.0, 0);
    EXPECT_EQ(z3, expected_z);
}

TEST(Kursakov_Evgeny_ComplexNumberTest, Multiplication_Is_Commutative) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 7.0);

    // Act
    ComplexNumber z3 = z1 * z2;
    ComplexNumber z4 = z2 * z1;

    // Assert
    EXPECT_EQ(z3, z4);
}

TEST(Kursakov_Evgeny_ComplexNumberTest, Add_Is_Commutative) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 7.0);

    // Act
    ComplexNumber z3 = z1 + z2;
    ComplexNumber z4 = z2 + z1;

    // Assert
    EXPECT_EQ(z3, z4);
}
