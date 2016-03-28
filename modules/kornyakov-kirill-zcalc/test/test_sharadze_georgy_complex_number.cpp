// Copyright 2016 Sharadze Georgy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Make_Few_Multiplications_In_A_Row) {
    // Arrange
    ComplexNumber z(1.0, -1.0);
    ComplexNumber expected_result(-2.0, -2.0); // (1 - i)(1 - i)(1 - i) = -2 - 2i

    // Act
    ComplexNumber result = z * z * z;

    // Assert
    EXPECT_EQ(expected_result, result);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Divide_With_Zero) {
    // Arrange
    ComplexNumber z0(0.0, 0.0);
    ComplexNumber z1(2.0, 8.0);

    // Act
    ComplexNumber z = z0 / z1;

    // Assert
    EXPECT_EQ(z0, z);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Compare) {
    // Arrange
    ComplexNumber z1(-1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act

    // Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Equal_To_Itself) {
    // Arrange
    ComplexNumber z;

    // Act

    // Assert
    EXPECT_TRUE(z == z);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Make_Billion_Additions) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(1.0, 1.0);

    // Act
    for (int i = 0; i < 1000000000; i++)
        z1 = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(1000000000.0, z1.getRe());
    EXPECT_DOUBLE_EQ(1000000000.0, z1.getIm());
}
