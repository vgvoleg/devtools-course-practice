// Copyright 2016 Shumihin Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shumihin_Sergey_ComplexNumberTest, Multiplication_Is_Associative) {
    // Arrange
    ComplexNumber cNum1(2.0, 1.0);
    ComplexNumber cNum2(0.0, 5.0);
    ComplexNumber cNum3(5.0, 3.0);

    // Act & Assert
    EXPECT_EQ(cNum1*(cNum2*cNum3), (cNum1*cNum2)*cNum3);
}

TEST(Shumihin_Sergey_ComplexNumberTest, Cant_Divided_By_Zero) {
    // Arrange
    ComplexNumber cNum1(1.0, 2.0);
    ComplexNumber cNum2(0.0, 0.0);

    // Act & Assert
    EXPECT_ANY_THROW(cNum1 / cNum2);
}

TEST(Shumihin_Sergey_ComplexNumberTest, Can_Assign_To_Youself) {
    // Arrange
    ComplexNumber cNum(2.3, 1.0);

    // Act
    cNum = cNum;

    // Assert
    ComplexNumber expected_cNum(2.3, 1.0);
    EXPECT_EQ(expected_cNum, cNum);
}

TEST(Shumihin_Sergey_ComplexNumberTest, Can_Initialize_Using_Int) {
    // Arrange
    ComplexNumber cNum(1, 2);

    // Act & Assert
    ComplexNumber expected_cNum(1.0, 2.0);
    EXPECT_EQ(expected_cNum, cNum);
}

TEST(Shumihin_Sergey_ComplexNumberTest, Can_Use_Multi_Oper_In_One_Line) {
    // Arrange
    ComplexNumber cNum1(2, 1);
    ComplexNumber cNum2(6, 0);
    ComplexNumber cNum3(2, 3);
    ComplexNumber cNum4(3, 2);

    // Act
    ComplexNumber result_cNum = (cNum1 + cNum2) * cNum3 / cNum4;

    // Assert
    ComplexNumber expect_cNum(7, 4);
    EXPECT_EQ(expect_cNum, result_cNum);
}

TEST(Shumihin_Sergey_ComplexNumberTest, Square_Of_Im_Is_Equal_To_Minus_One) {
    // Arrange
    ComplexNumber cNum(0.0, 1.0);

    // Act & Assert
    ComplexNumber expect_cNum(-1.0, 0.0);
    EXPECT_EQ(expect_cNum, cNum * cNum);
}
