// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>
#include <math.h>
#include "include/complex_number.h"

TEST(Zemtsov_Artem_ComplexNumberTest, Can_Get_Sum_Of_The_Many_Complex) {
    // Arrange
    const unsigned N = 10000;
    ComplexNumber z(1.0, 1.0);
    ComplexNumber z_res;

    // Act
    for (unsigned i = 0; i < N; i++)
        z_res = z_res + z;

    // Assert
    ComplexNumber expected_z(10000.0, 10000.0);
    EXPECT_EQ(expected_z, z_res);
}

TEST(Zemtsov_Artem_ComplexNumberTest, distributivity_is_work) {
    // Arrange
    ComplexNumber firstEx(10.0, 10.0);
    ComplexNumber secondEx(25.0, 15.0);
    ComplexNumber thirdEx(13, 66);

    // Assert
    EXPECT_EQ(firstEx*thirdEx+secondEx*thirdEx, thirdEx*(firstEx+secondEx));
}

TEST(Zemtsov_Artem_ComplexNumberTest, check_conjuate_Is_Abs_Square) {
    // Arrange
    ComplexNumber fEx(8.0, 6.0), secEx(8.0, -6.0);

    // Act
    ComplexNumber multy = fEx * secEx;
    double abs = sqrt(fEx.getRe() * fEx.getRe()+fEx.getIm() * fEx.getIm() );
    ComplexNumber absSquare(abs * abs, 0.0);

    // Assert
    EXPECT_TRUE(absSquare == multy);
}

TEST(Zemtsov_Artem_ComplexNumberTest, can_get_and_set_re_and_im) {
    // Arrange
    ComplexNumber firstEx(13, 66) , secEx;

    // Act
    secEx.setIm(firstEx.getIm());
    secEx.setRe(firstEx.getRe());

    // Assert
    EXPECT_EQ(firstEx, secEx);
}

TEST(Zemtsov_Artem_ComplexNumberTest, checking_of_the_inequality_operator) {
    // Arrange
    ComplexNumber firstEx(13 , 66) , secEx(66 , 13);

    // Assert
    EXPECT_NE(firstEx , secEx);
}
