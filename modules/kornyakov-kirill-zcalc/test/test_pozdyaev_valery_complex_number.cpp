#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Set_Boolean) {
	// Arrange
	ComplexNumber z1(0, 0);
	bool t = true;

	// Act
	z1.setRe(t);

	// Assert
	EXPECT_DOUBLE_EQ(1.0, z1.getRe());
}

TEST(Pozdyaev_Valery_ComplexNumberTest, Can_Set_Char) {
	// Arrange
	ComplexNumber z1(0, 0);
	char t = 'a';

	// Act
	z1.setRe(t);

	// Assert
	EXPECT_DOUBLE_EQ(int(t), z1.getRe());
}
