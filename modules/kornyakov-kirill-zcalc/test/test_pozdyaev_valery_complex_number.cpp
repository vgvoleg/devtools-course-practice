#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Set_Boolean) {
	// Arrange
	ComplexNumber z1(0, 0);
	bool re = true;

	// Act
	z1.setRe(re);

	// Assert
	EXPECT_DOUBLE_EQ(1.0, z1.getRe());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Set_Different_Types) {
	// Arrange
	ComplexNumber z(0, 0);
	char re = 'a';
	short im = 255;

	// Act
	z.setRe(re);
	z.setIm(im);

	// Assert
	EXPECT_DOUBLE_EQ(re, z.getRe());
	EXPECT_DOUBLE_EQ(im, z.getIm());
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
	ComplexNumber z(1.0, 1.0);

	// Act
	z = z;

	// Assert
	EXPECT_EQ(z, z);
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Multiplication_With_Inverse_Number) {
	// Arrange
	ComplexNumber z(1.0, 1.0);
	ComplexNumber inverse_z(0.5, -0.5);

	// Act
	ComplexNumber result = z * inverse_z;

	// Assert
	EXPECT_DOUBLE_EQ(1.0, result.getRe());
	EXPECT_DOUBLE_EQ(0, result.getIm());
}