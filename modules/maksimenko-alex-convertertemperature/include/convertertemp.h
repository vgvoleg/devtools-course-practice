// Copyright 2016 Maksimenko Alex

#ifndef MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
#define MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_

enum Data { OK, ERROR };

enum class Measure { KELVIN, NUTON, DEGREE, FAHRENHEIT };

const double daughternum[5] { 273.0, 32.0, 1.8, 33.0, 100.0 };

class ConverterTemp {
 private:
    Data retcode_;
    double value_;
    Measure measure_;

 public:
    explicit ConverterTemp(const double, Measure);
    void converter(const Measure);
    int getRetCode(void);
    const double getValue(void);
    Measure getMeasure(void);
};

#endif  // MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
