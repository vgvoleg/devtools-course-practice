// Copyright 2016 Ryabinin Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Add_Complex_Number) {
// Arrange
ComplexNumber x(4.0, 3.0);
ComplexNumber y(5.0, 2.0);

// Act
ComplexNumber z = x + y;

// Assert
ComplexNumber add_xy(9.0, 5.0);
EXPECT_EQ(z, add_xy);
}

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Subtraction_Complex_Number) {
// Arrange
ComplexNumber x(20.0, 3.0);
ComplexNumber y(5.0, 6.0);

// Act
ComplexNumber z = x - y;

// Assert
ComplexNumber sub_xy(15.0, -3.0);
EXPECT_EQ(z, sub_xy);
}

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Multi_Null_Complex_Number) {
// Arrange
ComplexNumber x(1.0, 3.0);
ComplexNumber y(0.0, 0.0);

// Act
ComplexNumber z = x * y;

// Assert
EXPECT_EQ(z, y);
}

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Share_NULL_Complex_Number) {
// Arrange
ComplexNumber x(0.0, 0.0);
ComplexNumber y(1.0, 3.0);

// Act
ComplexNumber z = x / y;

// Assert
EXPECT_EQ(x, z);
}

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Folded_Opposie_Complex_Number) {
// Arrange
ComplexNumber x(5.0, -3.0);
ComplexNumber y(-5.0, 3.0);

// Act
ComplexNumber z = x + y;

// Assert
ComplexNumber folded_z(0.0, 0.0);
EXPECT_EQ(folded_z, z);
}

TEST(Ryabinin_Kirill_ComplexNumberTest, Can_Compare_Complex_Number) {
// Arrange
ComplexNumber x(5.0, 7.0);
ComplexNumber y(-5.0, 7.0);

// Act
bool compare_z = x == y;

// Assert
EXPECT_FALSE(compare_z);
}
