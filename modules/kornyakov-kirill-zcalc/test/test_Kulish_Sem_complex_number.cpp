// Copyright 2016 Kulish Semyon

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"


double vectorlength(const ComplexNumber & cn) {
  return sqrt(pow(cn.getRe(), 2) + pow(cn.getIm(), 2));
}

TEST(Kulish_Sem_complex_test, Can_Calculate_Vector_Length) {
  // Arrange
  ComplexNumber cnum(4.0, 3.0);

  // Act
  double result = vectorlength(cnum);

  // Assert
  const int N = 5;  //Expected_Result
  EXPECT_EQ(5, result);
}

TEST(Kulish_Sem_complex_test, Can_Use_Commutative_Operation) {
  // Arrange
  ComplexNumber cnumb1(5.0, 16.0);
  ComplexNumber cnumb2(2.2, 3.9);

  // Act & Assert
  EXPECT_EQ(cnumb2*cnumb1, cnumb1*cnumb2);
}

TEST(Kulish_Sem_complex_test, Can_Make_All_Oper_Some_Times) {
  // Arrange
  ComplexNumber cnumb1(2.0, 3.0);
  ComplexNumber cnumb2(2.0, -2.0);
  ComplexNumber cnumb3(1.0, -1.0);
  ComplexNumber cnumb4(1.0, 1.0);
  ComplexNumber cnumb5(2.0, 3.0);
  const int N = 15;  // Number_Of_Cycles

  // Act
  ComplexNumber resultCNumb;
  for (int i = 0; i < N; i++)
    resultCNumb = resultCNumb+(cnumb1*cnumb2 - cnumb3 / cnumb4 + cnumb5);

  // Assert
  ComplexNumber expectedCNumb(180, 90);
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
  fstIneq = vectorlength(cnumb1) - vectorlength(cnumb2);
  sndIneq = abs(vectorlength(cnumb1) - vectorlength(cnumb2));
  buffCNum = cnumb1 + cnumb2;
  trdIneq = vectorlength(buffCNum);
  fthIneq = vectorlength(cnumb1) + vectorlength(cnumb2);

  if (fstIneq < sndIneq && sndIneq < trdIneq && trdIneq < fthIneq)
    triangleCheck = true;

  // Assert
  EXPECT_TRUE(triangleCheck);
}

TEST(Kulish_Sem_complex_test, Can_Build_Complex_To_Any_Pow) {
  // Arrange
  ComplexNumber cnumb(4, 3);
  const int N = 10;

  // Act
  ComplexNumber result(1, 0);
  for (int i = 1; i <= N; i++)
    result = result*cnumb;

  // Assert
  ComplexNumber expectedResultCnumb(9653287, 1476984);
  EXPECT_EQ(expectedResultCnumb, result);
}
