// Copyright 2016 Orlov Georgy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Orlov_Georgy_ComplexNumberTest, Squared_Img_Number_Equal_Minus_One) {
    // Arrange
    const ComplexNumber z1(0, 1);

    // Act & Assert
    const ComplexNumber expected_z(-1, 0);
    EXPECT_EQ(expected_z, z1 * z1);
}

TEST(Orlov_Georgy_ComplexNumberTest, Addition_Is_Commutative) {
    // Arrange
    const ComplexNumber z1(10, 15);
    const ComplexNumber z2(6, 12);

    // Act & Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Orlov_Georgy_ComplexNumberTest, Multiplication_Is_Commutative) {
    // Arrange
    const ComplexNumber z1(10, 15);
    const ComplexNumber z2(6, 12);

    // Act & Assert
    EXPECT_EQ(z1 * z2, z2 * z1);
}

TEST(Orlov_Georgy_ComplexNumberTest, Expr_With_All_Ops_Correct_Result) {
    // Arrange
    const ComplexNumber z1(2, 4);
    const ComplexNumber z2(8, 12);
    const ComplexNumber z3(-6, 5);
    const ComplexNumber z4(8, 12);
    const ComplexNumber z5(1, -1);

    // Act & Assert
    const ComplexNumber expected_z(-36, 51);
    EXPECT_EQ(z1 * z2 + z3 - z4 / z5, expected_z);
}

TEST(Orlov_Georgy_ComplexNumberTest, Distributivity_Is_Performed) {
    // Arrange
    const ComplexNumber z1(-2, 5);
    const ComplexNumber z2(6, 4);
    const ComplexNumber z3(8, 1);

    // Act & Assert
    EXPECT_EQ(z1 * (z2 + z3), (z1 * z2) + (z1 * z3));
}
