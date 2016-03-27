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
