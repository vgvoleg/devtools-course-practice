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
    int n=1;
    vector<int> v = {1};
    Matrix m(n, v);

    // Act
    double determ = m.Determenant();

    // Assert
    EXPECT_DOUBLE_EQ(determ, 1);
}


TEST(Determenant_properties, Right_value_size_2) {

    // Arrange
        int n=2;
    vector<int> v = {1,2,4,5};
    Matrix m(n, v);

    // Act
    double determ = m.Determenant();

    // Assert
    EXPECT_DOUBLE_EQ(determ, -3);
}


/*TEST(Determenant_properties, Right_value_size_3) {

    // Arrange
    int n=3;
    vector<int> v = {1,2,3,4,5,6,7,8,1};
    Matrix m(n, v);

    // Act
    double determ = m.Determenant();

    // Assert
    EXPECT_DOUBLE_EQ(determ, 24);
}
*/