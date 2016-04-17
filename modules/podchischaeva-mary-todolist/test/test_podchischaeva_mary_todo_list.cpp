// Copyright 2016 Podchischaeva Mary

#include <gtest/gtest.h>

#include "TODOlist.h"

TEST(TODOitem, Can_Create) {
    // Arrange
    TODOlist* list;

    // Act
    list = new TODOlist();

    // Assert
    EXPECT_NE(nullptr, list);
}

TEST(TODOitem, Can_AddByItem) {
    // Arrange
    TODOitem item;
    TODOlist list;

    item.setTitle("abc");

    // Act
    list.add(item);

    // Assert
    EXPECT_EQ(1, item.getPriority());
}

TEST(TODOitem, Can_WrongPrioritySet) {
    // Arrange
    TODOitem item;

    // Act
    item.setPriority(-1);

    // Assert
    EXPECT_EQ(TODOitem::DEFAULT_PRIORITY_VALUE, item.getPriority());
}

TEST(TODOitem, Can_TitleSetGet) {
    // Arrange
    TODOitem item;

    // Act
    item.setTitle("abc");

    // Assert
    EXPECT_EQ("abc", item.getTitle());
}

TEST(TODOitem, Can_TextSetGet) {
    // Arrange
    TODOitem item;

    // Act
    item.setText("abc");

    // Assert
    EXPECT_EQ("abc", item.getText());
}

TEST(TODOitem, Can_IncreasePriority) {
    // Arrange
    TODOitem item;
    int expected_priority = TODOitem::DEFAULT_PRIORITY_VALUE - 1;

    // Act
    item.increasePriority();

    // Assert
    EXPECT_EQ(expected_priority, item.getPriority());
}

TEST(TODOitem, Can_DecreasePriority) {
    // Arrange
    TODOitem item;
    int expected_priority = TODOitem::DEFAULT_PRIORITY_VALUE + 1;

    // Act
    item.decreasePriority();

    // Assert
    EXPECT_EQ(expected_priority, item.getPriority());
}

