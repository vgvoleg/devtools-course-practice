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
  const int N = 5;  // Expected_Result
  EXPECT_EQ(N, result);
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
  ComplexNumber cnumb[5];
  cnumb[0] = ComplexNumber(2.0, 3.0);
  cnumb[1] = ComplexNumber(2.0, -2.0);
  cnumb[2] = ComplexNumber(1.0, -1.0);
  cnumb[3] = ComplexNumber(1.0, 1.0);
  cnumb[4] = ComplexNumber(2.0, 3.0);

  // Act
  const int N = 15;  // Number_Of_Cycles
  ComplexNumber resultCNumb(1.0, 0.0);
  // Result_Complex=Result_Complex+cnum1*cnum2-(cnum3/cnum4)+cnum5
  for (int i = 0; i < N; i++)
    resultCNumb = resultCNumb+cnumb[0]*cnumb[1] - cnumb[2] / cnumb[3] + cnumb[4];

  // Assert
  ComplexNumber expectedCNumb(180, 90);
  EXPECT_EQ(expectedCNumb, resultCNumb);
}

TEST(Kulish_Sem_complex_test, Can_Check_Triangle_Inequality) {
  // Arrange
  ComplexNumber cnumb1(3.0, -2.0);
  ComplexNumber cnumb2(-1.0, 5.0);

  // Act
  // |z1|-|z2|<||z1|-|z2||<|z1+z2|<|z1|+|z2|
  bool triangleCheck = false;
  double fstIneq = vectorlength(cnumb1) - vectorlength(cnumb2);
  double sndIneq = abs(vectorlength(cnumb1) - vectorlength(cnumb2));
  double trdIneq = vectorlength(cnumb1 + cnumb2);
  double fthIneq = vectorlength(cnumb1) + vectorlength(cnumb2);

  if (fstIneq < sndIneq && sndIneq < trdIneq && trdIneq < fthIneq)
    triangleCheck = true;

  // Assert
  EXPECT_TRUE(triangleCheck);
}

TEST(Kulish_Sem_complex_test, Can_Build_Complex_To_Any_Pow) {
  // Arrange
  ComplexNumber cnumb(4, 3);

  // Act
  const int N = 10;
  ComplexNumber result(1, 0);
  for (int i = 1; i <= N; i++)
    result = result*cnumb;

  // Assert
  ComplexNumber expectedResultCnumb(9653287, 1476984);
  EXPECT_EQ(expectedResultCnumb, result);
}
