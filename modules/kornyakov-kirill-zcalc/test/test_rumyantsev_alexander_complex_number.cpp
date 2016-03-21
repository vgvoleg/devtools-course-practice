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

TEST(Rumyantsev_Alexander_ComplexNumberTest, Can__Do_Multiple_Assignment) {
	// Arrange
	ComplexNumber z1, z2, z3(1.0, 2.0);

	// Act
	z1 = z2 = z3;

	// Assert
	EXPECT_EQ(z1, z3);
	EXPECT_EQ(z2, z3);
}
