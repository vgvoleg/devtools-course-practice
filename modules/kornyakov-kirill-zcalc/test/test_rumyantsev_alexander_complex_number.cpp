#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kornyakov_Kirill_ComplexNumberTest, Can_Create_Default_Complex) {
	// Arrange
	ComplexNumber z;

	// Assert
	EXPECT_DOUBLE_EQ(0.0, z.getRe());
	EXPECT_DOUBLE_EQ(0.0, z.getIm());
}
