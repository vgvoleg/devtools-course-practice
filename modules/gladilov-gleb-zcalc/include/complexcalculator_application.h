// Copyright 2014 Gladilov Gleb

#ifndef CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_
#define CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_

#include <string>

#pragma pack(push, 1)
typedef struct {
    double arg1_real;
    double arg1_imaginary;
    double arg2_real;
    double arg2_imaginary;
    char operation;
} Expression;
#pragma pack(pop)

class CalculatorApplication {
 public:
    CalculatorApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;

    void help(const char* appname, const char* message = "");
    bool checkArgsNum(int argc, const char** argv);
};

#endif  // CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_
