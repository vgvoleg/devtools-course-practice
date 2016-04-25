// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix_determenant.h"

using std::invalid_argument;
using std::vector;

TEST(Koshechkin_vlad, Right_value_of_determenant) {

    // Arrange
        int n=2;
    vector<int> v = {1,2,4,5};
    Matrix m(n, v);

    // Act
    double determ = m.Determenant();

    // Assert
    EXPECT_DOUBLE_EQ(determ, -3);
}

