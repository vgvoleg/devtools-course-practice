// Copyright 2016 Kornyakov Kirill

#ifndef MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_CALCULATOR_H_

#include <string>

class ComplexCalculator {
 public:
    ComplexCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double z1_real;
        double z1_imaginary;
        double z2_real;
        double z2_imaginary;
        char operation;
    } Arguments;
};

#endif  // MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_CALCULATOR_H_
