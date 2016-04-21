// Copyright 2016 Litsov Alex

#include <gtest/gtest.h>

#include <string>
#include "include/BinaryTree.h"

TEST(Element, Can_Create_Correctly) {
    // Arrange
    Element* a;
    Element parent, right, left;

    // Act
    a = new Element(5, "hello", &parent, &right, &left);

    // Assert
    ASSERT_EQ(5, a->getKey());
    ASSERT_EQ("hello", a->getValue());
    ASSERT_EQ(&parent, a->getParent());
    ASSERT_EQ(&right, a->getRight());
    ASSERT_EQ(&left, a->getLeft());
}

TEST(Element, Can_Make_Copy) {
    // Arrange
    Element* a;
    Element* b;

    // Act
    a = new Element(5, "hello");
    b = new Element(*a);

    // Assert
    ASSERT_EQ(5, b->getKey());
    ASSERT_EQ("hello", b->getValue());
}

TEST(Element, Can_Get_Key) {
    // Arrange
    Element a(5);

    // Act & Assert
    ASSERT_EQ(5, a.getKey());
}

TEST(Element, Can_Set_Key) {
    // Arrange
    Element a(5, "eu");

    // Act
    a.setKey(12);

    // Assert
    ASSERT_EQ(12, a.getKey());
}

TEST(Element, Can_Get_Value) {
    // Arrange
    Element a(5, "hello123");

    // Act & Assert
    ASSERT_EQ("hello123", a.getValue());
}

TEST(Element, Can_Set_Value) {
    // Arrange
    Element a(5, "eu");

    // Act
    a.setValue("abcde");

    // Assert
    ASSERT_EQ("abcde", a.getValue());
}

TEST(Element, Can_Set_Right) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.setRight(&b);

    // Assert
    ASSERT_EQ(&b, a.getRight());
}

TEST(Element, Can_Get_Right) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", 0, &a);

    // Act & Assert
    ASSERT_EQ(&a, b.getRight());
}

TEST(Element, Can_Set_Left) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.setLeft(&b);

    // Assert
    ASSERT_EQ(&b, a.getLeft());
}

TEST(Element, Can_Get_Left) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", 0, 0, &a);

    // Act & Assert
    ASSERT_EQ(&a, b.getLeft());
}

TEST(Element, Can_Set_Parent) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.setParent(&b);

    // Assert
    ASSERT_EQ(&b, a.getParent());
}

TEST(Element, Can_Get_Parent) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", &a);

    // Act & Assert
    ASSERT_EQ(&a, b.getParent());
}

TEST(BinaryTree, Can_Create_Correctly) {
    // Arrange
    Element* a = new Element(5, "e1");

    // Act
    BinaryTree Tree(a);

    // Assert
    ASSERT_EQ(a, Tree.getRoot());
}

TEST(BinaryTree, Can_Insert_Element) {
    // Arrange
    Element a(5), b(3), c(7), d(6);
    BinaryTree Tree(&a);

    // Act
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);

    // Assert
    ASSERT_EQ(d.getKey(), Tree.getRoot()->getRight()->getLeft()->getKey());
}

TEST(BinaryTree, Can_Get_Order_By_Keys) {
    // Arrange
    Element a(5), b(3), c(7), d(6);
    BinaryTree Tree(&a);

    // Act
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);

    // Assert
    ASSERT_EQ("3 5 6 7 ", Tree.getKeysOrder());
}

TEST(BinaryTree, Can_Get_Values_Order_By_Keys) {
    // Arrange
    Element a(5, "5"), b(3, "3"), c(7, "3"), d(6, "6");
    BinaryTree Tree(&a);

    // Act
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);

    // Assert
    ASSERT_EQ("3 5 6 7 ", Tree.getValuesOrderByKeys());
}

TEST(BinaryTree, Can_Make_Copy) {
    // Arrange
    Element a(5, "5"), b(3, "3"), c(7, "3"), d(6, "6");
    BinaryTree Tree1(&a);
    Tree1.insertElem(&b);
    Tree1.insertElem(&c);
    Tree1.insertElem(&d);

    // Act
    BinaryTree Tree2(Tree1);

    // Assert
    ASSERT_EQ("3 5 6 7", Tree2.getKeysOrder());
    ASSERT_EQ("3 5 6 7", Tree2.getValuesOrderByKeys());
}

TEST(BinaryTree, Can_Do_Assignment) {
    // Arrange
    Element a(2, "2"), b(13, "13"), c(4, "4"), d(5, "5");
    BinaryTree Tree1(&a);
    Tree1.insertElem(&b);
    Tree1.insertElem(&c);
    Tree1.insertElem(&d);

    // Act
    BinaryTree Tree2 = Tree1;

    // Assert
    ASSERT_EQ("2 4 5 13", Tree2.getKeysOrder());
    ASSERT_EQ("2 4 5 13", Tree2.getValuesOrderByKeys());
}

TEST(BinaryTree, Can_Search_By_Key) {
    // Arrange
    Element a(12), b(15), c(132), d(1), e(13);
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);

    // Act
    Element* match = Tree.searchByKey(c.getKey());

    // Assert
    ASSERT_EQ(match->getKey(), c.getKey());
}

TEST(BinaryTree, Can_Search_By_Value) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);

    // Act
    Element* match = Tree.searchByValue(d.getValue());

    // Assert
    ASSERT_EQ(match->getValue(), d.getValue());
}

TEST(BinaryTree, Can_Get_Min_By_Key) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);

    // Act
    Element* match = Tree.getMinByKey();

    // Assert
    ASSERT_EQ(match->getKey(), d.getKey());
}

TEST(BinaryTree, Can_Get_Max_By_Key) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);

    // Act
    Element* match = Tree.getMaxByKey();

    // Assert
    ASSERT_EQ(match->getKey(), c.getKey());
}

TEST(BinaryTree, Can_Get_Successor) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);
    Element* tmp = Tree.searchByKey(13);

    // Act
    Element* successor = Tree.getSuccessor(tmp);

    // Assert
    ASSERT_EQ(successor->getKey(), b.getKey());
}

TEST(BinaryTree, Can_Get_Predecessor) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.insertElem(&b);
    Tree.insertElem(&c);
    Tree.insertElem(&d);
    Tree.insertElem(&e);
    Element* tmp = Tree.searchByKey(15);

    // Act
    Element* predecessor = Tree.getPredecessor(tmp);

    // Assert
    ASSERT_EQ(predecessor->getKey(), e.getKey());
}
