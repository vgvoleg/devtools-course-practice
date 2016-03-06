// Copyright 2013 Kirill Kornyakov

#ifndef CODE_KORNYAKOV_KIRILL_LAB3_INCLUDE_SIMPLECALCULATOR_APPLICATION_H_
#define CODE_KORNYAKOV_KIRILL_LAB3_INCLUDE_SIMPLECALCULATOR_APPLICATION_H_

#include <string>

#pragma pack(push, 1)
typedef struct {
    int arg1;
    int arg2;
    char operation;
} Expression;
#pragma pack(pop)

class CalculatorApplication {
 public:
    CalculatorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_KORNYAKOV_KIRILL_LAB3_INCLUDE_SIMPLECALCULATOR_APPLICATION_H_
