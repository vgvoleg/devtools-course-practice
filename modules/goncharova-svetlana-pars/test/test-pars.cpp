// Copyright 2016 Goncharova Svetlana

#include <gtest/gtest.h>

#include "include/pars.h"

TEST(Parser, Can_Create_Parser) {
    // Arrange
    Parser* ptrParser;

    // Act
    ptrParser = new Parser("32+21");

    // Assert
    EXPECT_NE(nullptr, ptrParser);
}

TEST(Parser, Can_Calc_Eval_With_Sum_Pow_Proisv) {
    // Arrange
    Parser parser("2+2*(3+2**3)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 2 + 2 * (3 + 2 * 2 * 2);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Mod_Abs_Otricanie) {
    // Arrange
    Parser parser("abs(-2)+2*(3mod4)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 8;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Sin_Cos_Del) {
    // Arrange
    Parser parser("sin(1)/cos(0)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = sin(1)/cos(0);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Error_If_Unknown_Un_Operator) {
    // Arrange
    Parser parser("sin(10)/tan(1)");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Token) {
    // Arrange
    Parser parser("#1");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Check_Brackets) {
    // Arrange
    Parser parser("(1+3");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Bin_Operator) {
    // Arrange
    Parser parser("(8 div 7)/8");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Expression_Type) {
    // Arrange
    Parser parser("Hello,world");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}
