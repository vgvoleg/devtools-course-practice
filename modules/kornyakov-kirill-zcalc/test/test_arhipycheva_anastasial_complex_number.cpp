// Copyright 2016 Arhipycheva Anastasia
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Can_Create_From_Double) {
  double re = -922337203685;
  double im = 260.45682;

  ComplexNumber complex(re, im);

  EXPECT_DOUBLE_EQ(-922337203685, complex.getRe());
  EXPECT_DOUBLE_EQ(260.45682, complex.getIm());
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Addition_With_Opposing_Number) {
  int re = 140;
  int im = 444;

  ComplexNumber null(0, 0);
  ComplexNumber complex1(re, -im);
  ComplexNumber complex2(-re, im);

  EXPECT_EQ(null, complex1 + complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Imaginary) {
  int re = 0;
  int im1 = 444;
  int im2 = 666;

  ComplexNumber complex1(re, im1);
  ComplexNumber complex2(re, im2);

  EXPECT_EQ(false, complex1 == complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Real) {
  int re1 = 123;
  int re2 = 12;
  int im = 0;

  ComplexNumber complex1(re1, im);
  ComplexNumber complex2(re2, im);

  EXPECT_EQ(true, complex1 != complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_Different_Types) {
  int re1 = 123;
  double re2 = 12.556;
  double im1 = 13.487;
  int im2 = 489;

  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  EXPECT_EQ(true, complex1 != complex2);
}


TEST(Arhipycheva_Anastasia_ComplexNumberTest, Can_Multiplication_When_Null) {
  int re1 = 0;
  int re2 = 546;
  int im1 = 789;
  int im2 = 0;

  ComplexNumber null(0, 0);
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  EXPECT_EQ(null, complex1*complex2);
}
