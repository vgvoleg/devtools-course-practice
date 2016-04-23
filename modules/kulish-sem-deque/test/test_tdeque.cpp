// Copyright Kulish_Sem 2016
#include <gtest/gtest.h>
#include <string>
#include "TDeque.hpp"

using std::string;
using std::to_string;

TEST(TDeque, Can_Create_Int_Deque) {
  // Arrange And Act
  TDeque<int> *intDeque = new TDeque<int>;

  // Assert
  EXPECT_NE(nullptr, intDeque);
}

TEST(TDeque, Can_Create_String_Deque) {
  // Arrange And Act
  TDeque<string> *stringDeque = new TDeque<string>;

  // Assert
  EXPECT_NE(nullptr, stringDeque);
}

TEST(TDeque, Can_Create_Double_Deque) {
  // Arrange And Act
  TDeque<double> *doubleDeque = new TDeque<double>;

  // Assert
  EXPECT_NE(nullptr, doubleDeque);
}

TEST(TDeque, Can_Create_Not_Empty_Deque) {
  // Arrange And Act
  const int N = 1;
  TDeque<int> deque(N);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, Push_Head_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, Push_Tail_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Tail(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, Pop_Head_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Tail(i);

  // Assert
  const int expected_result = 0;
  EXPECT_EQ(expected_result, deque.pop_Head());
}

TEST(TDeque, Pop_Head_Works_With_One_Element) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  deque.push_Tail(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Head());
}

TEST(TDeque, Pop_Tail_Works) {
  // Arrange
  TDeque<int> deque;
  TDeque<int> deque1;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  const int expected_result = 0;
  EXPECT_EQ(expected_result, deque.pop_Tail());
}

TEST(TDeque, Pop_Tail_Works_With_One_Element) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  deque.push_Head(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Tail());
}

TEST(TDeque, All_Pop_And_Push_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 50;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.push_Head(i);
    else
      deque.push_Tail(i);

  // Assert
  const int expectedHead = 48;
  const int expectedTail = 49;
  EXPECT_EQ(expectedHead, deque.pop_Head());
  EXPECT_EQ(expectedTail, deque.pop_Tail());
}

TEST(TDeque, Destructor_Works) {
  // Arrange
  TDeque<int>* intDeque = new TDeque<int>();

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      intDeque->push_Head(i);
    else
      intDeque->push_Tail(i);

  intDeque->~TDeque();

  // Assert
  EXPECT_TRUE(intDeque->isEmpty());
}

TEST(TDeque, IsExist_Works) {
  // Arrange
  TDeque<string> deque;

  // Act
  const int N = 10;
  string str = "str";
  for (int i = 0; i < N; i++)
    deque.push_Head(str + to_string(i));

  // Assert
  string expectedResult = "str3";
  EXPECT_TRUE(deque.isExist(expectedResult));
}

TEST(TDeque, isEmpty_works) {
  // Arrange
  TDeque<int> deque;

  // Act And Assert
  bool isEmpty = deque.isEmpty();
  EXPECT_TRUE(isEmpty);
}

TEST(TDeque, Emplace_Head_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.push_Head(i);
    else
      deque.push_Tail(i);

  // Assert
  const int expectedResult = N+1;
  deque.emplace_Head(expectedResult);

  EXPECT_EQ(expectedResult, deque.pop_Head());
}

TEST(TDeque, Emplace_Tail_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      deque.push_Head(i);
    else
      deque.push_Tail(i);

  // Assert
  const int expected_Result = N +1;
  deque.emplace_Tail(expected_Result);
  EXPECT_EQ(expected_Result, deque.pop_Tail());
}

TEST(TDeque, Erase_Works_At_The_End) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  const int position = 0;
  const int numThree = 9;
  deque.erase(numThree, position);
  EXPECT_FALSE(deque.isExist(numThree));
}

TEST(TDeque, Erase_Works_At_The_Start) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  const int position = 0;
  const int numTwo = 5;
  deque.erase(numOne, position);
  EXPECT_FALSE(deque.isExist(numOne));
}

TEST(TDeque, Erase_Works_At_The_Middle) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  const int position = 0;
  const int numTwo = 5;
  deque.erase(numTwo, position);
  EXPECT_FALSE(deque.isExist(numTwo));
}

TEST(TDeque, Brackets_Works) {
  // Arrange
  TDeque<int> deque;

  // Act
  for (int i = 0; i < 10; i++)
    deque.push_Head(i);

  // Assert
  const int position = 5;
  const int expected_Result = 4;
  EXPECT_EQ(expected_Result, deque[position]);
}

TEST(TDeque, Return_Minus_One_Then_Value_Less_Than_Zero) {
  // Arrange
  TDeque<int> deque;

  // Act
  for (int i = 0; i < 50; i++)
    deque.push_Head(i);

  // Assert
  const int position = -1;
  EXPECT_EQ(position, deque[position]);
}
