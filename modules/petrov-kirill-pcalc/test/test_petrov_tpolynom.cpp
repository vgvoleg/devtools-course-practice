// Copyright 2016 Petrov Kirill
#include <gtest/gtest.h>
#include "tpolynom.h"

TEST(TPolynom, Can_Create) {
	// Arrange
	TPolynom* P;

	// Act
	const int size = 3;
	const double mon[][2] = { { 1.0, 3 },{ 3.0, 4 },{ 1.0, 6 } };
	P = new TPolynom (mon,size);

	// Assert
	EXPECT_NE(P, nullptr);
}

TEST(TPolynom, Can_Compare)
{
	// Arrange
	const int size = 3;
	const double mon[][2] = { { 1.0, 3 },{ 2.0, 4 },{ 2.0, 100 } };
	const TPolynom P1(mon, size);
	const TPolynom P2(mon, size);

	// Act & Assert
	EXPECT_TRUE(P1 == P2);
}

TEST(TPolynom, Can_Get_Does_Not_Equal)
{
	// Arrange
	const int size = 3;
	const double mon1[][2] = { { 1.0, 3 },{ 2.0, 4 },{ 2.0, 100 } };
	const double mon2[][2] = { { 1.0, 3 },{ 2.0, 4 },{ 2.0, 101 } };
	const TPolynom P1(mon1, size);
	const TPolynom P2(mon2, size);

	// Act & Assert
	EXPECT_TRUE(P1 != P2);
}

TEST(TPolynom, Can_Create_Via_Copying)
{
	// Arrange
	const int size = 3;
	const double mon[][2] = { { 1.0, 3 },{ 2.0, 4 },{ 2.0, 100 } };
	const TPolynom P1(mon, size);

	// Act
	const TPolynom P2 = P1;

	// Act & Assert
	EXPECT_EQ(P1, P2);
}
TEST(TPolynom, Can_Assign)
{
	// Arrange
	const int size = 2;
	const double mon1[][2] = { { 5.0, 3 },{ 2.0, 4 } };
	const double mon2[][2] = { { 2.0, 6 },{ 1.0, 9 } };
	const TPolynom P1(mon1, size);
	TPolynom P2 (mon2,size);

	// Act
	P2 = P1;

	// Assert
	EXPECT_EQ(P1, P2);
}

TEST(TPolynom, Can_Add_Polynoms)
{
	// Arrange
	const int size1 = 5;
	const int size2 = 4;
	const double mon1[][2] = { { 5.0, 213 },{ 8.0, 321 },{ 10.0, 432 },{ -21.0, 500 },{ 10.0, 999 } };
	const double mon2[][2] = { { 15.0, 0 },{ -8.0, 321 },{ 1.0, 500 },{ 20.0, 702 } };
	const TPolynom P1(mon1, size1);
	const TPolynom P2(mon2, size2);

	// Act
	const TPolynom P = P1 + P2;

	// Assert
	const int expected_size = 6;
	const double expected_mon[][2] = { { 10.0, 999 }, { 20.0, 702 }, { -20.0, 500 }, { 10.0, 432 }, { 5.0, 213 }, { 15, 0 } };
	const TPolynom expected_P(expected_mon, expected_size);
	EXPECT_EQ(expected_P, P);
}

TEST(DISABLE_TPolynom, Can_Add_Polynoms_With_The_Same_Index)
{
	// Arrange
	const int size1 = 2;
	const int size2 = 2;
	const double mon1[][2] = { { 5.0, 2 },{ 8.0, 2 } };
	const double mon2[][2] = { { 15.0, 3 },{ -8.0, 3 } };
	const TPolynom P1(mon1, size1);
	const TPolynom P2(mon2, size2);

	// Act
	const TPolynom P = P1 + P2;

	// Assert
	const int expected_size = 2;
	const double expected_mon[][2] = { { 7.0, 3 },{ 13.0, 2 } };
	const TPolynom expected_P(expected_mon, expected_size);
	EXPECT_EQ(expected_P, P);
}

TEST(TPolynom, Can_Add_Up_Many_Polynoms)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	const double mon1[][2] = { { 5.0, 2 },{ 8.0, 3 },{ 9.0, 4 } };
	const double mon2[][2] = { { 1.0, 1 },{ -8.0, 3 },{ 1.0, 4 },{ 2.0, 5 } };
	const double mon3[][2] = { { 10.0, 0 },{ 2.0, 3 },{ 8.0, 5 } };
	const TPolynom P1(mon1, size1);
	const TPolynom P2(mon2, size2);
	const TPolynom P3(mon3, size3);

	// Act
	const TPolynom P = P1 + P2 + P3;

	// Assert
	const int expected_size = 6;
	const double expected_mon[][2] = { { 10.0, 5 }, { 10.0, 4 }, { 2.0, 3 }, { 5.0, 2 }, { 1.0, 1 }, { 10.0, 0 } };
	const TPolynom expected_P(expected_mon, expected_size);
	EXPECT_EQ(expected_P, P);
}

TEST(TPolynom, Can_Get_Zero_Monom)
{
	// Arrange
	const int size = 3;
	const double mon[][2] = { { 5.0, 213 },{ 8.0, 321 },{ 10.0, 432 } };
	const TPolynom P1(mon, size);
	const TPolynom P2(mon, size);

	// Act
	const TPolynom P = P1 - P2;

	// Assert
	const int expected_size = 1;
	const double expected_mon[][2] = { { 0.0, 0 } };
	const TPolynom expected_P(expected_mon, expected_size);
	EXPECT_EQ(expected_P, P);
}

TEST(TPolynom, Can_Subtract_Polynoms)
{
	// Arrange
	const int size1 = 2;
	const int size2 = 3;
	const double mon1[][2] = { { 5.5, 4 }, { 8.2, 2 } };
	const double mon2[][2] = { { 15.2, 2 }, { -8.0, 3 }, { 3.5, 4 } };
	const TPolynom P1(mon1, size1);
	const TPolynom P2(mon2, size2);

	// Act
	const TPolynom P = P1 - P2;

	// Assert
	const int expected_size = 3;
	const double expected_mon[][2] = { { 2.0, 4 }, { 8.0, 3 }, { -7.0, 2 } };
	const TPolynom expected_P(expected_mon, expected_size);
	EXPECT_EQ(expected_P, P);
}