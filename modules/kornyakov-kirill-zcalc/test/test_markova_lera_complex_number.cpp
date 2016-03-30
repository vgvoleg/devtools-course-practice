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
    ComplexNumber result;
    // Act
    for (unsigned i = 0; i < 500; i++)
       result = result + example;
    // Assert
    ComplexNumber expectedValue(500.0, 500.0);
    EXPECT_EQ(expectedValue, result);
}

TEST(Markova_Lera_ComplexNumberTest, distributivity_saved_and_use_Re_Im) {
  // Arrange
  ComplexNumber firstEx(13.0, 103.0)
  ComplexNumber secondEx(610.0, 140.0);
  ComplexNumber thirdEx(15.0, 11.0);
  // Act
  ComplexNumber leftSide = (firstEx + secondEx) * thirdEx;
  ComplexNumber rightSide = (firstEx * thirdEx) + (secondEx * thirdEx);
  // Assert
  EXPECT_EQ(leftSide, rightSide);
}

TEST(Markova_Lera_ComplexNumberTest, copy_is_work) {
    // Arrange
    ComplexNumber firstExample(153.0, 17.0);
    ComplexNumber secondExampleByCopy;
    double Im;
    double Re;
    // Act
    secondExampleByCopy = firstExample;
    Im = firstExample.getIm();
    Re = firstExample.getRe();
    ComplexNumber secondExampleByDoubleGet(Re, Im);
    // Assert
    EXPECT_EQ(secondExampleByCopy, secondExampleByDoubleGet);
}

TEST(Markova_Lera_ComplexNumberTest, Can_Multyply) {
    // Arrange
    ComplexNumber unitExample(1.0, 1.0);
    const int dividedIntoTwo = 100;
    const int notDividedIntoTwo = 111;
    ComplexNumber firstExpected;
    ComplexNumber secondExpected;
    // Act
    for (int i = 0; i < dividedIntoTwo; i++) {
        unitExample = unitExample * unitExample;
        firstExpected = unitExample;
    }
    unitExample.setIm(1.0);  // comeback
    unitExample.setRe(1.0);  // comeback
    for (int i = 0; i < notDividedIntoTwo; i++) {
        unitExample = unitExample * unitExample;
        secondExpected = unitExample;
    }
    // Assert
    EXPECT_NE(firstExpected, secondExpected);
}
