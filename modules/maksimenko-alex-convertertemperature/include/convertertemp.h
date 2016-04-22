// Copyright 2016 Maksimenko Alex

#ifndef MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
#define MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_

namespace Data {
    const int OK = 0;
    const int ERROR = -1;
}

enum Measure { KELVIN, NUTON, DEGREE, FAHRENHEIT };

class ConverterTemp {
 private:
    int retcode_;
    double value_;
    Measure measure_;

 public:
    explicit ConverterTemp(const double, Measure);
    void converter(const Measure);
    int getRetCode(void);
    const double getValue(void);
};

#endif  // MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
