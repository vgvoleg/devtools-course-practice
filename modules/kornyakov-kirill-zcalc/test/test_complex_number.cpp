// Copyright 2016 Kornyakov Kirill

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

class ComplexTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(ComplexTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange
    double re = 26.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_NEAR(re, z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(im, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Create_Via_Copying) {
    // Arrange
    double re = 26.0;
    double im = 20.0;
    ComplexNumber z(re, im);

    // Act
    ComplexNumber expected_z = z;

    // Assert
    EXPECT_NEAR(re, expected_z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(im, expected_z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Set_Real) {
    // Arrange
    ComplexNumber z;
    double re = 20.0;

    // Act
    z.setRe(re);

    // Assert
    EXPECT_NEAR(re, z.getRe(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Set_Imaginary) {
    // Arrange
    ComplexNumber z;
    double im = 26.0;

    // Act
    z.setIm(im);

    // Assert
    EXPECT_NEAR(im, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Add_Complex) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 7.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_NEAR(27.0, z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(21.0, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Difference_Complex) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z2 - z1;

    // Assert
    EXPECT_NEAR(-25.0, z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(-13.0, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Multiplication_Complex) {
    // Arrange
    ComplexNumber z1(5.0, 3.0);
    ComplexNumber z2(4.0, 6.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_NEAR(2.0,  z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(42.0, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Division_Complex) {
    // Arrange
    ComplexNumber z1(15.0, 20.0);
    ComplexNumber z2(27.0, 30.0);

    // Act
    ComplexNumber z = z2 / z1;

    // Assert
    EXPECT_NEAR(1.608,  z.getRe(), ComplexTest::epsilon);
    EXPECT_NEAR(-0.144, z.getIm(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(26.0, 14.0);

    // Act & Assert
    EXPECT_THROW(z2 / z1, std::string);
}
