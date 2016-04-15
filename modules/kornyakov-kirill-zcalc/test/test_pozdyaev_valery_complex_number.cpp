// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Set_Int) {
    // Arrange
    int re = 12;
    int im = -24;
    ComplexNumber z1;

    // Act
    z1.setRe(re);
    z1.setIm(im);

    // Assert
    EXPECT_DOUBLE_EQ(12.0, z1.getRe());
    EXPECT_DOUBLE_EQ(-24.0, z1.getIm());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Add_Small_Complex) {
    // Arrange
    ComplexNumber z1(1e-10, 1e-20);
    ComplexNumber z2(1e-10, 1e-20);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z(2e-10, 2e-20);
    EXPECT_EQ(expected_z, z);
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Do_Multi_Assignment) {
    // Arrange
    ComplexNumber a, b;
    ComplexNumber c(3.0, 3.0);

    // Act
    a = b = c;

    // Assert
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Do_Assignment_To_Itself) {
    // Arrange
    double re = 3.0;
    double im = 4.0;
    ComplexNumber z(re, im);

    // Act
    z = z;

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Multiply_With_Inverse) {
    // Arrange
    ComplexNumber z(1.0, 1.0);
    ComplexNumber inverse_z(0.5, -0.5);

    // Act
    ComplexNumber result = z * inverse_z;

    // Assert
    EXPECT_DOUBLE_EQ(1.0, result.getRe());
    EXPECT_DOUBLE_EQ(0, result.getIm());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Create_Reciprocal) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    ComplexNumber z_one(1.0, 0);

    // Act
    ComplexNumber result = z_one / z;

    // Assert
    double re = 0.2;  /* Re(1/z) = Re(z) / (Re(z)^2 + Im(z)^2) */
    double im = -0.4;  /* Im(1/z) = -Im(z) / (Re(z)^2 + Im(z)^2) */
    EXPECT_DOUBLE_EQ(re, result.getRe());
    EXPECT_DOUBLE_EQ(im, result.getIm());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Mult_Conjugates_Is_Mult_Of_Modules) {
    // Arrange
    ComplexNumber z(3.0, 4.0);
    ComplexNumber conjugate_z(3.0, -4.0);

    // Act
    ComplexNumber result = z * conjugate_z; /* z * Conjugate(z) = |z|^2 */

    // Assert
    EXPECT_DOUBLE_EQ(25.0, result.getRe());
    EXPECT_DOUBLE_EQ(0, result.getIm());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Extract_Complex_Using_Conjugate) {
    // Arrange
    ComplexNumber z(3.0, 4.0);
    ComplexNumber conjugate_z(3.0, -4.0);

    // Act
    double re = 0.5 * (z + conjugate_z).getRe();  // Re = 0.5*(z + conj_z))
    double im = 0.5 * (z - conjugate_z).getIm();  // Im = (0.5/i)*(z - conj_z)

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}
