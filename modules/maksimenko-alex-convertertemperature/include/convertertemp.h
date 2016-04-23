// Copyright 2016 Maksimenko Alex

#ifndef MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
#define MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_

enum class Data { OK, ERROR };

enum class Measure { KELVIN, NUTON, CELSIUS, FAHRENHEIT };

class ConverterTemp {
 private:
    Data retcode_;
    double value_;
    Measure measure_;

 public:
    explicit ConverterTemp(const double, const Measure);
    void converter(const Measure);
    Data getRetCode(void);
    double getValue(void)const;
    Measure getMeasure(void)const;
};

#endif  // MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
