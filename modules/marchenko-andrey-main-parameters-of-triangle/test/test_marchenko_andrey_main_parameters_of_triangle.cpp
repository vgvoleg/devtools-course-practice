// Copyright 2016 Marchenko Andrey
#include <gtest/gtest.h>
#include "math.h"
#include "include/Triangle.h"

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Rectangular_Triangle) {
    // Arrange
    point A(0, 0);
    point B(3, 3);
    point C(3, 0);

    // Act
    Triangle T(A,B,C);
    double ab = T.triangle_side_length(A,B);
    double ac = T.triangle_side_length(A,C);
    double bc = T.triangle_side_length(B,C);

    // Assert
    EXPECT_DOUBLE_EQ(ab, 3*pow(2,0.5));
    EXPECT_DOUBLE_EQ(ac, 3);
    EXPECT_DOUBLE_EQ(bc, 3);
}

