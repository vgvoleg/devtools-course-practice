// Copyright 2016 Murashov Michael

#include <gtest/gtest.h>
#include <iostream>
#include "include/tstack.hpp"

const int SIZE = 10;

TEST(TStack, check_push_pop_top_of_stack) {
    // Arrange
    TStack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    int extented_value;

    // Assert & Act
    for (int i = SIZE - 1; i >= 0; i--) {
        extented_value = st.top();
        EXPECT_EQ(extented_value, i);
        st.pop();
    }
}

TEST(TStack, can_top_from_empty_stack) {
    // Arrange
    TStack<int> st;

    // Assert & Act
    EXPECT_EQ(st.top(), 0);
}

TEST(TStack, check_overload_equality_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(st == extented_st);
}

TEST(TStack, check_overload_equality_not_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i - 10);
    }

    // Assert & Act
    EXPECT_FALSE(st == extented_st);
}

TEST(TStack, check_overload_equality_by_size) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    extented_st.push(20);

    // Assert & Act
    EXPECT_FALSE(st == extented_st);
}

TEST(TStack, can_create_copy_stack) {
    // Arrange
    TStack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Act
    TStack<int> copy_st(st);

    // Assert
    EXPECT_EQ(st, copy_st);
}

TEST(TStack, check_overload_not_equality_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    // Assert & Act
    EXPECT_FALSE(st != extented_st);
}

TEST(TStack, check_overload_not_equality_not_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st != extented_st);
}

TEST(TStack, check_overload_not_equality_by_size) {
    // Arrange
    TStack<int> st;
    TStack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    extented_st.push(20);

    // Assert & Act
    EXPECT_TRUE(st != extented_st);
}

TEST(TStack, check_overload_assignment) {
    // Arrange
    TStack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    TStack<int> extented_st;

    // Act
    extented_st = st;

    // Assert
    EXPECT_EQ(st, extented_st);
}

TEST(TStack, can_get_size_of_stack) {
    // Arrange
    TStack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Assert & Act
    EXPECT_EQ(SIZE, st.getSize());
}

TEST(TStack, check_empty_of_stack) {
    // Arrange
    TStack<int> st;

    // Assert & Act
    EXPECT_TRUE(st.empty());
}

TEST(TStack, check_not_empty_of_stack) {
    // Arrange
    TStack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Assert & Act
    EXPECT_FALSE(st.empty());
}

TEST(TStack, check_overload_more_data) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(more_st > st);
}

TEST(TStack, check_overload_more_size) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    more_st.push(10);

    // Assert & Act
    EXPECT_TRUE(more_st > st);
}

TEST(TStack, check_overload_less_data) {
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st < more_st);
}

TEST(TStack, check_overload_less_size) {
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    more_st.push(10);

    // Assert & Act
    EXPECT_TRUE(st < more_st);
}

TEST(TStack, check_overload_more_and_equal_not_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(more_st >= st);
}

TEST(TStack, check_overload_more_and_equal_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(more_st >= st);
}

TEST(TStack, check_overload_less_and_equal_not_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st <= more_st);
}

TEST(TStack, check_overload_less_and_equal_identical) {
    // Arrange
    TStack<int> st;
    TStack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(st <= more_st);
}

TEST(TStack, check_overload_plus) {
    // Arrange
    TStack<int> st_1;
    TStack<int> st_2;
    for (int i = 0; i < SIZE; i++) {
        st_1.push(i);
        st_2.push(i + 10);
    }

    int extented_value;

    // Act
    TStack<int> plus_st(st_1 + st_2);

    // Assert
    for (int i = plus_st.getSize() - 1; i >= 0; i--) {
        extented_value = plus_st.top();
        EXPECT_EQ(extented_value, i);
        plus_st.pop();
    }
}

TEST(TStack, can_swap_two_stacks) {
    // Arrange
    TStack<int> st_1;
    TStack<int> st_2;

    // now st_1 < st_2
    for (int i = 0; i < SIZE; i++) {
        st_1.push(i);
        st_2.push(i + 10);
    }

    // Act
    swap_st(&st_1, &st_2);

    // Assert
    EXPECT_TRUE(st_1 > st_2);
}
