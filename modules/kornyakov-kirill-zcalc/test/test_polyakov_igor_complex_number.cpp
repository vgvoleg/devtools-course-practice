// Copyright 2016 Polyakov Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"
#include <cmath>

TEST(Polyakov_Igor_ComplexNumberTest, Can_Division_With_Unit_In_Numerator) {
    // Arrange
    ComplexNumber z_denominator(1.0, 2.0);
    ComplexNumber z_numerator(1.0, 0.0);

    // Act
    ComplexNumber z = z_numerator / z_denominator;

    // Assert
    EXPECT_EQ(0.2, z.getRe());  // z = 1 / (a + b*i). Re(z) = a / (a^2 + b^2)
    EXPECT_EQ(-0.4, z.getIm());  // z = 1 / (a + b*i). Im(z) = -b / (a^2 + b^2)
}

TEST(Polyakov_Igor_ComplexNumberTest, Can_Sum_Complex_And_Conjugate_Number) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    ComplexNumber z_conjugate(1.0, -2.0);  // z = a + b*i. z_conjugate = a - b*i

    // Act
    ComplexNumber z_rez = z + z_conjugate;

    // Assert
    EXPECT_EQ(2.0, z_rez.getRe());  // z + z_conjugate = 2 * Re(z)
    EXPECT_EQ(0.0, z_rez.getIm());
}

TEST(Polyakov_Igor_ComplexNumberTest, Check_Triangule_Inequality) {
    // |z_1 + z_2| <= |z_1| + |z_2|
    // Arrange
    double x_1 = 1.0;
    double x_2 = 2.0;
    double y_1 = 2.0;
    double y_2 = 3.0;

    ComplexNumber z_1(x_1, y_1);
    ComplexNumber z_2(x_2, y_2);

    // Act
    double module_z_1 = sqrt(pow(z_1.getRe(), 2.0) + pow(z_1.getIm(), 2.0));
    double module_z_2 = sqrt(pow(z_2.getRe(), 2.0) + pow(z_2.getIm(), 2.0));
    double re_sum_sqr = pow(z_1.getRe() + z_2.getRe(), 2.0);
    double im_sum_sqr = pow(z_1.getIm() + z_2.getIm(), 2.0);
    double module_of_summ_complex_numbers = sqrt(re_sum_sqr + im_sum_sqr);

    // Assert
    ASSERT_LE(module_of_summ_complex_numbers, module_z_1 + module_z_2);
}

TEST(Polyakov_Igor_ComplexNumberTest, Can_Joint_Use_Sum_And_Multiplication) {
    // Arrange
    ComplexNumber z_1(1.0, 2.0);
    ComplexNumber z_2(2.0, -3.0);
    ComplexNumber z_3(3.0, 4.0);

    // Act
    ComplexNumber z_rez = (z_1 + z_2) * z_3;

    // Assert
    EXPECT_EQ(13.0, z_rez.getRe());
    EXPECT_EQ(9.0, z_rez.getIm());
}

TEST(Polyakov_Igor_ComplexNumberTest, Is_Complex_Eq_Itself_After_Div_And_Mult) {
    // Arrange

    ComplexNumber z(1.0, 4.0);
    ComplexNumber z_operand(1.0, 2.0);

    // Act
    ComplexNumber z_rez = z / z_operand * z_operand;

    // Assert
    ASSERT_EQ(z, z_rez);
}
