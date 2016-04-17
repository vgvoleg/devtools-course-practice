// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include "include/parse.h"

TEST(Parse, can_parse_number) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "3";

  // Act
  int result = Parse::number(argv, start, finish);

  // Assert
  const int expected_n = 3;
  EXPECT_EQ(expected_n, result);
}

TEST(Parse, can_catch_the_exception_wrong_number) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "a2";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::number(argv, start, finish) );
}

TEST(Parse, can_catch_the_exception_incorrect_value) {
  // Arrange
  const char* argv = "2.s3";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::value(argv));
}

TEST(Parse, can_catch_the_exception_went_abroad) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "6";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::number(argv, start, finish));
}

TEST(Parse, can_parse_polynom) {
  // Arrange
  const char* argv = "1.01x^2y^1z^0+3x^1y^1z^2-2.5x^3y^0z^0";

  // Act
  const TPolynom polynom = Parse::polynom(argv);

  // Assert
  const int expected_size = 3;
  const double expected_mon[][2] = { { 3.0, 112 }, { 1.01, 210 },
                                     { -2.5, 300 } };
  const TPolynom expected_P(expected_mon, expected_size);
  EXPECT_EQ(expected_P, polynom);
}

TEST(Parse, can_catch_the_exception_wrong_polynoms_format) {
  // Arrange
  const char* argv = "1x^2y^1z^0+3^1y^1z^2-2x^3y^0z^0";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::polynom(argv) );
}

TEST(Parse, can_parse_operation) {
  // Arrange
  const char* argv = "compute";

  // Act
  const TOperation operation = Parse::operation(argv);

  // Assert
  const TOperation expected_O = COMPUTE;
  EXPECT_EQ(expected_O, operation);
}

TEST(Parse, can_catch_the_exception_no_such_operation) {
  // Arrange
  const char* argv = "compu1te";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::operation(argv) );
}

