// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sirotkin_Nikita_ComplexNumberTest, Im_division_by_Im_is_real) {
    // Arrange
    double re = 0;
    double im_a = 2;
    double im_b = 1;

    // Act
    ComplexNumber a(re, im_a);
    ComplexNumber b(re, im_b);
    ComplexNumber res = a / b;

    // Assert
    double re_expect = 2;
    double im_expect = 0;
    ASSERT_DOUBLE_EQ(re_expect, res.getRe());
    ASSERT_DOUBLE_EQ(im_expect, res.getIm());
}

TEST(Sirotkin_Nikita_ComplexNumberTest, Re_mult_on_Im_is_Im) {
    // Arrange
    double re_a = 2;
    double im_a = 0;
    double re_b = 0;
    double im_b = 5;

    // Act
    ComplexNumber a(re_a, im_a);
    ComplexNumber b(re_b, im_b);
    ComplexNumber res = a * b;

    // Assert
    double re_expect = 0;
    double im_expect = 10;
    ASSERT_DOUBLE_EQ(re_expect, res.getRe());
    ASSERT_DOUBLE_EQ(im_expect, res.getIm());
}

TEST(Sirotkin_Nikita_ComplexNumberTest, Z_add_null_is_Z) {
    // Arrange
    double re = 2;
    double im = 5;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber b(0, 0);
    ComplexNumber res = a + b;

    // Assert
    double re_expect = 2;
    double im_expect = 5;
    ASSERT_DOUBLE_EQ(re_expect, res.getRe());
    ASSERT_DOUBLE_EQ(im_expect, res.getIm());
}

TEST(Sirotkin_Nikita_ComplexNumberTest, Can_sum_many_times) {
    // Arrange
    double re = 2;
    double im = 3;
    int count = 1000;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber res(0,0);
    for (int i = 0; i < count; ++i)
        res = res + a;

    // Assert
    double re_expect = 2*count;
    double im_expect = 3*count;
    ASSERT_DOUBLE_EQ(re_expect, res.getRe());
    ASSERT_DOUBLE_EQ(im_expect, res.getIm());
}

TEST(Sirotkin_Nikita_ComplexNumberTest, not_equal_number_is_not_equal) {
    // Arrange
    double re_a = 2;
    double im_a = 3;
    double re_b = 3;
    double im_b = 3;
    ComplexNumber a(re_a, im_a);
    ComplexNumber b(re_b, im_b);

    // Assert
    EXPECT_FALSE(a == b);
}
