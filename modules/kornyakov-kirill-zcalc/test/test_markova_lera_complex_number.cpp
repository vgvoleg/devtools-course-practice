// Copyright 2016 Markova Lera

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Markova_Lera_ComplexNumberTest, Can_Set_Re_and_Im) {
    // Arrange
    ComplexNumber example(0.0, 0.0);
    // Act
    example.setIm(15.0);
    example.setRe(69.0);
    // Assert
    ComplexNumber expectedValue(69.0, 15.0);
    EXPECT_EQ(example, expectedValue);
}

TEST(Markova_Lera_ComplexNumberTest, Can_Get_Big_Sum) {
    // Arrange
    ComplexNumber example(1.0, 1.0);
    // Act
    ComplexNumber result;
    const int N = 500;
    for (unsigned i = 0; i < N; i++)
       result = result + example;
    // Assert
    ComplexNumber expectedValue(500.0, 500.0);
    EXPECT_EQ(expectedValue, result);
}

TEST(Markova_Lera_ComplexNumberTest, distributivity_saved) {
  // Arrange
  ComplexNumber firstEx(13.0, 103.0);
  ComplexNumber secondEx(610.0, 140.0);
  ComplexNumber thirdEx(15.0, 11.0);
  // Act
  ComplexNumber leftSide = (firstEx + secondEx) * thirdEx;
  ComplexNumber rightSide = (firstEx * thirdEx) + (secondEx * thirdEx);
  // Assert
  EXPECT_EQ(leftSide, rightSide);
}

TEST(Markova_Lera_ComplexNumberTest, Use_Re_Im_and_copy_is_work) {
    // Arrange
    ComplexNumber firstExample(153.0, 17.0);
    ComplexNumber secondExampleByCopy;
    // Act
    double Im;
    double Re;
    Im = firstExample.getIm();
    Re = firstExample.getRe();

    // Assert
    secondExampleByCopy = firstExample;
    ComplexNumber secondExampleByDoubleGet(Re, Im);
    EXPECT_EQ(secondExampleByCopy, secondExampleByDoubleGet);
}

TEST(Markova_Lera_ComplexNumberTest, Can_Multyply) {
    // Arrange
    ComplexNumber unitExample(1.0, 1.0);
    ComplexNumber firstExpected(1.0, 0);
    ComplexNumber secondExpected(1.0, 0);

    // Act
    const int dividedIntoTwo = 100;
    const int notDividedIntoTwo = 111;

    for (int i = 0; i < dividedIntoTwo; i++) {
        firstExpected = firstExpected * unitExample;
    }

    for (int i = 0; i < notDividedIntoTwo; i++) {
        secondExpected = secondExpected * unitExample;
    }

    // Assert
    EXPECT_NE(firstExpected, secondExpected);
}
