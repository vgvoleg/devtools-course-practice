// Copyright 2016 Ovcharuk Oleg

#include <gtest/gtest.h>
#include <include/queue.h>

TEST(Queue, cant_create_queue_with_incorrect_size) {
    // Arrange
    // Act
    // Assert
    EXPECT_ANY_THROW(Queue A(-1));
}

TEST(Queue, can_create_queue_with_correct_size) {
    // Arrange
    // Act
    // Assert
    EXPECT_NO_THROW(Queue A(5));
    EXPECT_NO_THROW(Queue B);
}

TEST(Queue, can_add_element) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.put(20, 1), DataOK);
}

TEST(Queue, can_add_several_elements) {
    // Arrange
    Queue A;
    // Act
    bool expect = true;
    for (int i = 0; i < 5; i++) {
        if (A.put(i, 1) == FullQueue)
            expect = false;
    }
    // Assert
    EXPECT_EQ(expect, true);
}

TEST(Queue, cant_add_elem_into_full_queue) {
    // Arrange
    Queue A(5);
    // Act
    for (int i = 0; i < 5; i++)
        A.put(i, 1);
    // Assert
    EXPECT_EQ(A.put(5, 1), FullQueue);
}

TEST(Queue, cant_add_elem_with_incorect_priority) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_ANY_THROW(A.put(10, -1));
}

TEST(Queue, can_correct_add_elem_with_hi_prior_to_the_begin) {
    // Arrange
    Queue A(5);
    // Act
    A.put(10, 2);
    A.put(11, 2);
    A.put(9, 1);
    // Assert
    dataValue expected_res = 9;
    EXPECT_EQ(A.get(), expected_res);
}

TEST(Queue, can_correct_add_elem_with_higher_priority_to_the_mid) {
    // Arrange
    Queue A(5);
    // Act
    A.put(1, 1);
    A.put(3, 3);
    A.put(2, 2);
    // Assert
    dataValue expected_res1 = 1;
    dataValue expected_res2 = 2;
    EXPECT_EQ(A.get(), expected_res1);
    EXPECT_EQ(A.get(), expected_res2);
}

TEST(Queue, can_correct_work_with_priorities) {
    // Arrange
    Queue A(5);
    // Act
    A.put(3, 3);
    A.put(4, 4);
    A.put(1, 1);
    A.put(2, 2);
    A.put(5, 5);
    bool expect = true;
    for (int i = 0; i < 5; i++)
        if (A.get() != (i + 1))
            expect = false;
    // Assert
    EXPECT_EQ(expect, true);
}

TEST(Queue, can_correct_get_elem) {
    // Arrange
    Queue A;
    // Act
    A.put(10, 1);
    A.put(20, 1);
    // Assert
    dataValue expected_res = 10;
    EXPECT_EQ(A.get(), expected_res);
}

TEST(Queue, can_correct_get_several_elems) {
    // Arrange
    Queue A;
    // Act
    A.put(1, 1);
    A.put(2, 1);
    A.put(3, 1);
    // Assert
    dataValue expected_res1 = 1;
    dataValue expected_res2 = 2;
    EXPECT_EQ(A.get(), expected_res1);
    EXPECT_EQ(A.get(), expected_res2);
}

TEST(Queue, cant_get_elem_from_empty_queue) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.get(), EmptyQueue);
}

TEST(Queue, can_delete_queue) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < MemSize; i++)
        A.put(i, 1);
    A.~Queue();
    // Assert
    EXPECT_EQ(A.get(), EmptyQueue);
}

TEST(Queue, can_find_max_elem) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 5; i++)
        A.put(i, 1);
    // Assert
    dataValue expected_res = 4;
    EXPECT_EQ(A.findMaxElem(), expected_res);
}

TEST(Queue, cant_find_max_in_empty_queue) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMaxElem(), EmptyQueue);
}

TEST(Queue, can_find_min_elem) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 5; i++)
        A.put(i + 10, 1);
    A.put(0, 1);
    // Assert
    dataValue expected_res = 0;
    EXPECT_EQ(A.findMinElem(), expected_res);
}

TEST(Queue, cant_find_min_in_empty_queue) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMinElem(), EmptyQueue);
}

TEST(Queue, can_find_max_with_higher_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 3; i++)
        A.put(i, 1);
    for (int i = 0; i < 3; i++)
        A.put((i + 10), 2);
    // Assert
    dataValue expected_res = 2;
    EXPECT_EQ(A.findMaxElemHiPrior(), expected_res);
}

TEST(Queue, cant_find_max_with_hi_pr_in_empty_queue) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMaxElemHiPrior(), EmptyQueue);
}

TEST(Queue, can_find_min_with_higher_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 3; i++)
        A.put((i+10), 1);
    for (int i = 0; i < 3; i++)
        A.put(i, 2);
    A.put(6, 1);
    // Assert
    dataValue expected_res = 6;
    EXPECT_EQ(A.findMinElemHiPrior(), expected_res);
}

TEST(Queue, cant_find_min_with_hi_pr_in_empty_queue) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMinElemHiPrior(), EmptyQueue);
}

TEST(Queue, can_find_max_with_set_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 3; i++)
        A.put(i, 1);
    for (int i = 0; i < 3; i++)
        A.put(i + 10, 2);
    // Assert
    dataValue expected_res1 = 2;
    dataValue expected_res2 = 12;
    EXPECT_EQ(A.findMaxElemSetPrior(1), expected_res1);
    EXPECT_EQ(A.findMaxElemSetPrior(2), expected_res2);
}

TEST(Queue, cant_find_max_with_set_prior_in_empty_q) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMaxElemSetPrior(1), EmptyQueue);
}

TEST(Queue, cant_find_max_with_incorrect_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 10; i++)
        A.put(i, 1);
    // Assert
    EXPECT_ANY_THROW(A.findMaxElemSetPrior(2));
}

TEST(Queue, can_find_min_with_set_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 3; i++)
        A.put(i, 1);
    for (int i = 0; i < 3; i++)
        A.put(i + 10, 2);
    A.put(5, 2);
    // Assert
    dataValue expected_res1 = 0;
    dataValue expected_res2 = 5;
    EXPECT_EQ(A.findMinElemSetPrior(1), expected_res1);
    EXPECT_EQ(A.findMinElemSetPrior(2), expected_res2);
}

TEST(Queue, cant_find_min_with_set_prior_in_empty_q) {
    // Arrange
    Queue A;
    // Act
    // Assert
    EXPECT_EQ(A.findMinElemSetPrior(1), EmptyQueue);
}

TEST(Queue, cant_find_min_with_incorrect_prior) {
    // Arrange
    Queue A;
    // Act
    for (int i = 0; i < 10; i++)
        A.put(i, 3);
    // Assert
    EXPECT_ANY_THROW(A.findMinElemSetPrior(-1));
}
