// Copyright 2016 Litsov Alex

#include <gtest/gtest.h>
#include <cmath>

#include "include/complex_number.h"

TEST(Litsov_Alex_ComplexNumberTest, Check_Triangle_Inequality) {
    // Arrange
    ComplexNumber a(1, 1), b(2, 2);

    // Act
    ComplexNumber sum_num = a + b;
    double module_of_sum = pow(sum_num.getRe()*sum_num.getRe()
         + sum_num.getIm()*sum_num.getIm(), 0.5);
    double sum_of_modules = pow(a.getRe()*a.getRe() + a.getIm()*a.getIm(), 0.5)
         + pow(b.getRe()*b.getRe() + b.getIm()*b.getIm(), 0.5);

    // Assert
    ASSERT_LE(module_of_sum, sum_of_modules);
}

TEST(Litsov_Alex_ComplexNumberTest, Sum_Is_Commutative) {
    // Arrange
    ComplexNumber a(1.5, 2.9), b(13.82, 122.2311);

    // Act
    ComplexNumber left_to_right = a + b;
    ComplexNumber right_to_left = b + a;

    // Assert
    ASSERT_EQ(left_to_right, right_to_left);
}

TEST(Litsov_Alex_ComplexNumberTest, Sum_Is_Associative) {
    // Arrange
    ComplexNumber a(1.5, 2.9), b(13.82, 122.2311), c(223.2, 13332.11);

    // Act
    ComplexNumber res1 = a+(b+c);
    ComplexNumber res2 = (a+b)+c;

    // Assert
    ASSERT_EQ(res1, res2);
}

TEST(Litsov_Alex_ComplexNumberTest, Can_Mult_By_One) {
    // Arrange
    ComplexNumber a(123.11, -0.1123);
    ComplexNumber b(1, 0);

    // Act
    ComplexNumber res = a*b;

    // Assert
    ComplexNumber exp_num(123.11, -0.1123);
    ASSERT_EQ(res, exp_num);
}

TEST(Litsov_Alex_ComplexNumberTest, Mult_Is_Commutative) {
    // Arrange
    ComplexNumber a(3.13, 2.9), b(13.82, 122.2311);

    // Act
    ComplexNumber res1 = a*b;
    ComplexNumber res2 = b*a;

    // Assert
    ASSERT_EQ(res1, res2);
}

TEST(Litsov_Alex_ComplexNumberTest, DISABLED_Div_Is_Distributive) {
    // Arrange
    ComplexNumber a(3.13, 2.9), b(13.82, 122.2311), c(2.15, 21.16);

    // Act
    ComplexNumber sum = a + b;
    ComplexNumber res1 = sum / c;
    ComplexNumber div1 = a / c;
    ComplexNumber div2 = b / c;
    ComplexNumber res2 = div1 + div2;
    // Assert
    ASSERT_EQ(res1, res2);
}
