// Copyright 2016 Podchischaeva Mary

#include <gtest/gtest.h>

#include "TODOitem.h"

TEST(TODOitem, Can_Create) {
    // Arrange
    TODOitem* item;

    // Act
    item = new TODOitem();

    // Assert
    EXPECT_NE(nullptr, item);
}

TEST(TODOitem, Can_Priority_Set_Get) {
    // Arrange
    TODOitem item;

    // Act
    item.setPriority(1);

    // Assert
    EXPECT_EQ(1, item.getPriority());
}

TEST(TODOitem, Can_Wrong_Priority_Set) {
    // Arrange
    TODOitem item;

    // Act
    item.setPriority(-1);

    // Assert
    EXPECT_EQ(TODOitem::DEFAULT_PRIORITY_VALUE, item.getPriority());
}

TEST(TODOitem, Can_Title_Set_Get) {
    // Arrange
    TODOitem item;

    // Act
    item.setTitle("abc");

    // Assert
    EXPECT_EQ("abc", item.getTitle());
}

TEST(TODOitem, Can_Text_Set_Get) {
    // Arrange
    TODOitem item;

    // Act
    item.setText("abc");

    // Assert
    EXPECT_EQ("abc", item.getText());
}

TEST(TODOitem, Can_Increase_Priority) {
    // Arrange
    TODOitem item;
    int expected_priority = TODOitem::DEFAULT_PRIORITY_VALUE - 1;

    // Act
    item.increasePriority();

    // Assert
    EXPECT_EQ(expected_priority, item.getPriority());
}

TEST(TODOitem, Can_Decrease_Priority) {
    // Arrange
    TODOitem item;
    int expected_priority = TODOitem::DEFAULT_PRIORITY_VALUE + 1;

    // Act
    item.decreasePriority();

    // Assert
    EXPECT_EQ(expected_priority, item.getPriority());
}

