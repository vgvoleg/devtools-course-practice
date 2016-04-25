// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix_determenant.h"

using std::invalid_argument;
using std::vector;

TEST(Correct_work, Right_work_of_incor_empty_constr) {
    // Arrange
    int n = 2;
    vector<int> v = {0, 0, 0, 0};

    // Act
    Matrix m = Matrix(n);
    // Assert
    EXPECT_EQ(m.p_m, v);
}

TEST(Correct_work, Work_of_empty_incor_constr) {
    // Arrange
    int n = -2;
    // Act&Assert
    EXPECT_THROW(Matrix m(n), Incorrect);
}

TEST(Correct_work, Right_work_of_constr_with_vector) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    // Act
    Matrix m = Matrix(n, v);
    // Assert
    EXPECT_EQ(m.p_m, v);
}

TEST(Correct_work, Work_of_constr_with_incor_vector) {
    // Arrange
    int n = -2;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), Incorrect);
}

TEST(Correct_work, Right_work_of_get) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);
    // Act
    int x00 = m.Get(0, 0);
    int x11 = m.Get(1, 1);
    int x01 = m.Get(0, 1);
    int x10 = m.Get(1, 0);
    // Assert
    EXPECT_EQ(x00, 1);
    EXPECT_EQ(x01, 8);
    EXPECT_EQ(x10, 1);
    EXPECT_EQ(x11, 5);
}

TEST(Correct_work, Right_work_of_set) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);
    // Act
    m.Set(0, 0, 100);
    m.Set(1, 1, 19);
    int x00 = m.Get(0, 0);
    int x11 = m.Get(1, 1);
    // Assert
    EXPECT_EQ(x00, 100);
    EXPECT_EQ(x11, 19);
}

TEST(Correct_work, Right_work_of_first_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {5, 3, 6, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 0);
    v = res.p_m;
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(Correct_work, Right_work_of_second_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {1, 4, 3, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 1);
    v = res.p_m;
    // Assert
    EXPECT_EQ(v, minor);
}
