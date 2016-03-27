// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zemtsov_Artem_ComplexNumberTest, Can_Get_Sum_Of_The_Many_Complex) {
	// Arrange
	const unsigned N = 10000;
	ComplexNumber z(1.0, 1.0);
	ComplexNumber z_res;

	// Act
	for (unsigned i = 0; i < N; i++)
		z_res = z_res + z;

	// Assert
	ComplexNumber expected_z(10000.0, 10000.0);
	EXPECT_EQ(expected_z, z_res);
}
TEST(Zemtsov_Artem_ComplexNumberTest, distributivity_is_work) {
	// Arrange
	ComplexNumber firstEx(10.0, 10.0);
	ComplexNumber secondEx(25.0,15.0);
	ComplexNumber thirdEx(13, 66);

	// Normal human assert
	EXPECT_EQ(firstEx*thirdEx+secondEx*thirdEx, thirdEx*(firstEx+secondEx));
}
