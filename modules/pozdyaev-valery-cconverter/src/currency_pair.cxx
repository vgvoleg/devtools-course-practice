// Copyright 2016 Pozdyaev Valery

#include "include/currency_pair.h"

#include <string>
#include <regex>

const std::regex currency_code_pattern("[A-Z]{3}\/[A-Z]{3}");

CurrencyPair::CurrencyPair() {
    currency_pair_code_ = "EUR/USD";
    bid_price_ = 1.1;
    ask_price_ = 1.2;
}

CurrencyPair::CurrencyPair(string currency_pair_code,
                            double bid_price, double ask_price) {
    CurrencyPair::checkCurrencyPairCode(currency_pair_code);
    if (bid_price <= 0 || ask_price <= 0) {
        throw string("Incorrect price format");
    }

    if (currency_pair_code.substr(0, 3)
                == currency_pair_code.substr(4, 3)) {
        throw std::string("Exchange with same currency is not supported");
    }

    currency_pair_code_ = currency_pair_code;
    bid_price_ = bid_price;
    ask_price_ = ask_price;
}

void CurrencyPair::setBidPrice(double new_bid_price) {
    if (new_bid_price > 0) {
        bid_price_ = new_bid_price;
    } else {
        throw string("Incorrect bid price format");
    }
}

double CurrencyPair::getBidPrice() {
    return bid_price_;
}

void CurrencyPair::setAskPrice(double new_ask_price) {
    if (new_ask_price > 0) {
        ask_price_ = new_ask_price;
    } else {
        throw string("Incorrect ask price format");
    }
}

double CurrencyPair::getAskPrice() {
    return ask_price_;
}

void CurrencyPair::setCurrencyPairCode(string new_currency_pair_code) {
    checkCurrencyPairCode(new_currency_pair_code);

    currency_pair_code_ = new_currency_pair_code;
}

string CurrencyPair::getCurrencyPairCode() {
    return currency_pair_code_;
}

void CurrencyPair::checkCurrencyPairCode(string currency_pair_code) {
    if (!regex_match(currency_pair_code, currency_code_pattern)) {
        throw string("Incorrect currency pair code");
    }
}
