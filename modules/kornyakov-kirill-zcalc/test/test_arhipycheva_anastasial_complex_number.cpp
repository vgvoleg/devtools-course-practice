// Copyright 2016 Arhipycheva Anastasia
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Can_Create_From_Double) {
  //  Arrage
  double re = -922337203685;
  double im = 260.45682;
  //  Act
  ComplexNumber complex(re, im);

  //  Assert
  EXPECT_DOUBLE_EQ(-922337203685, complex.getRe());
  EXPECT_DOUBLE_EQ(260.45682, complex.getIm());
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Addition_With_Opposing_Number) {
  //  Arrage
  int re = 140;
  int im = 444;

  //  Act
  ComplexNumber null(0, 0);
  ComplexNumber complex1(re, -im);
  ComplexNumber complex2(-re, im);

  //  Assert
  EXPECT_EQ(null, complex1 + complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Imaginary) {
  //  Arrage
  int re = 0;
  int im1 = 444;
  int im2 = 666;

  //  Act
  ComplexNumber complex1(re, im1);
  ComplexNumber complex2(re, im2);

  //  Assert
  EXPECT_EQ(false, complex1 == complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Real) {
  //  Arrage
  int re1 = 123;
  int re2 = 12;
  int im = 0;

  //  Act
  ComplexNumber complex1(re1, im);
  ComplexNumber complex2(re2, im);

  //  Assert
  EXPECT_EQ(true, complex1 != complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_Different_Types) {
  //  Arrage
  int re1 = 123;
  double re2 = 12.556;
  double im1 = 13.487;
  int im2 = 489;

  //  Act
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  //  Assert
  EXPECT_EQ(true, complex1 != complex2);
}


TEST(Arhipycheva_Anastasia_ComplexNumberTest, DISABLED_Multiplic_When_Null) {
  //  Arrage
  int re1 = 0;
  int re2 = 546;
  int im1 = 789;
  int im2 = 0;

  //  Act
  ComplexNumber null(0, 0);
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  //  Assert
  EXPECT_EQ(null, complex1*complex2);
}
