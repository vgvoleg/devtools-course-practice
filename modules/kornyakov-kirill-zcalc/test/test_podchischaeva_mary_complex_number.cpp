// Copyright 2016 Podchischaeva Mary


#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Podchischaeva_Mary_ComplexNumberTest, Can_Multiply_With_Dual) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    ComplexNumber z(re, im);
    ComplexNumber dualz(re, -1.0 * im);

    // Act
    double sqrmod = re * re + im * im;
    ComplexNumber mult = z * dualz;

    // Assert
    ASSERT_DOUBLE_EQ(sqrmod, mult.getRe());
    ASSERT_DOUBLE_EQ(0.0, mult.getIm());
}

TEST(Podchischaeva_Mary_ComplexNumberTest, Can_Add_With_Dual) {
    // Arrange
    double re = 3.0;
    double im = 10.4;

    ComplexNumber z(re, im);
    ComplexNumber dualz(re, -1.0 * im);

    // Act
    ComplexNumber add = z + dualz;

    // Assert
    ASSERT_DOUBLE_EQ(2.0 * re, add.getRe());
    ASSERT_DOUBLE_EQ(0.0, add.getIm());
}

TEST(Podchischaeva_Mary_ComplexNumberTest, Can_Add_Hundred_Numbers) {
    // Arrange
    double totalRe = 1.0;
    double totalIm = 1.0;
    ComplexNumber totalz(totalRe, totalIm);
    ComplexNumber n(0.0, 0.0);

    // Act
    for (int i = 1; i < 100; ++i) {
        totalRe += 3.0 * i;
        totalIm += 2.0 * i;
        n.setRe(3.0 * i);
        n.setIm(2.0 * i);
        totalz = totalz + n;
    }

    // Assert
    ASSERT_DOUBLE_EQ(totalRe, totalz.getRe());
    ASSERT_DOUBLE_EQ(totalIm, totalz.getIm());
}

TEST(Podchischaeva_Mary_ComplexNumberTest, Module_Of_Div_Is_Div_Of_Modules) {
    // Arrange
    double re1 = 2.10;
    double re2 = 9.6;
    double im1 = 8.0;
    double im2 = 10.1;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber div = z1 / z2;
    double mod1 = sqrt(re1 * re1 + im1 * im1);
    double mod2 = sqrt(re2 * re2 + im2 * im2);
    double newre = div.getRe();
    double newim = div.getIm();
    double newmod = sqrt(newre * newre + newim * newim);

    // Assert
    ASSERT_DOUBLE_EQ(mod1 / mod2, newmod);
}

TEST(Podchischaeva_Mary_ComplexNumberTest, Module_Of_Mult_Is_Mult_Of_Modules) {
    // Arrange
    double re1 = 1.100500;
    double re2 = 7.3;
    double im1 = 2.0;
    double im2 = 3.4;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber mult = z1 * z2;
    double mod1 = sqrt(re1 * re1 + im1 * im1);
    double mod2 = sqrt(re2 * re2 + im2 * im2);
    double newre = mult.getRe();
    double newim = mult.getIm();
    double newmod = sqrt(newre * newre + newim * newim);

    // Assert
    ASSERT_DOUBLE_EQ(mod1 * mod2, newmod);
}

