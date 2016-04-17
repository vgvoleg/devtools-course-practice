// Copyright 2016 Pozdyaev Valery

#include "include/currency_converter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>

CurrencyConverter::CurrencyConverter() {
    currency_pairs.resize(0);
}

void CurrencyConverter::addCurrencyPair(CurrencyPair currency_pair) {
    for (CurrencyPair& pair : currency_pairs) {
        if (pair.getCurrencyPairCode() == currency_pair.getCurrencyPairCode()) {
            pair.setAskPrice(currency_pair.getAskPrice());
            pair.setBidPrice(currency_pair.getBidPrice());

            return;
        }
    }

    currency_pairs.push_back(currency_pair);
}

double CurrencyConverter::buyCurrency(string currency_pair_code, double sum) {
    CurrencyPair currency_pair = getCurrencyPairByCode(currency_pair_code);

    if (sum > 0) {
    return sum / currency_pair.getAskPrice();
    } else {
        throw std::string("Sum must be greater than 0");
    }
}

double CurrencyConverter::saleCurrency(string currency_pair_code, double sum) {
    CurrencyPair currency_pair = getCurrencyPairByCode(currency_pair_code);

    if (sum > 0) {
        return sum * currency_pair.getBidPrice();
    } else {
        throw std::string("Sum must be greater than 0");
    }
}

CurrencyPair CurrencyConverter::getCurrencyPairByCode(string curr_pair_code) {
    CurrencyPair::checkCurrencyPairCode(curr_pair_code);

    for (CurrencyPair pair : currency_pairs) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return pair;
        }
    }

    throw std::string("Currency pair is not found");
}
