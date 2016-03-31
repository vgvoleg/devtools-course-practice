// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Petrov_Kirill_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    ComplexNumber z1(5, 3);
    ComplexNumber z2(0, 0);

    // Act & Assert
    EXPECT_ANY_THROW(z1/z2);
}

TEST(Petrov_Kirill_ComplexNumberTest, Can_Division_And_Multiplication_Complex) {
    // Arrange
    ComplexNumber z1(5.0, 1.0);
    ComplexNumber z2(3.0, 5.0);
    ComplexNumber z3(0.0, 2.0);

    // Act
    ComplexNumber z = z1*z2/z3;

    // Assert
    ComplexNumber expected_z(14.0, -5.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Petrov_Kirill_ComplexNumberTest, Can_Associativity_Complex) {
    // Arrange
    ComplexNumber z1(5.0, 1.0);
    ComplexNumber z2(3.0, 5.0);
    ComplexNumber z3(0.0, 2.0);

    // Act
    ComplexNumber z = z1*(z2*z3);

    // Assert
    ComplexNumber expected_z=(z1*z2)*z3;
    EXPECT_EQ(expected_z, z);
}

TEST(Petrov_Kirill_ComplexNumberTest, Can_Summarize_The_Many_Complex) {
    // Arrange
    ComplexNumber z(1.0, 1.0);

    // Act
    ComplexNumber z_res;
    const unsigned N = 1000;
    for (unsigned i = 0; i < N; i++)
        z_res = z_res+z;

    // Assert
    ComplexNumber expected_z(1000.0, 1000.0);
    EXPECT_EQ(expected_z, z_res);
}

TEST(Petrov_Kirill_ComplexNumberTest, Can_Perform_Power_Of_A_Power_Property) {
    auto power=[](const ComplexNumber& index, const unsigned pow) {
       ComplexNumber res(1.0, 0.0);
       for (unsigned i = 0; i < pow; i++)
           res = res*index;
       return res;
    };
    // Arrange
    ComplexNumber z(5.0, 3.0);

    // Act & Assert
    const unsigned N = 3, M = 5;
    // (z^n)^m == z^(m*n) ?
    EXPECT_EQ(power(power(z, N), M), power(z, N*M));
}
