// Copyright 2016 Maksimenko Aleksey

#include <gtest/gtest.h>
#include <limits>
#include <cmath>

#include "include/complex_number.h"

TEST(Maksimenko_Aleksey_ComplexNumberTest, division_and_multiplication) {
	// Arrange
	ComplexNumber a(2, 1);
	ComplexNumber b(4, 1);
	ComplexNumber c(1, 1);
	ComplexNumber result(6.5, -0.5);

	// Act
	ComplexNumber z = (a*b) / c;

	// Assert
	EXPECT_EQ(z,result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, difference_of_squares_and_difference) {
	// Arrange
	ComplexNumber cn1(4, 2);
	ComplexNumber cn2(6, 8);
	
	// Act
	ComplexNumber result = cn1 + cn2;
	ComplexNumber res = (cn1*cn1 - cn2*cn2) / (cn1 - cn2);
	
	// Assert
	EXPECT_EQ(res, result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, difference_of_squares_and_sums) {
	// Arrange
	ComplexNumber cn1(4, 2);
	ComplexNumber cn2(6, 8);
	
	// Act
	ComplexNumber result = cn1 - cn2;
	ComplexNumber res = (cn1*cn1 - cn2*cn2) / (cn1 + cn2);
	
	// Assert
	EXPECT_EQ(res, result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, can_work_with_complex_numbers_conjugates)) {
	// Arrange
	ComplexNumber cn1(1, -1);
	ComplexNumber cn2(1, 1);
	ComplexNumber n1(7, 0);
	ComplexNumber n2(14, 0);
	ComplexNumber ins(-1, 0);
	
	// Act
	ComplexNumber res1 = n1*cn1*cn1 / (n2*cn2*cn2);
	ComplexNumber res2 = n1*cn2*cn2 / (n2*cn1*cn1);
	ComplexNumber result = ins*n1 / n2;
	
	// Assert
	EXPECT_EQ(res1, res2);
	EXPECT_EQ(res1, result);
	EXPECT_EQ(result, res2);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, can_apply_the_formula_of_difference_of_cubes) {
	// Arrange
	ComplexNumber cn1(1, 1);
	ComplexNumber cn2(1, 2);
	
	// Act
	ComplexNumber res=cn1*cn1*cn1-cn2*cn2*cn2;
	ComplexNumber result = (cn1 - cn2)*(cn1*cn1 + cn1*cn2 + cn2*cn2);
	
	// Assert
	EXPECT_EQ(res, result);
}
