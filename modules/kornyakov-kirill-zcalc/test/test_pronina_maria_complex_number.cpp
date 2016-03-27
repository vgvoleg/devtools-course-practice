// Copyright 2016 Pronina Maria
#include <gtest/gtest.h>

#include "include/complex_number.h"
#include <math.h>

TEST(Pronina_Maria_ComplexNumberTest,
    Imaginary_Number_Square_Is_Negative_Real) {
    // Arrange
    ComplexNumber z(0.0, 1.0);
    //Act
    ComplexNumber square = z * z;
    // Assert 
    ComplexNumber res(-1.0, 0.0);
    EXPECT_TRUE(res == square);
}