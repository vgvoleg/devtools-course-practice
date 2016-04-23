// Copyright 2016 Hramov Ilya

#include <gtest/gtest.h>
#include <math.h>

#include "include/quaternion.h"

TEST(Quaternion, Can_Create_Default) {
    // Arrange
    Quaternion quat;

    // Act

    // Assert
    EXPECT_EQ(quat.x, 0.0);
    EXPECT_EQ(quat.y, 0.0);
    EXPECT_EQ(quat.z, 0.0);
    EXPECT_EQ(quat.w, 0.0);
}

TEST(Quaternion, Can_Create_Parameterized) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_EQ(quat.x, 1.0);
    EXPECT_EQ(quat.y, 2.0);
    EXPECT_EQ(quat.z, 3.0);
    EXPECT_EQ(quat.w, 4.0);
}

TEST(Quaternion, Can_Compare_Itself) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_TRUE(quat == quat);
}

TEST(Quaternion, Can_Compare_Equal) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_TRUE(quat1 == quat2);
}

TEST(Quaternion, Can_Compare_Inequal) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act

    // Assert
    EXPECT_TRUE(quat1 != quat2);
}

TEST(Quaternion, Can_Add) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    Quaternion result = quat1 + quat2;

    // Assert
    Quaternion expect(5.0, 5.0, 5.0, 5.0);
    EXPECT_TRUE(result == expect);
}

TEST(Quaternion, Can_Subtract) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    Quaternion result = quat1 - quat2;

    // Assert
    Quaternion expect(-3.0, -1.0, 1.0, 3.0);
    EXPECT_TRUE(result == expect);
}

TEST(Quaternion, Can_Assign_Add) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 += quat2;

    // Assert
    Quaternion expect(5.0, 5.0, 5.0, 5.0);
    EXPECT_TRUE(quat1 == expect);
}

TEST(Quaternion, Can_Assign_Subtract) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 -= quat2;

    // Assert
    Quaternion expect(-3.0, -1.0, 1.0, 3.0);
    EXPECT_TRUE(quat1 == expect);
}

TEST(Quaternion, Can_Multiply) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 *= quat2;

    // Assert
    Quaternion expect(12.0, 24.0, 6.0, -12.0);
    EXPECT_TRUE(quat1 == expect);
}

TEST(Quaternion, Can_Conjugate) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = !quat;

    // Assert
    Quaternion expect(-1.0, -2.0, -3.0, 4.0);
    EXPECT_TRUE(result == expect);
}

TEST(Quaternion, Can_Inverse) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = ~quat;

    // Assert
    double coeff = 1.0 / (1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    Quaternion expect(-1.0 * coeff, -2.0 * coeff, -3.0 * coeff, 4.0 * coeff);
    EXPECT_TRUE(result == expect);
}

TEST(Quaternion, Can_Calculate_Magnitude) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    double result = quat.magnitude();

    // Assert
    double expect = sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    EXPECT_EQ(expect, result);
}

TEST(Quaternion, Can_Calculate_Quad_Magnitude) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    double result = quat.qmagnitude();

    // Assert
    double expect = (1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    EXPECT_EQ(expect, result);
}

TEST(Quaternion, Can_Normalize) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = quat.normalized();

    // Assert
    double coeff = 1.0 / sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    Quaternion expect(1.0 * coeff, 2.0 * coeff, 3.0 * coeff, 4.0 * coeff);
    EXPECT_TRUE(expect == result);
}
