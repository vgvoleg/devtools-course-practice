// Copyright 2016 Belyaeva Daria

#include "InterpolationSearch.h"
#include <gtest/gtest.h>

TEST(InterpolSearch, cant_create_object_with_incorrect_size) {
    // Arrange

    // Act & Assert
    EXPECT_ANY_THROW(InterpolSearch(-1));
}

TEST(InterpolSearch, can_create_object_with_correct_size) {
    // Arrange

    // Act & Assert
    EXPECT_NO_THROW(InterpolSearch IS(5));
}

TEST(InterpolSearch, initialization_with_zero_in_construction) {
    // Arrange
    InterpolSearch IS(1);

    // Act & Assert
    EXPECT_EQ(IS[0], 0);
}

TEST(InterpolSearch, can_create_object) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };

    // Act
    InterpolSearch* myIS = new InterpolSearch(myArr, size);

    // Assert
    EXPECT_NE(nullptr, myIS);
}

TEST(InterpolSearch, can_create_object_with_value) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 10 };

    // Act
    InterpolSearch myIS(myArr, size);

    // Assert
    EXPECT_EQ(myIS[0], 10);
}

TEST(InterpolSearch, cant_address_to_negative_number_in_array) {
    // Arrange
    InterpolSearch IS(1);

    // Act & Assert
    EXPECT_ANY_THROW(IS[-1]);
}

TEST(InterpolSearch, cant_address_to_number_bigger_than_size_of_array) {
    // Arrange
    InterpolSearch IS(1);

    // Act & Assert
    EXPECT_ANY_THROW(IS[2]);
}

TEST(InterpolSearch, can_address_to_normal_number_of_element) {
    // Arrange
    InterpolSearch IS(1);

    // Act & Assert
    EXPECT_NO_THROW(IS[0]);
}

TEST(InterpolSearch, can_check_equality) {
    // Arrange
    const int size = 6;
    const int myArr[size] = { 1, 2, 3, 4, 5, 7 };
    InterpolSearch myIS1(myArr, size);
    InterpolSearch myIS2(myArr, size);

    // Act
    const bool expected_true = (myIS1 == myIS2);

    // Assert
    EXPECT_TRUE(expected_true);
}

TEST(InterpolSearch, can_check_inequality_with_different_elements) {
    // Arrange
    const int size = 6;
    const int myArr[size] = { 1, 2, 3, 4, 5, 7 };
    const int myArr2[size] = { 1, 2, 5, 3, 7, 4 };
    InterpolSearch myIS1(myArr, size);
    InterpolSearch myIS2(myArr2, size);

    // Act
    const bool expected_false = (myIS1 == myIS2);

    // Assert
    EXPECT_FALSE(expected_false);
}

TEST(InterpolSearch, can_check_inequality_with_different_size) {
    // Arrange
    const int size1 = 6;
    const int size2 = 5;
    const int myArr[size1] = { 1, 2, 3, 4, 5, 7 };
    const int myArr2[size2] = { 1, 2, 5, 3, 7 };
    InterpolSearch myIS1(myArr, size1);
    InterpolSearch myIS2(myArr2, size2);

    // Act
    const bool expected_false = (myIS1 == myIS2);

    // Assert
    EXPECT_FALSE(expected_false);
}

TEST(InterpolSearch, can_return_size) {
    // Arrange
    InterpolSearch IS(3);

    // Act & Assert
    EXPECT_EQ(IS.GetSize(), 3);
}

TEST(InterpolSearch, can_not_do_quick_sort_wrong_left) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolSearch myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.QuickSort(-1, size - 1));
}

TEST(InterpolSearch, can_not_do_quick_sort_wrong_right) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolSearch myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.QuickSort(-1, size - 1));
}

TEST(InterpolSearch, can_do_quick_sort) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolSearch myIS(myArr, size);

    // Act
    myIS.QuickSort(0, size - 1);

    // Assert
    const int expectedArr[size] = { 1, 2, 3, 4, 5 };
    const InterpolSearch expectedResult(expectedArr, size);
    EXPECT_EQ(expectedResult, myIS);
}

TEST(InterpolSearch, can_do_search_wrong_key) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolSearch myIS(myArr, size);

    // Act
    int tmp = myIS.InterpolationSearch(6);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolSearch, can_do_search) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolSearch myIS(myArr, size);

    // Act
    int tmp = myIS.InterpolationSearch(3);

    // Assert
    EXPECT_EQ(tmp, 2);
}

TEST(InterpolSearch, can_do_search_one_element) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolSearch myIS(myArr, size);

    // Act
    int tmp = myIS.InterpolationSearch(1);

    // Assert
    EXPECT_EQ(tmp, 0);
}

TEST(InterpolSearch, can_do_search_one_element_wrong_key) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolSearch myIS(myArr, size);

    // Act
    int tmp = myIS.InterpolationSearch(3);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolSearch, can_do_search_equal_elements) {
    // Arrange
    const int size = 4;
    const int myArr[size] = { 1, 1, 1, 1 };
    InterpolSearch myIS(myArr, size);

    // Act
    int tmp = myIS.InterpolationSearch(1);

    // Assert
    EXPECT_EQ(tmp, 0);
}

TEST(InterpolSearch, can_not_do_search_in_unsorted_array) {
    // Arrange
    const int size = 4;
    const int myArr[size] = { 1, 2, 5, 3};
    InterpolSearch myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.InterpolationSearch(1));
}
