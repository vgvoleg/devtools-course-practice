// Copyright 2016 Orlov Georgy

#include <gtest\gtest.h>

#include <include\complex_number.h>

TEST(Orlov_Georgy_ComplexNumberTest, squared_img_number_equal_minus_one) {
    // Arrange
    const ComplexNumber z1(0, 1);
    const ComplexNumber z2(-1, 0);
    
    // Act
    ComplexNumber result = z1 * z1;

    // Assert
    EXPECT_EQ(z2, result);
}

TEST(Orlov_Georgy_ComplexNumberTest, addition_is_commutative) {
    // Arrange
    const ComplexNumber z1(10, 15);
    const ComplexNumber z2(6, 12);

    // Act
    ComplexNumber result1 = z1 + z2;
    ComplexNumber result2 = z2 + z1;

    // Assert
    EXPECT_EQ(result1, result2);
}

TEST(Orlov_Georgy_ComplexNumberTest, multiplication_is_commutative) {
    // Arrange
    const ComplexNumber z1(10, 15);
    const ComplexNumber z2(6, 12);

    // Act
    ComplexNumber result1 = z1 * z2;
    ComplexNumber result2 = z2 * z1;

    // Assert
    EXPECT_EQ(result1, result2);
}

TEST(Orlov_Georgy_ComplexNumberTest, expr_with_all_ops_gives_the_correct_result) {
    // Arrange
    const ComplexNumber z1(2, 4);
    const ComplexNumber z2(8, 12);
    const ComplexNumber z3(-6, 5);
    const ComplexNumber z4(8, 12);
    const ComplexNumber z5(1, -1);
    const ComplexNumber expected(-36, 51);

    // Act
    ComplexNumber result = z1 * z2 + z3 - z4 / z5;

    // Assert
    EXPECT_EQ(result, expected);
}

TEST(Orlov_Georgy_ComplexNumberTest, distributivity_check) {
    // Arrange
    const ComplexNumber z1(-2, 5);
    const ComplexNumber z2(6, 4);
    const ComplexNumber z3(8, 1);

    // Act
    ComplexNumber result1 = z1 * (z2 + z3);
    ComplexNumber result2 = (z1 * z2) + (z1 * z3);

    // Assert
    EXPECT_EQ(result1, result2);
}
