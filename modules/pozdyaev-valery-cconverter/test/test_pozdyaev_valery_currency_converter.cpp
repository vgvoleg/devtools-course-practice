// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include <string>

#include "include/currency_converter.h"

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Converter) {
    // Arrange
    CurrencyConverter* cconverter;

    // Act
    cconverter = new CurrencyConverter();

    // Assert
    EXPECT_NE(nullptr, cconverter);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Default_Currency_Pair) {
    // Arrange
    CurrencyPair *default_currency_pair;
    string currency_code = "USD/USD";
    double bid_price = 1.0;
    double ask_price = 1.0;

    // Act
    default_currency_pair = new CurrencyPair();

    // Assert
    EXPECT_EQ(currency_code, default_currency_pair->getCurrencyPairCode());
    EXPECT_DOUBLE_EQ(bid_price, default_currency_pair->getBidPrice());
    EXPECT_DOUBLE_EQ(ask_price, default_currency_pair->getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Currency_Pair) {
    // Arrange
    CurrencyPair* currency_pair;
    string currency_code = "EUR/USD";
    double bid_price = 1.1234;
    double ask_price = 1.2345;

    // Act
    currency_pair = new CurrencyPair(currency_code, bid_price, ask_price);

    // Assert
    EXPECT_EQ(currency_code, currency_pair->getCurrencyPairCode());
    EXPECT_DOUBLE_EQ(bid_price, currency_pair->getBidPrice());
    EXPECT_DOUBLE_EQ(ask_price, currency_pair->getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Set_And_Get_Currency_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double new_bid_price = 2.1;
    double new_ask_price = 2.2;

    // Act
    currency_pair.setBidPrice(new_bid_price);
    currency_pair.setAskPrice(new_ask_price);

    // Assert
    EXPECT_DOUBLE_EQ(new_bid_price, currency_pair.getBidPrice());
    EXPECT_DOUBLE_EQ(new_ask_price, currency_pair.getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Set_And_Get_Pair_Code) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    string new_code = "EUR/RUB";

    // Act
    currency_pair.setCurrencyPairCode(new_code);

    // Assert
    EXPECT_EQ(new_code, currency_pair.getCurrencyPairCode());
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Set_Incorrect_Bid_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double incorrect_bid_price = -0.5;

    // Act & Assert
    EXPECT_THROW(currency_pair.setBidPrice(incorrect_bid_price), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Set_Incorrect_Ask_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double incorrect_ask_price = -0.5;

    // Act & Assert
    EXPECT_THROW(currency_pair.setAskPrice(incorrect_ask_price), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Set_Bad_Currency_Code) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    string incorrect_code = "Eur.UsD";

    // Act & Assert
    EXPECT_THROW(currency_pair.setCurrencyPairCode(incorrect_code), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Create_Pair_With_Bad_Code) {
    // Arrange
    string incorrect_code = "Eur.UsD";
    double bid_price = 2.1;
    double ask_price = 2.2;

    // Act & Assert
    EXPECT_THROW(CurrencyPair(incorrect_code, bid_price, ask_price), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Create_Pair_With_Bad_Price) {
    // Arrange
    string code = "EUR/USD";
    double incorrect_bid_price = -2.1;
    double ask_price = 2.2;

    // Act & Assert
    EXPECT_THROW(CurrencyPair(code, incorrect_bid_price, ask_price), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Update_Existing_Currency_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.3, 1.5));
    double boughtCurrency = converter.saleCurrency("EUR/USD", 10);

    // Assert
    double expected_currency_sum = 13;
    EXPECT_DOUBLE_EQ(boughtCurrency, expected_currency_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Buy_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double boughtCurrency = converter.buyCurrency("EUR/USD", 12);

    // Assert
    double expected_currency_sum = 7.5;
    EXPECT_DOUBLE_EQ(boughtCurrency, expected_currency_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Sale_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double boughtCurrency = converter.saleCurrency("EUR/USD", 12);

    // Assert
    double expected_currency_sum = 14.4;
    EXPECT_DOUBLE_EQ(boughtCurrency, expected_currency_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Buy_With_Incorrect_Code) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.buyCurrency("EuR/UsD", 12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Sale_With_Incorrect_Code) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.saleCurrency("EuR/UsD", 12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Buy_With_Incorrect_Sum) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.buyCurrency("EUR/USD", -12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Sale_With_Incorrect_Sum) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.saleCurrency("EUR/USD", -12), string);
}
