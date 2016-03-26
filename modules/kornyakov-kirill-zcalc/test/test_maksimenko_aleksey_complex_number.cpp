// Copyright 2016 Maksimenko Aleksey

#include <gtest/gtest.h>
#include <limits>
#include <cmath>

#include "include/complex_number.h"

TEST(Maksimenko_Aleksey_ComplexNumberTest, division_and_multiplication_of_complex_numbers_different) {
	//a, b and c - complex numbers;
	ComplexNumber a(2, 1);
	ComplexNumber b(4, 1);
	ComplexNumber c(1, 1);
	ComplexNumber result(6.5, -0.5);

	ComplexNumber r = (a*b) / c;

	EXPECT_EQ(r,result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, the_quotient_of_the_difference_of_squares_and_difference_of_complex_numbers) {
	//cn1 and cn2 - complex numbers;
	ComplexNumber cn1(4, 2);
	ComplexNumber cn2(6, 8);
	//((4 + 2i)^2 - (6 + 8i)^2)/(4+2i-6-8i)=4+2i+6+8i;
	ComplexNumber result = cn1 + cn2;
	ComplexNumber res = (cn1*cn1 - cn2*cn2) / (cn1 - cn2);

	EXPECT_EQ(res, result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, the_quotient_of_the_difference_of_squares_and_sums_of_complex_numbers) {
	//cn1 and cn2 - complex numbers;
	ComplexNumber cn1(4, 2);
	ComplexNumber cn2(6, 8);
	//((4 + 2i)^2 - (6 + 8i)^2)/(4+2i+6+8i)=4+2i-6-8i;
	ComplexNumber result = cn1 - cn2;
	ComplexNumber res = (cn1*cn1 - cn2*cn2) / (cn1 + cn2);

	EXPECT_EQ(res, result);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, the_quotient_of_the_squares_of_complex_conjugate_numbers) {
	//cn1 and cn2 - complex conjugate numbers, n1 and n2 - an arbitrary number, ins - conversion in the opposite number;
	ComplexNumber cn1(1, -1);
	ComplexNumber cn2(1, 1);
	ComplexNumber n1(7, 0);
	ComplexNumber n2(14, 0);
	ComplexNumber ins(-1, 0);

	//a*(1-i)^2/(b*(1+i)^2)=a*(1+i)^2/(b*(1-i)^2)=-a/b;
	ComplexNumber res1 = n1*cn1*cn1 / (n2*cn2*cn2);
	ComplexNumber res2 = n1*cn2*cn2 / (n2*cn1*cn1);
	ComplexNumber result = ins*n1 / n2;
	

	EXPECT_EQ(res1, res2);
	EXPECT_EQ(res1, result);
	EXPECT_EQ(result, res2);
}

TEST(Maksimenko_Aleksey_ComplexNumberTest, difference_of_cubes,_complex_numbers) {
	//cn1 and cn2 - complex numbers;
	ComplexNumber cn1(1, 1);
	ComplexNumber cn2(1, 2);
	//a^3-b^3=(a-b)*(a^2+ab+b^2);
	ComplexNumber res=cn1*cn1*cn1-cn2*cn2*cn2;
	ComplexNumber result = (cn1 - cn2)*(cn1*cn1 + cn1*cn2 + cn2*cn2);

	EXPECT_EQ(res, result);
}
