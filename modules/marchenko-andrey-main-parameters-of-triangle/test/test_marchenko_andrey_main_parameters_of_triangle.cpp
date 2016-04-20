// Copyright 2016 Marchenko Andrey

#include <math.h>
#include <gtest/gtest.h>
#include "include/Triangle.h"

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Default_Triangle) {
    // Arrange
    Triangle T1;

    // Act
    point A(0.0, 0.0);
    point B(1.0, 1.0);
    point C(1.0, 0.0);
    Triangle T2(A, B, C);

    // Assert
    ASSERT_TRUE(T1 == T2);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Triangle_With_Non_Zero_Points) {
    // Arrange
    point A_(0.0, 1.0);
    point B_(2.0, 4.0);
    point C_(4.0, 5.0);

    // Act
    Triangle T(A_, B_, C_);

    // Assert
    ASSERT_TRUE(T.get_A() == A_ && T.get_B() == B_ && T.get_C() == C_);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Copy_Triangle) {
    // Arrange
    point A_(0.0, 1.0);
    point B_(3.0, 3.0);
    point C_(4.0, 5.0);
    Triangle T1(A_, B_, C_);

    // Act
    Triangle T2(T1);

    // Assert
    ASSERT_TRUE(T1 == T2);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_A) {
    // Arrange
    Triangle T;
    point A_(1.0, 1.0);

    // Act
    T.set_A(A_);

    // Assert
    ASSERT_TRUE(A_ == T.get_A());
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_B) {
    // Arrange
    Triangle T;
    point B_(1.0, 1.0);

    // Act
    T.set_B(B_);

    // Assert
    ASSERT_TRUE(B_ == T.get_B());
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_C) {
    // Arrange
    Triangle T;
    point C_(1.0, 1.0);

    // Act
    T.set_C(C_);

    // Assert
    ASSERT_TRUE(C_ == T.get_C());
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Triangle_With_Non_Zero_Side) {
    // Arrange
    point A(0.0, 1.0);
    point B(3.0, 3.0);
    point C(4.0, 5.0);
    Triangle T(A, B, C);

    // Act
    double side = T.triangle_side_length(T.get_A(), T.get_B());

    // Assert
    EXPECT_FALSE(side == 0.0);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Not_Create_Triangle_When_Two_Points_Are_Idential) {
    // Arrange
    point A(0.0, 1.0);
    point B(0.0, 1.0);
    point C(4.0, 5.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), TwoSamePoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Not_Create_Triangle_When_Three_Points_Are_Idential) {
    // Arrange
    point A(0.0, 1.0);
    point B(0.0, 1.0);
    point C(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), ThreeSamePoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_A_More_Than_B_And_B_More_Than_C) {
    // Arrange
    point A(4.0, 5.0);
    point B(2.0, 3.0);
    point C(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_A_More_Than_C_And_C_More_Than_B) {
    // Arrange
    point A(4.0, 5.0);
    point C(2.0, 3.0);
    point B(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_B_More_Than_A_And_A_More_Than_C) {
    // Arrange
    point B(4.0, 5.0);
    point A(2.0, 3.0);
    point C(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_B_More_Than_C_And_C_More_Than_A) {
    // Arrange
    point B(4.0, 5.0);
    point C(2.0, 3.0);
    point A(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_C_More_Than_B_And_B_More_Than_A) {
    // Arrange
    point C(4.0, 5.0);
    point B(2.0, 3.0);
    point A(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_C_More_Than_A_And_A_More_Than_B) {
    // Arrange
    point C(4.0, 5.0);
    point A(2.0, 3.0);
    point B(0.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_X_Coords_Are_Idential) {
    // Arrange
    point B(4.0, 5.0);
    point C(4.0, 3.0);
    point A(4.0, 1.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Cant_Create_Straight_Line_Triangle_When_Y_Coords_Are_Idential) {
    // Arrange
    point B(4.0, 5.0);
    point C(2.0, 5.0);
    point A(0.0, 5.0);

    // Act and Assert
    EXPECT_THROW(Triangle T(A, B, C), IncorrectPoints);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Treangle_With_Non_Zero_Perimeter) {
    // Arrange
    point A(0.0, 0.0);
    point B(1.0, 3.0);
    point C(4.0, 5.0);

    // Act
    Triangle T(A, B, C);
    double perimeter = T.perimeter_of_triangle();

    // Assert
    EXPECT_FALSE(perimeter == 0.0);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Equilateral_Triangle) {
    // Arrange
    point A(0.0, 0.0);
    point B(1.5, 1.5 * pow(3.0, 0.5));
    point C(3.0, 0.0);
    Triangle T(A, B, C);

    // Act
    double angle_A = T.angle_A_of_triangle_in_radians();
    double angle_B = T.angle_B_of_triangle_in_radians();
    double angle_C = T.angle_C_of_triangle_in_radians();

    // Assert
    ASSERT_TRUE(angle_A == angle_B && angle_B==angle_C);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Isosceles_Triangle) {
    // Arrange
    point A(0.0, 0.0);
    point B(4.0, 4.0);
    point C(4.0, 0.0);
    Triangle T(A, B, C);

    // Act
    double sin_A = T.sin_of_angle(T.angle_A_of_triangle_in_radians());
    double sin_B = T.sin_of_angle(T.angle_B_of_triangle_in_radians());

    // Assert
    ASSERT_TRUE(sin_A == sin_B);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Rectangular_Triangle) {
    // Arrange
    point A(0.0, 0.0);
    point B(3.0, 3.0);
    point C(3.0, 0.0);

    // Act
    Triangle T(A, B, C);
    double cos_C = T.cos_of_angle(T.angle_C_of_triangle_in_radians());

    // Assert
    ASSERT_NEAR(0.0, cos_C, 0.00000000001);
}

TEST(Marchenko_Andrey_TriangleTest,
    Is_Tangens_And_Catangens_0f_45_Degrees_Equal) {
    // Arrange
    point A(0.0, 0.0);
    point B(4.0, 4.0);
    point C(4.0, 0.0);
    Triangle T(A, B, C);

    // Act
    double tan_A = T.tan_of_angle(T.angle_A_of_triangle_in_radians());
    double ctan_A = T.ctan_of_angle(T.angle_A_of_triangle_in_radians());

    // Assert
    ASSERT_NEAR(ctan_A, tan_A, 0.00000000001);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Triangles_With_Equal_Inradius) {
    // Arrange
    point A(0.0, 0.0);
    point B1(2.0, 2.0);
    point B2(2.0, -2.0);
    point C(4.0, 0.0);

    // Act
    Triangle T1(A, B1, C);
    Triangle T2(A, B2, C);
    double inradius1 = T1.inradius();
    double inradius2 = T2.inradius();

    // Assert
    ASSERT_NEAR(inradius1, inradius2, 0.00000000001);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Triangles_With_Equal_Circumradius) {
    // Arrange
    point A(0.0, 0.0);
    point B1(2.0, 2.0);
    point B2(2.0, -2.0);
    point C(4.0, 0.0);

    // Act
    Triangle T1(A, B1, C);
    Triangle T2(A, B2, C);
    double circumradius1 = T1.circumradius();
    double circumradius2 = T2.circumradius();

    // Assert
    ASSERT_NEAR(circumradius1, circumradius2, 0.00000000001);
}

TEST(Marchenko_Andrey_TriangleTest,
    The_Triangle_Inequality_Is_Carried_Out) {
    // Arrange
    point A(1.0, 1.0);
    point B(2.0, 3.0);
    point C(4.0, 5.0);
    Triangle T(A, B, C);

    // Act
    double AB = T.triangle_side_length(T.get_A(), T.get_B());
    double BC = T.triangle_side_length(T.get_B(), T.get_C());
    double AC = T.triangle_side_length(T.get_A(), T.get_C());

    // Assert
    ASSERT_TRUE(AB + BC >= AC && AB + AC >= BC && AC + BC >= AB);
}

TEST(Marchenko_Andrey_TriangleTest,
    Is_The_First_Sign_Of_Triangles_Equalality) {
    // Arrange
    point A(0.0, 0.0);
    point B1(2.0, 3.0);
    point B2(2.0, -3.0);
    point C(4.0, 0.0);
    Triangle T1(A, B1, C);
    Triangle T2(A, B2, C);

    // Act
    double AB1 = T1.triangle_side_length(T1.get_A(), T1.get_B());
    double B1C = T1.triangle_side_length(T1.get_B(), T1.get_C());
    double AB2 = T2.triangle_side_length(T2.get_A(), T2.get_B());
    double B2C = T2.triangle_side_length(T2.get_B(), T2.get_C());
    double angle_of_T1 = T1.angle_B_of_triangle_in_radians();
    double angle_of_T2 = T2.angle_B_of_triangle_in_radians();

    // Assert
    ASSERT_TRUE(AB1 == AB2 && B1C == B2C && angle_of_T1 == angle_of_T2);
}

TEST(Marchenko_Andrey_TriangleTest,
    Is_The_Second_Sign_Of_Triangles_Equalality) {
    // Arrange
    point A(0.0, 0.0);
    point B1(2.0, 3.0);
    point B2(2.0, -3.0);
    point C(4.0, 0.0);
    Triangle T1(A, B1, C);
    Triangle T2(A, B2, C);

    // Act
    double AB1 = T1.triangle_side_length(T1.get_A(), T1.get_B());
    double AB2 = T2.triangle_side_length(T2.get_A(), T2.get_B());
    double A_angle_of_T1 = T1.angle_A_of_triangle_in_radians();
    double A_angle_of_T2 = T2.angle_A_of_triangle_in_radians();
    double B_angle_of_T1 = T1.angle_B_of_triangle_in_radians();
    double B_angle_of_T2 = T2.angle_B_of_triangle_in_radians();

    // Assert
    ASSERT_TRUE(AB1 == AB2 && A_angle_of_T1 ==
        A_angle_of_T2 && B_angle_of_T1 == B_angle_of_T2);
}

TEST(Marchenko_Andrey_TriangleTest,
    Is_The_Third_Sign_Of_Triangles_Equalality) {
    // Arrange
    point A1(0.0, 0.0);
    point B1(2.0, 3.0);
    point C1(4.0, 0.0);
    point A2(1.0, 1.0);
    point B2(3.0, 4.0);
    point C2(5.0, 1.0);
    Triangle T1(A1, B1, C1);
    Triangle T2(A2, B2, C2);

    // Act
    double A1B1 = T1.triangle_side_length(T1.get_A(), T1.get_B());
    double A1B2 = T2.triangle_side_length(T2.get_A(), T2.get_B());
    double B1C1 = T1.triangle_side_length(T1.get_B(), T1.get_C());
    double B2C2 = T2.triangle_side_length(T2.get_B(), T2.get_C());
    double A1C1 = T1.triangle_side_length(T1.get_A(), T1.get_C());
    double A2C2 = T2.triangle_side_length(T2.get_A(), T2.get_C());

    // Assert
    ASSERT_TRUE(A1B1 == A1B2 && B1C1 == B2C2 && A1C1 == A2C2);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Get_Coords_From_Point) {
    // Arrange
    point A(0.0, 0.0);
    point B(2.0, 3.0);
    point C(4.0, 0.0);
    Triangle T(A, B, C);

    // Act
    double A_x = T.get_A_x();
    double A_y = T.get_A_y();
    double B_x = T.get_B_x();
    double B_y = T.get_B_y();
    double C_x = T.get_C_x();
    double C_y = T.get_C_y();

    // Assert
    ASSERT_TRUE(A_x == 0.0 && A_y == 0.0 && B_x == 2.0
        && B_y == 3.0 && C_x == 4.0 && C_y == 0.0);
}

TEST(Marchenko_Andrey_TriangleTest,
    Can_Create_Two_Triangles_With_Small_Difference) {
    // Arrange
    point A1(0.0, 0.0);
    point B1(2.0, 3.0);
    point C1(4.0, 0.0);
    point A2(0.0, 0.0);
    point B2(2.001, 3.0);
    point C2(4.0, 0.0);

    // Act
    Triangle T1(A1, B1, C1);
    Triangle T2(A2, B2, C2);

    // Assert
    ASSERT_FALSE(T1 == T2);
}
