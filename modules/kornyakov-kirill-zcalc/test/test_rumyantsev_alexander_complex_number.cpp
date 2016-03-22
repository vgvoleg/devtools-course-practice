#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Create_Default_Complex) {
	// Arrange
	ComplexNumber z;

	// Assert
	EXPECT_DOUBLE_EQ(0.0, z.getRe());
	EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Create_From_Int) {
	// Arrange
	int re = 255;
	int im = -10;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_DOUBLE_EQ(255.0, z.getRe());
	EXPECT_DOUBLE_EQ(-10.0, z.getIm());
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Do_Multiple_Assignment) {
	// Arrange
	ComplexNumber z1, z2, z3(1.0, 2.0);

	// Act
	z1 = z2 = z3;

	// Assert
	EXPECT_EQ(z1, z3);
	EXPECT_EQ(z2, z3);
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Assign_To_Yourself) {
	// Arrange
	double re = 2.0;
	double im = 4.0;
	ComplexNumber z(re, im);

	// Act
	z = z;

	// Assert
	EXPECT_DOUBLE_EQ(re, z.getRe());
	EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Multiply_With_Zero) {
	// Arrange
	ComplexNumber z0(0.0, 0.0);
	ComplexNumber z1(5.0, 7.0);

	// Act
	ComplexNumber z = z0 * z1;

	// Assert
	EXPECT_EQ(z0, z);
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Devide_With_Zero) {
	// Arrange
	ComplexNumber z0(0.0, 0.0);
	ComplexNumber z1(2.0, 8.0);

	// Act
	ComplexNumber z = z0 / z1;

	// Assert
	EXPECT_EQ(z0, z);
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Multiply_With_Reciprocal) {
	// Arrange
	ComplexNumber z1(1.0, 2.0);
	ComplexNumber z2(3.0, 4.0);
	ComplexNumber ed(1.0, 0.0);

	// Act
	ComplexNumber reciprocal2 = ed / z2;

	ComplexNumber res1 = z1 / z2;
	ComplexNumber res2 = z1 * reciprocal2;

	// Assert
	EXPECT_EQ(res1, res2);
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Add_Conjugate) {
	// Arrange
	ComplexNumber z1(12.0, 4.0);
	ComplexNumber z2(12.0, -4.0);

	// Act
	ComplexNumber z = z1 + z2;

	// Assert
	/* Re(z) = 2 * Re(z1) */
	ComplexNumber expected_z(24.0, 0.0);
	EXPECT_EQ(expected_z, z);
}

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can_Multiply_Conjugate) {
	// Arrange
	ComplexNumber z1(-6.0, 8.0);
	ComplexNumber z2(-6.0, -8.0);

	// Act
	ComplexNumber z = z1 * z2;

	// Assert
	/* Re(z) = Re(z1)^2 + Re(z2)^2 */
	ComplexNumber expected_z(100.0, 0.0);
	EXPECT_EQ(expected_z, z);
}
