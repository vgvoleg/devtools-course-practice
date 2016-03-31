  // Copyright 2016 Arhipycheva Anastasia

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Can_Create_From_Double) {
  //  Arrage　＆　Act
  const double re = -922337203685;
  const double im = 260.45682;
  ComplexNumber complex(re, im);

  //  Assert
  EXPECT_DOUBLE_EQ(-922337203685, complex.getRe());
  EXPECT_DOUBLE_EQ(260.45682, complex.getIm());
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Addition_With_Opposing_Number) {
  //  Arrage　＆　Act
  const int re = 140;
  const int im = 444;
  ComplexNumber null(0, 0);
  ComplexNumber complex1(re, -im);
  ComplexNumber complex2(-re, im);

  //  Assert
  EXPECT_EQ(null, complex1 + complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Imaginary) {
  //  Arrage　＆　Act
  const int re = 0;
  const int im1 = 444;
  const int im2 = 666;
  ComplexNumber complex1(re, im1);
  ComplexNumber complex2(re, im2);

  //  Assert
  EXPECT_FALSE(complex1 == complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_When_Only_Real) {
  //  Arrage　＆　Act
  const int re1 = 123;
  const int re2 = 12;
  const int im = 0;
  ComplexNumber complex1(re1, im);
  ComplexNumber complex2(re2, im);

  //  Assert
  EXPECT_NE(complex1, complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumberTest, Comparison_Different_Types) {
  //  Arrage　＆　Act
  const int re1 = 124;
  const double re2 = 12.556;
  const double im1 = 13.487;
  const int im2 = 489;
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  //  Assert
  EXPECT_NE(complex1, complex2);
}


TEST(Arhipycheva_Anastasia_ComplexNumberTest, DISABLED_Multiplic_When_Null) {
  //  Arrage　＆　Act
  const int re1 = 0;
  const int re2 = 546;
  const int im1 = 789;
  const int im2 = 0;
  ComplexNumber null(0, 0);
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);

  //  Assert
  EXPECT_EQ(null, complex1*complex2);
}

TEST(Arhipycheva_Anastasia_ComplexNumbeкTest, DISABLED_Division_Null) {
  //  Arrage　＆　Act
  const int re1 = 8;
  const int re2 = 4;
  const int im1 = 12;
  const int im2 = 6;
  ComplexNumber complex1(re1, im1);
  ComplexNumber complex2(re2, im2);
  ComplexNumber complex3(re1+8, im2-2);
  ComplexNumber complex4 = (complex1 * complex2) / complex3;
  ComplexNumber rezult(2, 18);

  //  Assert
  EXPECT_EQ(rezult, complex4);
}
