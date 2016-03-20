// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"
#include "include/complexcalculator_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

CalculatorApplication::CalculatorApplication() : message_("") {}

void CalculatorApplication::help(const char* appname, const char* message) {
    message_ =
             std::string(message) +
             std::string("This is a simple complex calculator application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <argument1_real> <argument1_imaginary>"
             + "<argument2_real> <argument2_imaginary> <operation>\n\n"
             + "Where all arguments are double numbers, "
             + "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool CalculatorApplication::checkArgsNum(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}
double parseDouble(const char* arg);
double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}
char parseOperation(const char* arg);
char parseOperation(const char* arg) {
    char oper;
    if (strcmp(arg, "+") == 0) {
        oper = '+';
    } else if (strcmp(arg, "-") == 0) {
        oper = '-';
    } else if (strcmp(arg, "*") == 0) {
        oper = '*';
    } else if (strcmp(arg, "/") == 0) {
        oper = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return oper;
}

std::string CalculatorApplication::operator()(int argc, const char** argv) {
    Expression expr;
    std::ostringstream stream;

    bool returnCode = checkArgsNum(argc, argv);
    if (returnCode != true)
        return message_;
    try {
        expr.arg1_real = static_cast<double>(parseDouble(argv[1]));
        expr.arg1_imaginary = static_cast<double>(parseDouble(argv[2]));
        expr.arg2_real = static_cast<double>(parseDouble(argv[3]));
        expr.arg2_imaginary = static_cast<double>(parseDouble(argv[4]));
        expr.operation = static_cast<char>(parseOperation(argv[5]));
    }
    catch(std::string str) {
        return str;
    }

    Complex a;
    Complex b;
    Complex res;

    a.setReal(expr.arg1_real);
    a.setImaginary(expr.arg1_imaginary);
    b.setReal(expr.arg2_real);
    b.setImaginary(expr.arg2_imaginary);

    switch (expr.operation) {
     case '+':
        res = a + b;
        stream << "Real = " << res.getReal() << " "
               << "Imaginary = " << res.getImaginary();
        break;
     case '-':
        res = a - b;
        stream << "Real = " << res.getReal() << " "
               << "Imaginary = " << res.getImaginary();
        break;
     case '*':
        res = a * b;
        stream << "Real = " << res.getReal() << " "
               << "Imaginary = " << res.getImaginary();
        break;
     case '/':
        try {
            res = a / b;
            stream << "Real = " << res.getReal() << " "
                   << "Imaginary = " << res.getImaginary();
            break;
        }
        catch(std::string str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
