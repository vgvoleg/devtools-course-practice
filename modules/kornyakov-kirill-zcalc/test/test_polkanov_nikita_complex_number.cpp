// Copyright 2016 Polkanov Nikita

 #include <gtest/gtest.h>

 #include "include/complex_number.h"

 TEST(Polkanov_Nikita_ComplexNumberTest, Can_Use_Mult_Neutral_Element) {
     // Arrange
     double re = 3.0;
     double im = 5.0;
	 ComplexNumber z1(re, im);
	 ComplexNumber z2(1.0, 0.0);

     // Act
	 z1 = z1 * z2;


     // Assert
     EXPECT_EQ(re, z1.getRe());
     EXPECT_EQ(im, z1.getIm());
 }

 TEST(Polkanov_Nikita_ComplexNumberTest, Can_Use_Add_Neutral_Element) {
	 // Arrange
	 double re = 3.0;
	 double im = 5.0;
	 ComplexNumber z1(re, im);
	 ComplexNumber z2(0.0, 0.0);

	 // Act
	 z1 = z1 + z2;


	 // Assert
	 EXPECT_EQ(re, z1.getRe());
	 EXPECT_EQ(im, z1.getIm());
 }

 TEST(Polkanov_Nikita_ComplexNumberTest, Can_Use_Assign_Chain) {
	 // Arrange
	 double re = 3.0;
	 double im = 5.0;
	 ComplexNumber z1(re, im);
	 ComplexNumber z2, z3;

	 // Act
	 z3 = z2 = z1;


	 // Assert
	 EXPECT_EQ(z1, z2);
	 EXPECT_EQ(z2, z3);
 }

 TEST(Polkanov_Nikita_ComplexNumberTest, Can_Get_Real) {
	 // Arrange
	 double re = 3.0;
	 double im = 5.0;
	 ComplexNumber z(re, im);

	 // Act
	 // Assert
	 EXPECT_EQ(re, z.getRe());
 }

 TEST(Polkanov_Nikita_ComplexNumberTest, Can_Get_Imaginary) {
	 // Arrange
	 double re = 3.0;
	 double im = 5.0;
	 ComplexNumber z(re, im);

	 // Act
	 // Assert
	 EXPECT_EQ(im, z.getIm());
 }