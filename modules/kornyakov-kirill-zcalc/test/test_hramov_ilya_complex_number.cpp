// Copyright 2016 Hramov Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Parity_Equal_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);

    // Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Parity_Unequal_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.1, 2.0);

    // Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Imparity_Equal_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);

    // Assert
    EXPECT_FALSE(z1 != z2);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Imparity_Unequal_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.1, 2.0);

    // Assert
    EXPECT_TRUE(z1 != z2);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Multiply_Ordinary_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    // Act
    ComplexNumber result = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(-5.0, result.getRe());
    EXPECT_DOUBLE_EQ(10.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Multiply_Zero_To_Non_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber result = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, result.getRe());
    EXPECT_DOUBLE_EQ(0.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Add_Ordinary_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    // Act
    ComplexNumber result = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(4.0, result.getRe());
    EXPECT_DOUBLE_EQ(6.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Subtract_Ordinary_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    // Act
    ComplexNumber result = z1 - z2;

    // Assert
    EXPECT_DOUBLE_EQ(-2.0, result.getRe());
    EXPECT_DOUBLE_EQ(-2.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Divide_Ordinary_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);

    // Act
    double reResult = 11.0 / 25.0;
    double imResult = 2.0 / 25.0;
    ComplexNumber result = z1 / z2;

    // Assert
    EXPECT_DOUBLE_EQ(reResult, result.getRe());
    EXPECT_DOUBLE_EQ(imResult, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Divide_Zero_To_Non_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber result = z1 / z2;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, result.getRe());
    EXPECT_DOUBLE_EQ(0.0, result.getIm());
}
