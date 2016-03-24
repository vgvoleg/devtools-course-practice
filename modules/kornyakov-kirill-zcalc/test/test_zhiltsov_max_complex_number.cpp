// Copyright 2016 Zhiltsov Max

#include <gtest/gtest.h>
#include <limits>
#include <cmath>

#include "include/complex_number.h"

TEST(Zhiltsov_Max_ComplexNumberTest, MoveAssign_Working) {
    const ComplexNumber z1(10, 20);

    ComplexNumber z2;
    z2 = std::move(z1);

    EXPECT_EQ(z1, z2);
}

TEST(Zhiltsov_Max_ComplexNumberTest, MoveCtor_Working) {
    const ComplexNumber z1(10, 20);

    ComplexNumber z2(std::move(z1));

    EXPECT_EQ(z1, z2);
}

TEST(Zhiltsov_Max_ComplexNumberTest, LimitingValueAddition_Correct) {
    const ComplexNumber z(std::numeric_limits<double>::max(), 0);

    ComplexNumber sum = z + z;

    EXPECT_TRUE(std::isinf(sum.getRe()));
}

TEST(Zhiltsov_Max_ComplexNumberTest, DISABLED_LimitingValueAddition_Incorrect) {
    const ComplexNumber z1(std::numeric_limits<double>::max(), 0);
    const ComplexNumber z2(1.0, 0.0);

    ComplexNumber sum = z1 + z2;

    /*
    Failure because of IEEE754 floating point format and
    addition algorithm in particular.
    Expected result is at least "+inf" value
    instead of the same value as bigger operand.

    Possible solution:
    a) try to use a safe arihmetics algorithms
    b) throw an expection
    */
    EXPECT_TRUE(std::isinf(sum.getRe()));
}

TEST(Zhiltsov_Max_ComplexNumberTest, Multiplication_Correct) {
    const ComplexNumber z1(1.0e100, 0);
    const ComplexNumber z2(2.0, 0);

    ComplexNumber result = z1 * z2;

    EXPECT_DOUBLE_EQ(2.0e100, result.getRe());
}
