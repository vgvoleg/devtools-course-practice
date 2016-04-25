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
    vector<int> v = {1, 2,
                     4, 5};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, -3);
}


TEST(Determenant_properties, Right_value_size_3) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 24);
}

TEST(Determenant_properties, Right_value_of_traspon) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};
    vector<int> v2 = {1, 4, 7,
                      2, 5, 8,
                      3, 6, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determenant(m1);
    double determ2 = m2.Determenant(m2);
    // Assert
    EXPECT_DOUBLE_EQ(determ1, determ2);
}

TEST(Determenant_properties, Right_value_double_row) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     1, 2, 3,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determenant_properties, Right_value_multiples_row) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     2, 4, 6,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determenant_properties, Right_value_E_matrix) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 0, 0,
                     0, 1, 0,
                     0, 0, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 1);
}

TEST(Determenant_properties, Right_value_change_rows) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};

    vector<int> v2 = {4, 5, 6,
                      1, 2, 3,
                      7, 8, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determenant(m1);
    double determ2 = m2.Determenant(m2);
    // Assert
    EXPECT_DOUBLE_EQ(determ1, -determ2);
}

TEST(Determenant_properties, Right_value_dependence_matrix) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     -1, -2, -3,
                     0, 0, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determenant(m);
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determenant_properties, Right_value_multiplier_rows) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};

    vector<int> v2 = {2, 4, 6,
                      4, 5, 6,
                      7, 8, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determenant(m1);
    double determ2 = m2.Determenant(m2);
    // Assert
    EXPECT_DOUBLE_EQ(2*determ1, determ2);
}
