// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/mass_converter.h"

TEST(MassConverter, Can_Create) {
    // Arrange
    MassConverter *a;

    // Act
    a = new MassConverter();

    // Assert
    EXPECT_NE(nullptr, a);
}
