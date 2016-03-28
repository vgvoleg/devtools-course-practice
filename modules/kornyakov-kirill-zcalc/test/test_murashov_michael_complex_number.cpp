/* Copyright 2016 Murashov Michael */

#include <gtest/gtest.h>
#include <cmath>

#include "include/complex_number.h"

TEST(Murashov_Michael_ComplexNumberTest, can_work_with_public_methods) {
   // Arrange
   double re = 2.0;
   double im = 3.0;
   ComplexNumber z;

   // Act
   z.setRe(re);
   z.setIm(im);

   // Assert
   ComplexNumber expected_z(z.getRe(), z.getIm());

   EXPECT_EQ(expected_z, z);
}

TEST(Murashov_Michael_ComplexNumberTest, can_compare) {
   // Arrange
   ComplexNumber z1(4.0, -1.0);
   ComplexNumber z2(-1.0, -1.0);
   
   // Act
   bool expect = (z1 == z2);

   // Assert
   EXPECT_FALSE(expect);
}

TEST(Murashov_Michael_ComplexNumberTest, can_count_module) {
   // Arrange
   ComplexNumber z1(2.0, -1.0);

   // Act
   double acr1 = pow(z1.getIm(), 2);
   double acr2 = pow(z1.getRe(), 2);
   double vect = sqrt(acr1 + acr2);

   // Assert
   double expected_vect = sqrt(4.0 + 1.0);

   EXPECT_EQ(expected_vect, vect);
}

TEST(Murashov_Michael_ComplexNumberTest, can_do_algebraic_operations) {
   // Arrange
   ComplexNumber z1(1.0, -1.0);
   ComplexNumber z2(2.0, 2.0);
   ComplexNumber z3(-1.0, 3.0);
   ComplexNumber z4(2.0, -2.0);

   // Act
   ComplexNumber z = z1 * z2 / (z3 + z4);

   // Assert
   ComplexNumber expected_z(2.0, -2.0);

   EXPECT_EQ(expected_z, z);
}

TEST(Murashov_Michael_ComplexNumberTest, DISABLED_correct_cube_of_im_num) {
   // Arrange
   ComplexNumber z(0.0, 1.0);
   ComplexNumber cube;  // z^3

   // Act
   cube = z * z * z;  // re = 0, im = -1

   // Assert
   ComplexNumber expected_z(0.0, -1.0);

   EXPECT_EQ(expected_z, z);
}
