// Copyright Kulish_Sem 2016

#include <string>
#include <gtest/gtest.h>
#include "TDeque.h"

using std::string;

TEST(TDeque, can_create_deque) {
  // Arrange And Act
  TDeque<int> *intDeque = new TDeque<int>;
  TDeque<string> *strigDeque = new TDeque<string>;
  TDeque<double> *doubleDeque = new TDeque<double>;

  // Assert
  EXPECT_FALSE(NULL == intDeque);
  EXPECT_FALSE(NULL == strigDeque);
  EXPECT_FALSE(NULL == doubleDeque);
}

TEST(TDeque, can_create_not_empty_deque) {
  // Arrange And Act
  const int N = 1;
  TDeque<int> deque(N);

  // Assert
  EXPECT_EQ(1, deque.dequeSize());
}

TEST(TDeque, addHead_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.addHead(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, addTail_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.addTail(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, getHead_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.addTail(i);

  // Assert
  const int expected_result = 0;
  EXPECT_EQ(expected_result, deque.getHead());
}

TEST(TDeque, getTail_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.addHead(i);

  // Assert
  const int expected_result = 0;
  EXPECT_EQ(expected_result, deque.getTail());
}

TEST(TDeque, all_get_and_add_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 50;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.addHead(i);
    else
      deque.addTail(i);

  // Assert
  EXPECT_EQ(48, deque.getHead());
  EXPECT_EQ(49, deque.getTail());
}

TEST(TDeque, destructor_works) {
  // Arrange
  TDeque<int>* intDeque = new TDeque<int>();

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      intDeque->addHead(i);
    else
      intDeque->addTail(i);

  intDeque->~TDeque();

  // Assert
  EXPECT_TRUE(intDeque->isEmpty());
}

TEST(TDeque, isExist_works_) {
  // Arrange
  TDeque<string> deque;

  // Act
  const int N = 10;
  string str = "str";
  for (int i = 0; i < N; i++)
    deque.addHead(str + to_string(i));

  // Assert
  EXPECT_TRUE(deque.isExist("str3"));
}

TEST(TDeque, isEmpty_works) {
  // Arrange
  TDeque<int> deque;

  // Act And Assert
  bool isEmpty = deque.isEmpty();
  EXPECT_TRUE(isEmpty);
}

TEST(TDeque, emplace_Head_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.addHead(i);
    else
      deque.addTail(i);

  // Assert
  const int expectedResult = N+1;
  deque.emplace_Head(expectedResult);

  EXPECT_EQ(expectedResult, deque.getHead());
}

TEST(TDeque, emplace_tail_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.addHead(i);
    else
      deque.addTail(i);

  // Assert
  const int expected_Result = N +1;
  deque.emplace_Tail(expected_Result);
  EXPECT_EQ(expected_Result, deque.getTail());
}

TEST(TDeque, erase_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.addHead(5);
    else
      deque.addTail(2);

  // Assert
  const int num = 2;
  deque.erase(num, 0);
  EXPECT_FALSE(deque.isExist(num));
}

TEST(TDeque, bracers_works) {
  // Arrange
  TDeque<int> deque;

  // Act
  for (int i = 0; i < 10; i++)
    deque.addHead(i);

  // Assert
  const int position = 5;
  const int expected_Result = 4;
  EXPECT_EQ(expected_Result, deque[position]);
}

TEST(TDeque, can_go_abroad_deque) {
  // Arrange
  TDeque<int> deque;

  // Act
  for (int i = 0; i < 50; i++)
    deque.addHead(i);

  // Assert
  const int position = 51;
  ASSERT_ANY_THROW(deque[position]);
}
