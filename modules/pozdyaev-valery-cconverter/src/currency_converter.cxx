// Copyright 2016 Pozdyaev Valery

#include "include/currency_converter.h"


#include <string>

CurrencyConverter::CurrencyConverter() {
    currency_pairs.resize(0);
}

void CurrencyConverter::addCurrencyPair(CurrencyPair currency_pair) {
    string revers_code = currency_pair.getCurrencyPairCode().substr(4, 3) + "/"
        + currency_pair.getCurrencyPairCode().substr(0, 3);

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())
        || isCurrencyPairPresented(revers_code)) {
        throw std::string("Pair is already presented. Please use Update");
    }

    currency_pairs.push_back(currency_pair);
}

void CurrencyConverter::updateCurrencyPair(CurrencyPair currency_pair) {
    string currency_code = currency_pair.getCurrencyPairCode();

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())) {
        CurrencyPair& pair = getCurrencyPairByCode(currency_code);
        pair.setAskPrice(currency_pair.getAskPrice());
        pair.setBidPrice(currency_pair.getBidPrice());
    } else {
        throw std::string("Nothing to update");
    }
}

double CurrencyConverter::buyCurrency(CurrencyPair currency_pair, double sum) {
    return sum / currency_pair.getAskPrice();
}

double CurrencyConverter::saleCurrency(CurrencyPair currency_pair, double sum) {
    return sum * currency_pair.getBidPrice();
}

CurrencyPair& CurrencyConverter::getCurrencyPairByCode(string curr_pair_code) {
    for (CurrencyPair& pair : currency_pairs) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return pair;
        }
    }
}

bool CurrencyConverter::isCurrencyPairPresented(string curr_pair_code) {
    for (CurrencyPair pair : currency_pairs) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return true;
        }
    }

    return false;
}

double CurrencyConverter::exchangeCurrency(string selling_currency,
                                           string buying_currency, double sum) {
    if (sum <= 0) {
        throw std::string("Sum must be greater than 0");
    }

    if (selling_currency == "" || buying_currency == "") {
        throw std::string("Value of buying or selling currency is empty");
    }

    CurrencyPair currency_pair;

    string currency_pair_code = selling_currency + "/" + buying_currency;

    CurrencyPair::checkCurrencyPairCode(currency_pair_code);

    if (isCurrencyPairPresented(currency_pair_code)) {
        currency_pair = getCurrencyPairByCode(currency_pair_code);
        return saleCurrency(currency_pair, sum);
    }

    currency_pair_code = buying_currency + "/" + selling_currency;

    if (isCurrencyPairPresented(currency_pair_code)) {
        currency_pair = getCurrencyPairByCode(currency_pair_code);
        return buyCurrency(currency_pair, sum);
    }

    throw std::string("Can not exchange currency. Currency pair is not found");
}
