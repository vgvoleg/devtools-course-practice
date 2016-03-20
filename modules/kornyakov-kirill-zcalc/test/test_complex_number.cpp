// Copyright 2014 Gladilov Gleb

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

class ComplexTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(ComplexTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange & Act
    double testReal = 26.0;
    double testImaginary = 20.0;
    ComplexNumber test(testReal, testImaginary);

    // Assert
    EXPECT_NEAR(testReal, test.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(testImaginary, test.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Create_Via_Copying) {
    // Arrange
    double testReal = 26.0;
    double testImaginary = 20.0;
    ComplexNumber test(testReal, testImaginary);

    // Act
    ComplexNumber tested = test;

    // Assert
    EXPECT_NEAR(testReal, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(testImaginary, tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Set_Real) {
    // Arrange
    ComplexNumber test;
    double testReal = 20.0;

    // Act
    test.setReal(testReal);

    // Assert
    EXPECT_NEAR(testReal, test.getReal(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Set_Imaginary) {
    // Arrange
    ComplexNumber test;
    double testImaginary = 26.0;

    // Act
    test.setImaginary(testImaginary);

    // Assert
    EXPECT_NEAR(testImaginary, test.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Add_Complex) {
    // Arrange
    double testReal = 26.0;
    double testImaginary = 14.0;

    double testedReal = 1.0;
    double testedImaginary = 7.0;

    ComplexNumber test(testReal, testImaginary);
    ComplexNumber tested(testedReal, testedImaginary);

    // Act
    tested = tested + test;

    // Assert
    EXPECT_NEAR(27.0, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(21.0, tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Difference_Complex) {
    // Arrange
    double testReal = 26.0;
    double testImaginary = 14.0;

    double testedReal = 1.0;
    double testedImaginary = 1.0;

    ComplexNumber test(testReal, testImaginary);
    ComplexNumber tested(testedReal, testedImaginary);

    // Act
    tested = tested - test;

    // Assert
    EXPECT_NEAR(-25.0, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(-13.0, tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Multiplication_Complex) {
    // Arrange
    double testReal = 5.0;
    double testImaginary = 3.0;

    double testedReal = 4.0;
    double testedImaginary = 6.0;

    ComplexNumber test(testReal, testImaginary);
    ComplexNumber tested(testedReal, testedImaginary);

    // Act
    tested = tested * test;

    // Assert
    EXPECT_NEAR(2.0, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(42.0, tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Division_Complex) {
    // Arrange
    double testReal = 15.0;
    double testImaginary = 20.0;

    double testedReal = 27.0;
    double testedImaginary = 30.0;

    ComplexNumber test(testReal, testImaginary);
    ComplexNumber tested(testedReal, testedImaginary);

    // Act
    tested = tested / test;

    // Assert
    EXPECT_NEAR(1.608, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(-0.144, tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    double testReal = 0.0;
    double testImaginary = 0.0;

    double testedReal = 26.0;
    double testedImaginary = 14.0;

    ComplexNumber test(testReal, testImaginary);
    ComplexNumber tested(testedReal, testedImaginary);

    // Act & Assert
    EXPECT_THROW(tested / test, std::string);
}
