// Copyright 2016 Kornyakov Kirill

//#define TEST
#ifndef TEST

#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

#include "tpolynom.h"

int main()
{
	const int size1 = 2;
	const int size2 = 3;
	const double mon1[][2] = { { 5.5, 4 },{ 8.2, 2 } };
	const double mon2[][2] = { { 15.2, 2 },{ -8.0, 3 },{ 3.5, 4 } };
	const TPolynom P1(mon1, size1);
	const TPolynom P2(mon2, size2);

	// Act
	const TPolynom P = P1 - P2;
}
#endif