// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix.h"

using std::invalid_argument;
using std::vector;

TEST(MatrixTest, Can_Create_Empty_Matrix) {
    // Arrange
    int n = 2;
    vector<int> v = {0, 0, 0, 0};
    // Act
    Matrix m = Matrix(n);
    // Assert
    EXPECT_EQ(m.matrix, v);
}

TEST(MatrixTest, Throws_Count_Negative_In_Empty_Matrix) {
    // Arrange
    int n = -2;
    // Act&Assert
    EXPECT_THROW(Matrix m(n), std::invalid_argument);
}

TEST(MatrixTest, Can_Create_Matrix_From_Vector) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    // Act
    Matrix m = Matrix(n, v);
    // Assert
    EXPECT_EQ(m.matrix, v);
}

TEST(MatrixTest, Throws_Count_Negative_In_Marix) {
    // Arrange
    int n = -2;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Throws_Vecor_More_Size_In_Marix) {
    // Arrange
    int n = 1;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Throws_Vecor_Less_Size_In_Marix) {
    // Arrange
    int n = 5;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Can_Make_First_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {5, 3, 6, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 0);
    v = res.matrix;
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(MatrixTest, Can_Make_Second_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {1, 3, 4, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 1);
    v = res.matrix;
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(MatrixTest, Throws_Incorrect_Row_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(0, 4), std::out_of_range);
}
