// Copyright 2014 Gladilov Gleb

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/complexcalculator_application.h"

int main(int argc, const char** argv) {
    CalculatorApplication app;
    std::string info = app(argc, argv);
    printf("%s\n", info.c_str());

    return EXIT_SUCCESS;
}
