// Copyright 2016 Pozdyaev Valery

#ifndef MODULES_POZDYAEV_VALERY_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_POZDYAEV_VALERY_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_

#include "include/currency_pair.h"

#include <string>
#include <vector>

using std::string;

class CurrencyConverter {
 public:
    CurrencyConverter();
    void addCurrencyPair(CurrencyPair currency_pair);

    double buyCurrency(string currency_pair_code, double sum);
    double saleCurrency(string currency_pair_code, double sum);

 private:
     CurrencyPair getCurrencyPairByCode(string currency_pair_code);

     std::vector<CurrencyPair> currency_pairs;
};

#endif  // MODULES_POZDYAEV_VALERY_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
