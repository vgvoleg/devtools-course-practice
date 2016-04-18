// Copyright 2016 Marchenko Andrey
#include <gtest/gtest.h>
#include "math.h"
#include "include/Triangle.h"

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Default_Triangle){    
    //Arrange
    Triangle T1;    
    
    // Act
    point A(0,0);
    Triangle T2(A, A, A);

    // Assert
    ASSERT_TRUE(T1 == T2);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Triangle_With_Non_Zero_Points){
    //Arrange
    point A_(0, 1);
    point B_(2, 3);
    point C_(4, 5);
    
    // Act
    Triangle T(A_,B_,C_);
    
    // Assert
    ASSERT_TRUE(T.get_A() == A_);
    ASSERT_TRUE(T.get_B() == B_);
    ASSERT_TRUE(T.get_C() == C_);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Triangle_From_Other_Triangle){
    // Arrange
    point A_(0, 1);
    point B_(2, 3);
    point C_(4, 5);
    Triangle T1(A_, B_, C_);
    
    // Act
    Triangle T2(T1);
    
    // Assert
    ASSERT_TRUE(T1 == T2);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_A){
    // Arrange
    Triangle T;
    point A_(1,1);
    
    // Act
    T.set_A(A_);
    
    // Assert
    ASSERT_TRUE(A_==T.get_A());
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_B){
    // Arrange
    Triangle T;
    point B_(1, 1);

    // Act
    T.set_B(B_);
    
    // Assert
    ASSERT_TRUE(B_ == T.get_B());
}

TEST(Marchenko_Andrey_TriangleTest, Can_Set_C){
    // Arrange
    Triangle T;
    point C_(1, 1);
    
    // Act
    T.set_C(C_);
    
    // Assert
    ASSERT_TRUE(C_ == T.get_C());
}

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Zero_Side){
    // Arrange
    Triangle T;

    // Act
    double side=T.triangle_side_length(T.get_A(),T.get_B());
    
    // Assert
    EXPECT_DOUBLE_EQ(side, 0.0);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Treangle_With_Zero_Area){
    // Arrange
    point A(1, 1);
    point B(2, 2);
    point C(3, 3);

    // Act
    Triangle T(A, B, C);
    double area = T.area_of_triangle();

    // Assert
    EXPECT_DOUBLE_EQ(area, 0.0);
}

TEST(Marchenko_Andrey_TriangleTest, Can_Create_Treangle_With_Zero_Perimeter){
    // Arrange
    point A(0, 0);

    // Act
    Triangle T(A, A, A);
    double perimeter = T.perimeter_of_triangle();

    // Assert
    EXPECT_DOUBLE_EQ(perimeter, 0.0);
}

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
