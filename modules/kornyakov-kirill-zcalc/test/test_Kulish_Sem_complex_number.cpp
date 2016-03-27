// Copyright 2016 Kulish Semyon

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Kulish_Sem_complex_test, Can_Calculate_Vector_Length) {
  // Arrange
  ComplexNumber vector(4.0, 3.0);

  // Act
  double result = sqrt(pow(vector.getRe(), 2) + pow(vector.getIm(), 2));

  // Assert
  EXPECT_EQ(5, result);
}

TEST(Kulish_Sem_complex_test, Two_Complex_Are_Equiv_After_Multiplications) {
  // Arrange
  ComplexNumber cnumb1(5.0, 16.0);
  ComplexNumber cnumb2(2.2, 3.9);
  ComplexNumber result1;
  ComplexNumber result2;

  // Act
  result1 = cnumb2*cnumb1;
  result2 = cnumb1*cnumb2;

  // Assert
  EXPECT_EQ(result1, result2);
}

TEST(Kulish_Sem_complex_test, Can_Make_All_Oper_Some_Times) {
  // Arrange
  ComplexNumber cnumb1(2.0, 3.0);
  ComplexNumber cnumb2(2.0, -2.0);
  ComplexNumber cnumb3(1.0, -1.0);
  ComplexNumber cnumb4(1.0, 1.0);
  ComplexNumber cnumb5(2.0, 3.0);
  ComplexNumber resultCNumb;
  ComplexNumber expectedCNumb(180, 90);

  // Act
  for (int i = 0; i < 15; i++)
    resultCNumb = resultCNumb+(cnumb1*cnumb2 - cnumb3 / cnumb4 + cnumb5);

  // Assert
  EXPECT_EQ(expectedCNumb, resultCNumb);
}

TEST(Kulish_Sem_complex_test, Can_Check_Triangle_Inequality) {
  // Arrange
  ComplexNumber cnumb1(3.0, -2.0);
  ComplexNumber cnumb2(-1.0, 5.0);
  ComplexNumber buffCNum;
  bool triangleCheck = false;
  double fstIneq;
  double sndIneq;
  double trdIneq;
  double fthIneq;

  // Act
  // |z1|-|z2|<||z1|-|z2||<|z1+z2|<|z1|+|z2|
  fstIneq = sqrt(pow(cnumb1.getRe(), 2) + pow(cnumb1.getIm(), 2))
  - sqrt(pow(cnumb2.getRe(), 2) + pow(cnumb2.getIm(), 2));

  sndIneq = abs(sqrt(pow(cnumb1.getRe(), 2) + pow(cnumb1.getIm(), 2))
  - sqrt(pow(cnumb2.getRe(), 2) + pow(cnumb2.getIm(), 2)));

  buffCNum = cnumb1 + numb2;

  trdIneq = sqrt(pow(buffCNum.getRe(), 2) + pow(buffCNum.getIm(), 2));

  fthIneq = sqrt(pow(cnumb1.getRe(), 2) + pow(cnumb1.getIm(), 2))
  + sqrt(pow(cnumb2.getRe(), 2) + pow(cnumb2.getIm(), 2));

  if (fstIneq < sndIneq && sndIneq < trdIneq && trdIneq < fthIneq)
    triangleCheck = true;

  // Assert
  EXPECT_TRUE(triangleCheck);
}

TEST(Kulish_Sem_complex_test, Can_Build_Complex_To_Any_Pow) {
  // Arrange
  ComplexNumber cnumb(4, 3);
  ComplexNumber result(1, 0);
  ComplexNumber expectedResultCnumb(9653287, 1476984);
  int N = 10;

  // Act
  for (int i = 1; i <= N; i++)
    result = result*cnumb;

  // Assert
  EXPECT_EQ(expectedResultCnumb, result);
}
