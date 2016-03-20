// Copyright 2016 Kornyakov Kirill

#include "include/complex_number.h"
#include "include/complex_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

ComplexCalculator::ComplexCalculator() : message_("") {}

void ComplexCalculator::help(const char* appname, const char* message) {
    message_ =
             std::string(message) +
             std::string("This is a complex number calculator application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <z1_real> <z1_imaginary>"
             + "<z2_real> <z2_imaginary> <operation>\n\n"
             + "Where all arguments are double-precision numbers, "
             + "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool ComplexCalculator::checkArgsNum(int argc, const char** argv) {
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
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string ComplexCalculator::operator()(int argc, const char** argv) {
    Expression expr;
    std::ostringstream stream;

    bool returnCode = checkArgsNum(argc, argv);
    if (returnCode != true)
        return message_;
    try {
        expr.z1_real = static_cast<double>(parseDouble(argv[1]));
        expr.z1_imaginary = static_cast<double>(parseDouble(argv[2]));
        expr.z2_real = static_cast<double>(parseDouble(argv[3]));
        expr.z2_imaginary = static_cast<double>(parseDouble(argv[4]));
        expr.operation = static_cast<char>(parseOperation(argv[5]));
    }
    catch(std::string str) {
        return str;
    }

    ComplexNumber z1;
    ComplexNumber z2;

    z1.setReal(expr.z1_real);
    z1.setImaginary(expr.z1_imaginary);
    z2.setReal(expr.z2_real);
    z2.setImaginary(expr.z2_imaginary);

    ComplexNumber z;
    switch (expr.operation) {
     case '+':
        z = z1 + z2;
        stream << "Real = " << z.getReal() << " "
               << "Imaginary = " << z.getImaginary();
        break;
     case '-':
        z = z1 - z2;
        stream << "Real = " << z.getReal() << " "
               << "Imaginary = " << z.getImaginary();
        break;
     case '*':
        z = z1 * z2;
        stream << "Real = " << z.getReal() << " "
               << "Imaginary = " << z.getImaginary();
        break;
     case '/':
        try {
            z = z1 / z2;
            stream << "Real = " << z.getReal() << " "
                   << "Imaginary = " << z.getImaginary();
            break;
        }
        catch(std::string str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
