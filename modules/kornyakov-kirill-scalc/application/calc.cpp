// Copyright 2013 Kirill Kornyakov

#include <stdio.h>
#include <string>

#include "include/simplecalculator_application.h"

int main(int argc, const char** argv) {
    CalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
