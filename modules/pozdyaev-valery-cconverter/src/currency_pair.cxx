// Copyright 2016 Pozdyaev Valery

#include "include/currency_pair.h"

#include <utility>
#include <map>
#include <string>

const double base_lot_size = 10000;

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

    updateSpreadHistory();
}

void CurrencyPair::setBidPrice(double new_bid_price) {
    if (new_bid_price > 0) {
        bid_price_ = new_bid_price;
        updateSpreadHistory();
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
        updateSpreadHistory();
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
    size_t code_size = currency_pair_code.size();
    int symb_code = 0;

    if (code_size == 7) {
        for (int i = 0; i < 7; i++) {
            symb_code = static_cast<int> (currency_pair_code[i]);
            if ((i == 3 && symb_code != 47)
                || (i != 3 && (symb_code < 65 || symb_code > 90))) {
                throw string("Incorrect currency pair code");
            }
        }
    } else {
        throw string("Incorrect size of currency pair code");
    }
}

std::map<time_t, int> CurrencyPair::getSpreadHistory() {
    return spread_history;
}

void CurrencyPair::updateSpreadHistory() {
    time_t now = time(NULL);

    int spread = (ask_price_ - bid_price_) * base_lot_size;

    spread_history.insert(std::pair<time_t, int>(now, spread));
}
