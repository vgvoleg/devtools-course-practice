// Copyright 2016 Ovcharuk Oleg

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Ovcharuk_Oleg_ComplexNumberTest, Can_find_abs_value) {
    // Arrange
    ComplexNumber z(12.0, 4.0);
    // Act
    double abs_value = z.getRe()*z.getRe() + z.getIm()*z.getIm();
    // Assert
    EXPECT_DOUBLE_EQ(160.0, abs_value);
}

TEST(Ovcharuk_Oleg_ComplexNumberTest, Property_of_Addition_Conjugate) {
    // Arrange
    ComplexNumber z(4.0, 2.0);
    ComplexNumber _z(z.getRe(), z.getIm()*(-1));
    // Act
    ComplexNumber sum = z + _z;
    // Assert
    EXPECT_DOUBLE_EQ(8.0, (sum.getRe()));
}

TEST(Ovcharuk_Oleg_ComplexNumberTest, Property_of_Multiplication_Conjugate) {
    // Arrange
    ComplexNumber z(6.0, 4.0);
    ComplexNumber _z(z.getRe(), z.getIm()*(-1));
    // Act
    ComplexNumber mult = z * _z;
    // Assert
    EXPECT_DOUBLE_EQ(52.0, mult.getRe());
}

TEST(Ovcharuk_Oleg_ComplexNumberTest, Property_of_Commutativity) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(5.0, 5.0);
    // Act
    ComplexNumber sum1 = z1 + z2;
    ComplexNumber sum2 = z2 + z1;
    // Assert
    EXPECT_DOUBLE_EQ(sum1.getRe(), sum2.getRe());
    EXPECT_DOUBLE_EQ(sum1.getIm(), sum2.getIm());
}

TEST(Ovcharuk_Oleg_ComplexNumberTest, Property_of_Distributivity) {
    // Arrange
    ComplexNumber z1(4.0, 4.0);
    ComplexNumber z2(1.0, 0.0);
    ComplexNumber z3(23.0, 12.0);
    // Act
    ComplexNumber res1 = z2 + z3;
    res1 = z1 * res1;
    ComplexNumber res2 = z1*z2 + z1* z3;
    // Assert
    EXPECT_DOUBLE_EQ(res1.getRe(), res2.getRe());
    EXPECT_DOUBLE_EQ(res1.getIm(), res2.getIm());
}
