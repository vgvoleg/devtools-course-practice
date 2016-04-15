// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tishkin_Kostya_ComplexNumberTest, Can_create_twin) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber c(0.0, 0.0);

    // Act
    ComplexNumber d = c + a;

    // Assert
    EXPECT_EQ(d, a);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_Copy_Num) {
    // Arrange
    ComplexNumber z(2.0, 5.0);

    // Act
    ComplexNumber c = z;

    // Assert
    EXPECT_EQ(c, z);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_getRE) {
    // Arrange
    double d = 2.0;
    // Act
    ComplexNumber a(2.0, 5.0);

    // Assert
    EXPECT_EQ(a.getRe(), d);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_getIM) {
    // Arrange
    double c = 5.0;

    // Act
    ComplexNumber a(2.0, 5.0);

    // Assert
    EXPECT_EQ(a.getIm(), c);
}
TEST(Tishkin_Kostya_ComplexNumberTest, Can_setIM) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(2.0, 5.0);

    // Act
    a.setIm(3.0);

    // Assert
    EXPECT_NE(a, b);
}
