// Copyright 2016 Goncharova Svetlana

#include <gtest/gtest.h>

#include "include\pars.h"

TEST(Parser, Can_Create_Parser) {
    // Arrange
    Parser* ptrParser;

    // Act
    ptrParser = new Parser("32+21");

    // Assert
    EXPECT_NE(nullptr, ptrParser);
}
