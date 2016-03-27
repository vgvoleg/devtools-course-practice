// Copyright 2016 Pronina Maria
#include <gtest/gtest.h>

#include "include/complex_number.h"
#include <math.h>

TEST(Pronina_Maria_ComplexNumberTest,
    Imaginary_Number_Square_Is_Negative_Real) {
    // Arrange
    ComplexNumber z(0.0, 1.0);
    //Act
    ComplexNumber square = z * z;
    // Assert 
    ComplexNumber res(-1.0, 0.0);
    EXPECT_TRUE(res == square);
}

TEST(Pronina_Maria_ComplexNumberTest, Triangle_Inequality_For_Complex) {
    // Arrange
    ComplexNumber z1(6.0, 5.0), z2(7.0, 8.0);
    //Act
    ComplexNumber sum = z1 + z2;
    double sumAbs = sqrt(sum.getRe() * sum.getRe() + sum.getIm() * sum.getIm());
    double z1Abs = sqrt(z1.getRe() * z1.getRe() + z1.getIm() * z1.getIm());
    double z2Abs = sqrt(z2.getRe() * z2.getRe() + z2.getIm() * z2.getIm());
    // Assert
    EXPECT_TRUE(sumAbs < z1Abs + z2Abs);
}

TEST(Pronina_Maria_ComplexNumberTest,
    Mult_Of_Complex_And_Conjuate_Is_Abs_Square) {
    // Arrange
    ComplexNumber z1(8.0, 6.0), z2(8.0, -6.0);
    //Act
    ComplexNumber mult = z1 * z2;
    // Assert
    double z1Abs = sqrt(z1.getRe() * z1.getRe() + z1.getIm() * z1.getIm());
    ComplexNumber absSquare(z1Abs * z1Abs, 0.0);
    EXPECT_TRUE(absSquare == mult);
}

TEST(Pronina_Maria_ComplexNumberTest,
    Conjuate_Of_Mult_Is_Equal_To_Mul_Of_Conjuates) {
    // Arrange
    ComplexNumber z1(8.0, 6.0), z2(4.0, -3.0);
    //Act
    ComplexNumber mult = z1 * z2;
    ComplexNumber multConj(mult.getRe(), -mult.getIm());
    // Assert
    ComplexNumber z1Conj(8.0, -6.0), z2Conj(4.0, 3.0);
    EXPECT_TRUE(multConj == z1Conj * z2Conj);
}

TEST(Pronina_Maria_ComplexNumberTest,
    Conjuate_Of_Division_Is_Equal_To_Division_Of_Conjuates) {
    // Arrange
    ComplexNumber z1(8.0, 6.0), z2(4.0, -3.0);
    //Act
    ComplexNumber div = z1 / z2;
    ComplexNumber divtConj(div.getRe(), -div.getIm());
    // Assert
    ComplexNumber z1Conj(8.0, -6.0), z2Conj(4.0, 3.0);
    EXPECT_TRUE(divtConj == z1Conj / z2Conj);
}