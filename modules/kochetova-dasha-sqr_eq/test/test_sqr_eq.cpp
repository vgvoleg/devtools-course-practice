// Copyright 2016 Kochetova Dasha

#pragma once
#include <set>
#include "include/sqr_eq.h"

#include <gtest/gtest.h>

TEST(QuadraticEquationTest, can_create_object_without_parameters_A) {
    int a = 1;

    Equation eq;

    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_B) {
    int b = 1;

    Equation eq;

    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_C) {
    int c = 1;

    Equation eq;

    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_error) {
    Equation eq;

    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_A) {
    int a = 2;

    Equation eq(2, 1, 1);

    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_B) {
    int b = 2;

    Equation eq(1, 2, 1);

    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_C) {
    int c = 2;

    Equation eq(1, 1, 2);

    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_without_error) {
    Equation eq(2, 4, 5);

    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, not_create_object_with_null_A) {
    int a = 0;

    Equation eq(a, 1, 1);

    EXPECT_TRUE(eq.GetFlag());
}

TEST(QuadraticEquationTest, can_put_parametrs_A) {
    int a = 2;

    Equation eq;
    eq.PutParametrs(2, 4, 1);

    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_put_parametrs_B) {
    int b = 4;

    Equation eq;
    eq.PutParametrs(2, 4, 1);

    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_put_parametrs_C) {
    int c = 1;

    Equation eq;
    eq.PutParametrs(2, 4, 1);

    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, correct_discrim_without_param) {
    int dis = -3;

    Equation eq;

    EXPECT_EQ(dis, eq.Discrim());
}

TEST(QuadraticEquationTest, solve_eq_without_param) {
    Equation eq;
    eq.SolveDiscrim();

    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, correct_discrim_with_param) {
    int dis = 1;

    Equation eq(2, 3, 1);

    EXPECT_EQ(dis, eq.Discrim());
}

TEST(QuadraticEquationTest, solve_eq_with_one_root) {
    int result = -1;

    Equation eq(2, 4, 2);
    eq.SolveDiscrim();

    EXPECT_DOUBLE_EQ(result, eq.GetX1());
}

TEST(QuadraticEquationTest, solve_eq_with_two_root) {
    set<DType> roots = { -3, -1 };

    Equation eq(1, 4, 3);

    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_incomplete_eq_b) {
    set<DType> roots = { -3, 3 };

    Equation eq(1, 0, -9);

    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_incomplete_eq_c) {
    set<DType> roots = {-3, 0};

    Equation eq(1, 3, 0);

    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_eq_with_larger_values_x1) {
    double x1 = -0.0654;
    Equation eq(500, 3240, 210);

    eq.SolveDiscrim();

    EXPECT_NEAR(x1, eq.GetX1(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_larger_values_x2) {
    double x2 = -6.4145;
    Equation eq(500, 3240, 210);

    eq.SolveDiscrim();

    EXPECT_NEAR(x2, eq.GetX2(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_two_double_roots_1) {
    double x1 = -0.11898;
    Equation eq(5, 9, 1);

    eq.SolveDiscrim();

    EXPECT_NEAR(x1, eq.GetX1(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_two__double_roots_2) {
    double x2 = -1.6810;

    Equation eq(5, 9, 1);
    eq.SolveDiscrim();

    EXPECT_NEAR(x2, eq.GetX2(), 0.0001);
}

TEST(QuadraticEquationTest, solve_viet_without_param_error) {
    Equation eq;

    eq.SolveViet();

    EXPECT_TRUE(eq.GetFlag());
}

TEST(QuadraticEquationTest, solve_viet_without_error) {
    Equation eq(1, -5, 6);

    set<double> Discrim = eq.SolveDiscrim();
    set<double> Viet = eq.SolveViet();

    EXPECT_EQ(Discrim, Viet);
}

TEST(QuadraticEquationTest, can_calculate_parabola_top) {
    std::array<double, 2> top = { 2.5, -0.25 };

    Equation eq(1, -5, 6);

    EXPECT_EQ(top, eq.ParabolaTop());
}

TEST(QuadraticEquationTest, can_calculate_parabola_top_error) {
    Equation eq(1, -5, 6);

    eq.ParabolaTop();

    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, calculate_parabola_top_error) {
    Equation eq(0, 6, 5);

    eq.ParabolaTop();

    EXPECT_TRUE(eq.GetFlag());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_x1) {
    Equation eq(1, -2, 10);
    complex<DType> x1(1, 3);

    eq.SolveComplex();

    EXPECT_EQ(x1, eq.GetCx1());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_x2) {
    Equation eq(1, -2, 10);
    complex<DType> x2(1, -3);

    eq.SolveComplex();

    EXPECT_EQ(x2, eq.GetCx2());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_error) {
    Equation eq(1, 0, 9);

    eq.SolveComplex();

    EXPECT_FALSE(eq.GetFlag());
}
