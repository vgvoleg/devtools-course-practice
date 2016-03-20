// Copyright 2016 Kornyakov Kirill

#ifndef MODULES_GLADILOV_GLEB_ZCALC_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_
#define MODULES_GLADILOV_GLEB_ZCALC_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_

#include <string>

// #pragma pack(push, 1)
typedef struct {
    double z1_real;
    double z1_imaginary;
    double z2_real;
    double z2_imaginary;
    char operation;
} Expression;
// #pragma pack(pop)

class ComplexCalculator {
 public:
    ComplexCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool checkArgsNum(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_GLADILOV_GLEB_ZCALC_INCLUDE_COMPLEXCALCULATOR_APPLICATION_H_
