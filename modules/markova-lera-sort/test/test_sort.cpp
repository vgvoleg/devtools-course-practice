// Copyright 2016 Markova Lera

#include <gtest/gtest.h>
#include <include/sort.h>

TEST(MySort, Can_Create) {
    // Arrange
    MySort* a;

    // Act
    const int N = 2;
    const int myArr[N] = { 1, 3 };
    a = new MySort(myArr, N);

    // Assert
    EXPECT_NE(nullptr, a);
}

TEST(MySort, Can_Same_Result) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);
    MySort example2(array, N);

    // Act
    const bool expected_true = example == example2;

    // Assert
    EXPECT_TRUE(expected_true);
}

TEST(MySort, Can_Write) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);

    // Act
    const int result_valued = example[9];

    // Assert
    const int expected_value = 100;
    EXPECT_EQ(result_valued, expected_value);
}

TEST(MySort, Can_Do_Gnome_Sort) {
    // Arrange
    const int N = 10;
    const int array[N] = {1, 4, 5, 3, 7, 4, 3, 3, 2, 100};
    MySort example(array, N);

    // Act
    example.gnomeSort();

    // Assert
    const int expected_result[N] = { 1, 2, 3, 3, 3, 4, 4, 5, 7, 100 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}

TEST(MySort, Can_Do_Selection_Sort) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);

    // Act
    example.selectionSort();

    // Assert
    const int expected_result[N] = { 1, 2, 3, 3, 3, 4, 4, 5, 7, 100 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}

TEST(MySort, Can_Do_Paste_Sort) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);

    // Act
    example.pasteSort();

    // Assert
    const int expected_result[N] = { 1, 2, 3, 3, 3, 4, 4, 5, 7, 100 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}

TEST(MySort, Can_Do_Quick_Sort) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);

    // Act
    example.quickSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 2, 3, 3, 3, 4, 4, 5, 7, 100 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}

TEST(MySort, Can_Do_Sheker_Sort) {
    // Arrange
    const int N = 5;
    const int array[N] = { 1, 4, 5, 3, 7 };
    MySort example(array, N);

    // Act
    example.shakerSort(0, N - 1);

    // Assert
    const int expected_result[N] = { 1, 3, 4, 5, 7 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}

TEST(MySort, Can_Do_Merge_Sort) {
    // Arrange
    const int N = 10;
    const int array[N] = { 1, 4, 5, 3, 7, 4, 3, 3, 2, 100 };
    MySort example(array, N);

    // Act
    example.mergeSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 2, 3, 3, 3, 4, 4, 5, 7, 100 };
    const MySort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, example);
}
