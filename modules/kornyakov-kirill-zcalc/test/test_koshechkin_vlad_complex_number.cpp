// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Create_With_Zero_Imaginary) {
    // Arrange
    double re = 2.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Assignment) {
    // Arrange
    ComplexNumber z;
    ComplexNumber c(1.0, 2.0);

    // Act
    z = c;

    // Assert
    EXPECT_DOUBLE_EQ(1.0, z.getRe());
    EXPECT_DOUBLE_EQ(2.0, z.getIm());
}

TEST(Koshechkin_Vlad_ComplexNumberTest, Summ_Zero) {
    // Arrange
    ComplexNumber z;
    ComplexNumber c;

    // Act
    ComplexNumber v = z + c;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, v.getRe());
    EXPECT_DOUBLE_EQ(0.0, v.getIm());
}

TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Copy_Number) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    ComplexNumber c(z);

    // Assert
    EXPECT_EQ(c, z);
}

TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Multiply_One) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    ComplexNumber c(1.0, 0.0);

    // Act
    ComplexNumber v = z * c;

    // Assert
    EXPECT_EQ(v, z);
}
