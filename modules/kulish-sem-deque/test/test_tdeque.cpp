// Copyright Kulish_Sem 2016
#include <gtest/gtest.h>
#include <string>
#include "TDeque.hpp"

using std::string;
using std::to_string;

TEST(TDeque, Can_Create_Int_Deque) {
  // Arrange
  TDeque<int> *intDeque;

  // Act
  intDeque = new TDeque<int>;

  // Assert
  EXPECT_NE(nullptr, intDeque);
}

TEST(TDeque, Can_Create_String_Deque) {
  // Arrange
  TDeque<string> *stringDeque;

  // Act
  stringDeque = new TDeque<string>;

  // Assert
  EXPECT_NE(nullptr, stringDeque);
}

TEST(TDeque, Can_Create_Double_Deque) {
  // Arrange
  TDeque<double> *doubleDeque;

  // Act
  doubleDeque = new TDeque<double>;

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

TEST(TDeque, Can_Push_Head) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, Can_Use_Lnitializer_List) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});
 
  // Act And Assert
  const int expected_Result = 1;
  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(TDeque, Can_Push_Tail) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Tail(i);

  // Assert
  EXPECT_EQ(N, deque.dequeSize());
}

TEST(TDeque, Can_Pop_Head) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act And Assert
  const int expected_Result = 1;
  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(TDeque, Can_Pop_Head_With_One_Element) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  deque.push_Tail(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Head());
}

TEST(TDeque, Can_Pop_Tail) {
  // Arrange
  TDeque<int> deque({ 0, 1, 2, 3, 4, 5 });

  // Act And Assert
  const int expected_Result = 5;
  EXPECT_EQ(expected_Result, deque.pop_Tail());
}

TEST(TDeque, Can_Pop_Tail_With_One_Element) {
  // Arrange
  TDeque<int> deque;

  // Act
  const int N = 10;
  deque.push_Head(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Tail());
}

TEST(TDeque, Destructor_Works) {
  // Arrange
  TDeque<int>* intDeque = new TDeque<int>({1, 2, 3, 4, 5});

  // Act
  intDeque->~TDeque();

  // Assert
  EXPECT_TRUE(intDeque->isEmpty());
}

TEST(TDeque, Can_Use_IsExist) {
  // Arrange
  TDeque<string> deque({ "str1", "str2", "str3", "str4", "str5" });

  // Act And Assert
  string expected_Result = "str3";
  EXPECT_TRUE(deque.isExist(expected_Result));
}

TEST(TDeque, Can_Use_isEmpty) {
  // Arrange
  TDeque<int> deque;

  // Act And Assert
  EXPECT_TRUE(deque.isEmpty());
}

TEST(TDeque, Can_Emplace_Head) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act And Assert
  const int expected_Result = 10;
  deque.emplace_Head(expected_Result);

  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(TDeque, Can_Emplace_Tail) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act

  // Act And Assert
  const int expected_Result = 10;
  deque.emplace_Tail(expected_Result);
  EXPECT_EQ(expected_Result, deque.pop_Tail());
}

TEST(TDeque, Can_Erase_Last_Element) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int num = 5;
  deque.erase(num, position);

  // Assert
  EXPECT_FALSE(deque.isExist(num));
}

TEST(TDeque, Can_Erase_First_Element) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int num = 1;
  deque.erase(num, position);

  // Assert
  EXPECT_FALSE(deque.isExist(num));
}

TEST(TDeque, Can_Erase_Middle_Element) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int num = 3;
  deque.erase(num, position);

  // Assert
  EXPECT_FALSE(deque.isExist(num));
}

TEST(TDeque, Can_Use_Brackets) {
  // Arrange
  TDeque<int> deque({1, 2, 3, 4, 5});

  // Act And Assert
  const int position = 4;
  const int expected_Result = 2;
  EXPECT_EQ(expected_Result, deque[position]);
}

TEST(TDeque, Return_Minus_One_Then_Value_Less_Than_Zero) {
  // Arrange
  TDeque<int> deque;

  // Act And Assert
  const int position = -2;
  const int expected_Result = -1;
  EXPECT_EQ(expected_Result, deque[position]);
}
