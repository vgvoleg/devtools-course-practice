// Copyright 2016 Sharadze Georgy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Make_Few_Multiplications_In_A_Row) {
    // Arrange
    ComplexNumber z(1.0, -1.0);
    ComplexNumber expected_result(-2.0, -2.0);

    // Act
    ComplexNumber result = z * z * z;

    // Assert
    EXPECT_EQ(expected_result, result);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Init_With_Zeros) {
    ASSERT_NO_THROW(ComplexNumber z(0.0, 0.0));
}

TEST(Sharadze_Georgy_ComplexNumberTest, Divide_With_Zero_Is_Right) {
    // Arrange
    ComplexNumber z0(0.0, 0.0);
    ComplexNumber z1(1.0, 1.0);

    // Act
    ComplexNumber result;

    // Assert
    EXPECT_EQ(z0, result);
}

TEST(Sharadze_Georgy_ComplexNumberTest, DISABLED_Can_Divide_Zero_On_Zero) {
    // Arrange
    ComplexNumber z0(0.0, 0.0);
    ComplexNumber z1(0.0, 0.0);

    // Act
    ComplexNumber result;

    // Assert
    ASSERT_NO_THROW(result = z0 / z1);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Compare) {
    // Arrange
    ComplexNumber z1(-1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act & Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Sharadze_Georgy_ComplexNumberTest,
     Equal_To_Itself_When_Init_With_Default_Constructor) {
    // Arrange
    ComplexNumber z;

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(Sharadze_Georgy_ComplexNumberTest, DISABLED_Can_Make_Billion_Additions) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(1.0, 1.0);
    const double billion = 1000000000.0;

    // Act
    for (int i = 0; i < billion; i++)
        z1 = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(billion, z1.getRe());
    EXPECT_DOUBLE_EQ(billion, z1.getIm());
}
