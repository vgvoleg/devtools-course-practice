// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix_determenant.h"

using std::invalid_argument;
using std::vector;

TEST(Correct_work, Right_work_of_empty_constr) {

    // Arrange
    int n=2;
    vector<int> v = {0,0,0,0};

    // Act
    Matrix m = Matrix(n);
    // Assert
    EXPECT_EQ (m.p_m, v);
}

TEST(Correct_work, Right_work_of_constr_with_vector) {

    // Arrange
    int n=2;
    vector<int> v = {1,8,1,5};

    // Act
    Matrix m = Matrix(n,v);
    // Assert
    EXPECT_EQ (m.p_m, v);
}

TEST(Correct_work, Right_work_of_get) {

    // Arrange
    int n=2;
    vector<int> v = {1,8,1,5};
    Matrix m = Matrix(n,v);

    // Act
    int x00 = m.Get(0,0);
    int x11 = m.Get(1,1);
    int x01 = m.Get(0,1);
    int x10 = m.Get(1,0);
    // Assert
    EXPECT_EQ (x00, 1);
    EXPECT_EQ (x01, 8);
    EXPECT_EQ (x10, 1);
    EXPECT_EQ (x11, 5);
}