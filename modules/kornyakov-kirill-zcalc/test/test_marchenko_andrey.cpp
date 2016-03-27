#include <gtest/gtest.h>
#include "cmath"
#include "include/complex_number.h"

TEST(Marchenko_Andrey_ComplexNumberTest, Can_Create_Int_Char_Variable) {
    // Arrange
    int re = 0;
    char im = 0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Marchenko_Andrey_ComplexNumberTest, Can_Use_Big_Complex_Numbers) {
    // Arrange
    double a = sqrt(1000);
    double b = sqrt(2000);
    ComplexNumber z1(a,b);
    ComplexNumber z2(2 * a, 2 * b);

    // Act
    ComplexNumber result = z1 + z2;
    ComplexNumber expected_result(3 * a, 3 * b);

    // Assert
    EXPECT_EQ(result, expected_result);
}
