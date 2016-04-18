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

    // Free memory
    delete item;
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

TEST(TODOitem, Can_Compare_Items_Title) {
    // Arrange
    TODOitem item1;
    TODOitem item2;

    // Act
    item1.setTitle("abc");
    item2.setTitle("def");

    // Assert
    EXPECT_FALSE(item1 == item2);
}

TEST(TODOitem, Can_Compare_Items_Text) {
    // Arrange
    TODOitem item1;
    TODOitem item2;

    // Act
    item1.setText("abc");
    item2.setText("def");

    // Assert
    EXPECT_FALSE(item1 == item2);
}

TEST(TODOitem, Can_Compare_Items_Priority) {
    // Arrange
    TODOitem item1;
    TODOitem item2;

    // Act
    item1.setPriority(1);
    item2.setPriority(2);

    // Assert
    EXPECT_FALSE(item1 == item2);
}

TEST(TODOitem, Returns_Error_Code_When_Inc_Invalid_Priority) {
    // Arrange
    TODOitem item1;
    int err;

    // Act
    item1.setPriority(0);
    err = item1.increasePriority();

    // Assert
    EXPECT_NE(0, err);
}

TEST(TODOitem, Returns_Error_Code_When_Dec_Invalid_Priority) {
    // Arrange
    TODOitem item1;
    int err;

    // Act
    item1.setPriority(5);
    err = item1.decreasePriority();

    // Assert
    EXPECT_NE(0, err);
}

TEST(TODOitem, Returns_Error_Code_When_Set_Invalid_Priority) {
    // Arrange
    TODOitem item1;
    int err;

    // Act
    err = item1.setPriority(100500);

    // Assert
    EXPECT_NE(0, err);
}

