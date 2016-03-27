// Copyright 2016 Hramov Ilya

#include <gtest\gtest.h>
#include "include\complex_number.h"

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Equality) {
    //Arrange
    ComplexNumber z1(1.0, 2.0), z2(1.0, 2.0), z3(1.1, 2.0);

    //Assert
    EXPECT_TRUE(z1 == z2);
    EXPECT_FALSE(z1 == z3);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Compare_For_Inequality) {
    //Arrange
    ComplexNumber z1(1.0, 2.0), z2(1.0, 2.0), z3(1.1, 2.0);

    //Assert
    EXPECT_TRUE(z1 != z3);
    EXPECT_FALSE(z1 != z2);
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Multiply_Not_Extraordinnary_Numbers) {
    //Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0);

    //Act
    ComplexNumber result = z1 * z2;

    //Assert
    EXPECT_DOUBLE_EQ(-5.0, result.getRe());
    EXPECT_DOUBLE_EQ(10.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Add_Not_Extraordinnary_Numbers) {
    //Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0);

    //Act
    ComplexNumber result = z1 + z2;

    //Assert
    EXPECT_DOUBLE_EQ(4.0, result.getRe());
    EXPECT_DOUBLE_EQ(6.0, result.getIm());
}

TEST(Hramov_Ilya_ComplexNumberTest, Can_Subtract_Not_Extraordinnary_Numbers) {
    //Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0);

    //Act
    ComplexNumber result = z1 - z2;

    //Assert
    EXPECT_DOUBLE_EQ(-2.0, result.getRe());
    EXPECT_DOUBLE_EQ(-2.0, result.getIm());
}
