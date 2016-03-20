// Copyright 2014 Gladilov Gleb

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/complex_calculator.h"

int main(int argc, const char** argv) {
    ComplexCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return EXIT_SUCCESS;
}
