// Copyright 2016 Kochetova Dasha

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kochetova_Dasha_ComplexNumberTest, can_create_object_without_parameters) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z;

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kochetova_Dasha_ComplexNumberTest, check_result_equality_operator) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(20.0, 30.0);

    // Act
    z1 = z2;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Kochetova_Dasha_ComplexNumberTest, can_compare_objects) {
    // Arrange
    ComplexNumber z1(10.0, 2.0);
    ComplexNumber z2(z1);

    // Act
    bool result = (z1 == z2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Kochetova_Dasha_ComplexNumberTest, can_calculate_arithmetic_expressions) {
    // Arrange
    ComplexNumber z1(1.0, -1.0);
    ComplexNumber z2(2.0, 2.0);
    ComplexNumber z3(3.0, 5.0);

    // Act
    ComplexNumber result = (z1 + z2)*z3;

    // Assert
    ComplexNumber expected_z(4.0, 18.0);
    EXPECT_EQ(expected_z, result);
}

TEST(Kochetova_Dasha_ComplexNumberTest, can_get_big_sum) {
    // Arrange
    ComplexNumber z(1.0, 1.0);
    ComplexNumber result;

    // Act
    for (int i = 0; i < 1000; i++) {
        result = result + z;
    }

    // Assert
    ComplexNumber expected_z(1000.0, 1000.0);
    EXPECT_EQ(result, expected_z);
}
