// Copyright 2016 Goncharova Svetlana

#include "include/pars.h"

#include <string>

    string Parser::parse_token() {
    while (isspace(*input)) ++input;

    if (isdigit(*input)) {
        string number;
        while (isdigit(*input) || *input == '.') number.push_back(*input++);
        return number;
    }

    static const string tokens[] =
    { "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };
    for (auto& t : tokens) {
        if (strncmp(input, t.c_str(), t.size()) == 0) {
            input += t.size();
            return t;
        }
    }

    return "";
}

Expression Parser::parse_simple_expression() {
    auto token = parse_token();
    if (token.empty()) {
        throw std::runtime_error("Invalid input");
    }
    if (token == "(") {
        auto result = parse();
        if (parse_token() != ")") {
            throw std::runtime_error("Expected ')'");
        }
        return result;
    }

    if (isdigit(token[0])) {
        return Expression(token);
    }
    return Expression(token, parse_simple_expression());
}

int get_priority(const string& binary_op) {
    if (binary_op == "+") {
        return 1;
    }
    if (binary_op == "-") {
        return 1;
    }
    if (binary_op == "*") {
        return 2;
    }
    if (binary_op == "/") {
        return 2;
    }
    if (binary_op == "mod") {
        return 2;
    }
    if (binary_op == "**") {
        return 3;
    }
    return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {
    auto left_expr = parse_simple_expression();

    for (;;) {
        auto op = parse_token();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return parse_binary_expression(0);
}

double Parser::eval(const Expression& e) {
    double result;
    switch (e.args.size()) {
    case 2: {
        auto a = eval(e.args[0]);
        auto b = eval(e.args[1]);
        if (e.token == "+") {
            result = a + b;
        }
        if (e.token == "-") {
            result = a - b;
        }
        if (e.token == "*") {
            result = a * b;
        }
        if (e.token == "/") {
            result = a / b;
        }
        if (e.token == "**") {
            result = pow(a, b);
        }
        if (e.token == "mod") {
            result = static_cast<int> (a) % static_cast<int> (b);
        }
        break;
    }

    case 1: {
        auto a = eval(e.args[0]);
        if (e.token == "+") {
            result = +a;
        }
        if (e.token == "-") {
            result = -a;
        }
        if (e.token == "abs") {
            result = fabs(a);
        }
        if (e.token == "sin") {
            result = sin(a);
        }
        if (e.token == "cos") {
            result = cos(a);
        }
        break;
    }

    case 0:
        result = strtod(e.token.c_str(), nullptr);
        break;
    }
    return result;
}
