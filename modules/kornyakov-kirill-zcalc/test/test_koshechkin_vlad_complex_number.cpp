//
// Created by Влад on 27.03.16.
//


#include <gtest/gtest.h>

#include "include/complex_number.h"
using std::vector;
using std::string;

TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Create_With_Zero_Imaginary) {
    // Arrange
    double re = 2.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}
TEST(Koshechkin_Vlad_ComplexNumberTest, Can_Assignment) {
    // Arrange
    ComplexNumber z;
    ComplexNumber c(1.0, 2.0);

    // Act
    z=c;

    // Assert
    EXPECT_DOUBLE_EQ(1.0, z.getRe());
    EXPECT_DOUBLE_EQ(2.0, z.getIm());
}
