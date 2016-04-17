// Copyright 2016 Podchischaeva Mary

#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

#include "TODOlist.h"

using std::vector;

TEST(TODOlist, Can_Create) {
    // Arrange
    TODOlist* list;

    // Act
    list = new TODOlist();

    // Assert
    EXPECT_NE(nullptr, list);
}

TEST(TODOlist, Can_Add_By_Item) {
    // Arrange
    TODOitem item;
    TODOlist list;

    item.setTitle("abc");

    // Act
    list.addItem(item);

    // Assert
    EXPECT_NE(-1, list.search("abc"));
}

TEST(TODOlist, Can_Add_By_Title) {
    // Arrange
    TODOlist list;

    // Act
    list.addItem("abc");

    // Assert
    EXPECT_NE(-1, list.search("abc"));
}

TEST(TODOlist, Can_Get_Size) {
    // Arrange
    TODOlist list;

    // Act
    list.addItem("abc");

    // Assert
    EXPECT_EQ(1, list.size());
}

TEST(TODOlist, Can_Get_Item) {
    // Arrange
    TODOlist list;

    // Act
    list.addItem("abc");
    list.addItem("defg");
    list.addItem("higk");

    // Assert
    EXPECT_EQ(list.getItem(1).getTitle(), "defg");
}

TEST(TODOlist, Throws_When_Get_By_Invalid_Pos) {
    // Arrange
    TODOlist list;

    // Act & Assert
    EXPECT_THROW(list.getItem(100500), std::out_of_range);
}

TEST(TODOlist, Can_Get_All) {
    // Arrange
    TODOlist list;
    vector<TODOitem> v;
    TODOitem temp;

    // Act
    temp.setTitle("abc");
    list.addItem(temp);
    v.push_back(temp);

    temp.setTitle("def");
    list.addItem(temp);
    v.push_back(temp);

    temp.setTitle("gik");
    list.addItem(temp);
    v.push_back(temp);

    EXPECT_TRUE(list.getItem(0) == v[0]);
    EXPECT_TRUE(list.getItem(1) == v[1]);
    EXPECT_TRUE(list.getItem(2) == v[2]);
    EXPECT_TRUE(list.getAll() == v);

    // Assert
    EXPECT_EQ(list.getAll(), v);
}

TEST(TODOlist, Can_Get_By_Priority) {
    // Arrange
    TODOlist list;
    vector<TODOitem> v;
    TODOitem temp;

    // Act
    temp.setTitle("abc");
    temp.setPriority(1);
    list.addItem(temp);
    v.push_back(temp);

    temp.setTitle("def");
    temp.setPriority(2);
    list.addItem(temp);

    temp.setTitle("gik");
    temp.setPriority(1);
    list.addItem(temp);
    v.push_back(temp);

    // Assert
    EXPECT_EQ(list.getByPriority(1), v);
}

TEST(TODOlist, Can_Save_Load) {
    // Arrange
    TODOlist listForSave, listForLoad;
    vector<TODOitem> v;
    TODOitem temp;

    // Act
    temp.setTitle("abc");
    temp.setPriority(1);
    listForSave.addItem(temp);
    v.push_back(temp);

    temp.setTitle("def");
    temp.setPriority(2);
    listForSave.addItem(temp);
    v.push_back(temp);

    temp.setTitle("gik");
    temp.setPriority(1);
    listForSave.addItem(temp);
    v.push_back(temp);

    listForSave.save("todo.list");
    listForLoad.load("todo.list");

    // Assert
    EXPECT_EQ(listForLoad.getAll(), v);
}

TEST(TODOlist, Can_Delete_By_Pos) {
    // Arrange
    TODOlist list;
    vector<TODOitem> v;
    TODOitem temp;

    // Act
    temp.setTitle("abc");
    temp.setPriority(1);
    list.addItem(temp);
    v.push_back(temp);

    temp.setTitle("def");
    temp.setPriority(2);
    list.addItem(temp);

    temp.setTitle("gik");
    temp.setPriority(1);
    list.addItem(temp);
    v.push_back(temp);

    list.deleteItem(1);

    // Assert
    EXPECT_EQ(list.getAll(), v);
}

TEST(TODOlist, Throws_When_Delete_By_Invalid_Pos) {
    // Arrange
    TODOlist list;

    // Act
    list.addItem("abc");

    // Act & Assert
    EXPECT_THROW(list.deleteItem(100500), std::out_of_range);
}
