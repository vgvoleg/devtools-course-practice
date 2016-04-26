// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix.h"

using std::invalid_argument;
using std::vector;

TEST(Correct_work, Can_Create_Emty_Matrix) {
    // Arrange
    int n = 2;
    vector<int> v = {0, 0, 0, 0};

    // Act
    Matrix m = Matrix(n);
    // Assert
    EXPECT_EQ(m.matrix, v);
}

TEST(Correct_work, Throws_Count_Negative_In_Emty_Matrix) {
    // Arrange
    int n = -2;
    // Act&Assert
    EXPECT_THROW(Matrix m(n), std::invalid_argument);
}

TEST(Correct_work, Can_Create_Matrix_From_Vector) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    // Act
    Matrix m = Matrix(n, v);
    // Assert
    EXPECT_EQ(m.matrix, v);
}

TEST(Correct_work, Throws_Count_Negative_In_Marix) {
    // Arrange
    int n = -2;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(Correct_work, Can_Make_First_Minor) {
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

TEST(Correct_work, Can_Make_Second_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {1, 4, 3, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 1);
    v = res.matrix;
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(Correct_work, Throws_Incorrect_Row_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(0, 4), std::out_of_range);
}
