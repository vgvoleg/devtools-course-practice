// Copyright 2016 Muminov Ruslan

#include <math.h>

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

double calc_abs_value(ComplexNumber c) {
    return sqrt(c.getRe()*c.getRe() + c.getIm()*c.getIm());
}

double calc_argument(ComplexNumber c) {
    return atan(c.getIm()/c.getRe());
}

const double epsilon = std::numeric_limits<double>::epsilon();

TEST(Muminov_Ruslan_ComplexNumberTest, Does_Triangle_Inequality) {
    // Arrange
    ComplexNumber z1(2.0, -5.0);
    ComplexNumber z2(4.0, 10.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_TRUE(calc_abs_value(z) <= calc_abs_value(z1) + calc_abs_value(z2));
}

TEST(Muminov_Ruslan_ComplexNumberTest,
     Absolute_Values_Of_Conjugates_Are_Equal) {
    // Arrange
    ComplexNumber z1(2.0, 5.0);
    ComplexNumber z2(z1.getRe(), -z1.getIm());

    // Act & Assert
    EXPECT_NEAR(calc_abs_value(z1), calc_abs_value(z2), epsilon);
}

TEST(Muminov_Ruslan_ComplexNumberTest,
     Conjugates_Product_Is_Equal_Square_Absolute_Value) {
    // Arrange
    ComplexNumber z1(14.0, 4.0);
    ComplexNumber z2(z1.getRe(), -z1.getIm());

    // Act
    ComplexNumber z = z1*z2;
    double sqrAbs = calc_abs_value(z1)*calc_abs_value(z1);

    // Assert
    EXPECT_NEAR(z.getRe(), sqrAbs, epsilon);
    EXPECT_EQ(z.getIm(), 0);
}

TEST(Muminov_Ruslan_ComplexNumberTest,
     Conjugates_Sum_Is_Equal_Double_Real_Part) {
    // Arrange
    ComplexNumber z1(23.0, 10.0);
    ComplexNumber z2(z1.getRe(), -z1.getIm());

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_NEAR(z.getRe(), 2*z1.getRe(), epsilon);
    EXPECT_EQ(z.getIm(), 0);
}

TEST(Muminov_Ruslan_ComplexNumberTest,
     Argument_Of_Inverse_Number_Is_Equal_Negative_Argument_Of_Original) {
    // Arrange
    ComplexNumber z1(13.0, 5.0);
    ComplexNumber z(1.0, 0.0);

    // Act
    ComplexNumber z2 = z/z1;

    // Assert
    EXPECT_NEAR(calc_argument(z1), -calc_argument(z2), epsilon);
}
