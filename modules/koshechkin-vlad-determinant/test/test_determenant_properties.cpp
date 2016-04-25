// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix_determenant.h"

using std::invalid_argument;
using std::vector;

TEST(Determenant_properties, Right_value_size_1) {
    // Arrange
    int n = 1;
    vector<int> v = {1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 1);
}


TEST(Determenant_properties, Right_value_size_2) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 2, 4, 5};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, -3);
}


TEST(Determenant_properties, Right_value_size_3) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 24);
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
TEST(Correct_work, Right_work_of_Minor1) {
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
