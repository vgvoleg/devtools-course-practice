// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tishkin_Kostya_ComplexNumberTest, Can_create_twin) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber c(0.0, 0.0);

    // Act
    c = c + a;

    // Assert
    EXPECT_EQ(a,c);
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
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(5.0, 2.0);

    // Act
	double c = a.getRe();
	double d = b.getIm();

    // Assert
    EXPECT_EQ(c, d);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_setRE) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(2.0, 5.0);

    // Act
	a.setRe(3.0);

    // Assert
    EXPECT_NE(a, b);
}
TEST(Tishkin_Kostya_ComplexNumberTest, Can_setIM) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(2.0, 5.0);

    // Act
	a.setIm(3.0);

    // Assert
    EXPECT_NE(a,b);
}
