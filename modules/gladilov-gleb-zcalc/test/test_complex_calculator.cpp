// Copyright 2014 Gladilov Gleb

#include <gtest/gtest.h>

#include <string>

#include "include/complexcalculator.h"

class ComplexTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(ComplexTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange & Act
    ValueType testReal = static_cast<ValueType>(26);
    ValueType testImaginary = static_cast<ValueType>(20);
    Complex test(testReal, testImaginary);

    // Assert
    EXPECT_NEAR(testReal, test.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(testImaginary, test.getImaginary(), ComplexTest::epsilon);
}
TEST_F(ComplexTest, Can_Create_Via_Copying) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(26);
    ValueType testImaginary = static_cast<ValueType>(20);
    Complex test(testReal, testImaginary);

    // Act
    Complex tested = test;

    // Assert
    EXPECT_NEAR(testReal, tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(testImaginary, tested.getImaginary(), ComplexTest::epsilon);
}
TEST_F(ComplexTest, Can_Set_Real) {
    // Arrange
    Complex test;
    ValueType testReal = static_cast<ValueType>(20);

    // Act
    test.setReal(testReal);

    // Assert
    EXPECT_NEAR(testReal, test.getReal(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Set_Imaginary) {
    // Arrange
    Complex test;
    ValueType testImaginary = static_cast<ValueType>(26);

    // Act
    test.setImaginary(testImaginary);

    // Assert
    EXPECT_NEAR(testImaginary, test.getImaginary(), ComplexTest::epsilon);
}
TEST_F(ComplexTest, Can_Add_Complex) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(26);
    ValueType testImaginary = static_cast<ValueType>(14);

    ValueType testedReal = static_cast<ValueType>(1);
    ValueType testedImaginary = static_cast<ValueType>(7);

    Complex test(testReal, testImaginary);
    Complex tested(testedReal, testedImaginary);

    // Act
    tested = tested + test;

    // Assert
    EXPECT_NEAR(static_cast<ValueType>(27),
                tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(static_cast<ValueType>(21),
                tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Difference_Complex) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(26);
    ValueType testImaginary = static_cast<ValueType>(14);

    ValueType testedReal = static_cast<ValueType>(1);
    ValueType testedImaginary = static_cast<ValueType>(1);

    Complex test(testReal, testImaginary);
    Complex tested(testedReal, testedImaginary);

    // Act
    tested = tested - test;

    // Assert
    EXPECT_NEAR(static_cast<ValueType>(-25),
                tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(static_cast<ValueType>(-13),
                tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Can_Multiplication_Complex) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(5);
    ValueType testImaginary = static_cast<ValueType>(3);

    ValueType testedReal = static_cast<ValueType>(4);
    ValueType testedImaginary = static_cast<ValueType>(6);

    Complex test(testReal, testImaginary);
    Complex tested(testedReal, testedImaginary);

    // Act
    tested = tested * test;

    // Assert
    EXPECT_NEAR(static_cast<ValueType>(2),
                tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(static_cast<ValueType>(42),
                tested.getImaginary(), ComplexTest::epsilon);
}
TEST_F(ComplexTest, Can_Division_Complex) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(15);
    ValueType testImaginary = static_cast<ValueType>(20);

    ValueType testedReal = static_cast<ValueType>(27);
    ValueType testedImaginary = static_cast<ValueType>(30);

    Complex test(testReal, testImaginary);
    Complex tested(testedReal, testedImaginary);

    // Act
    tested = tested / test;

    // Assert
    EXPECT_NEAR(static_cast<ValueType>(1.608),
                tested.getReal(), ComplexTest::epsilon);
    EXPECT_NEAR(static_cast<ValueType>(-0.144),
                tested.getImaginary(), ComplexTest::epsilon);
}

TEST_F(ComplexTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ValueType testReal = static_cast<ValueType>(0);
    ValueType testImaginary = static_cast<ValueType>(0);

    ValueType testedReal = static_cast<ValueType>(26);
    ValueType testedImaginary = static_cast<ValueType>(14);

    Complex test(testReal, testImaginary);
    Complex tested(testedReal, testedImaginary);

    // Act & Assert
    EXPECT_THROW(tested / test, std::string);
}
