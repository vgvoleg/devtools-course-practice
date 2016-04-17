// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include <string>

#include "include/currency_converter.h"

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Converter) {
    // Arrange
    CurrencyConverter* converter;

    // Act
    converter = new CurrencyConverter();

    // Assert
    EXPECT_NE(nullptr, converter);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Default_Currency_Pair) {
    // Arrange
    CurrencyPair *default_currency_pair;
    string currency_code = "EUR/USD";
    double bid_price = 1.1;
    double ask_price = 1.2;

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
    converter.updateCurrencyPair(CurrencyPair("EUR/USD", 1.3, 1.5));
    double bought_USD = converter.exchangeCurrency("EUR", "USD", 10);

    // Assert
    double expected_USD_sum = 13;
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Update_Through_Add_Func) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair updated_pair("EUR/USD", 1.3, 1.5);
    EXPECT_THROW(converter.addCurrencyPair(updated_pair), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Update_Non_Existing_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair non_existing_pair("USD/RUB", 63.2, 65.5);
    EXPECT_THROW(converter.updateCurrencyPair(non_existing_pair), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Sale_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_USD = converter.exchangeCurrency("EUR", "USD", 12);

    // Assert
    double expected_USD_sum = 14.4;
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Buy_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_EUR = converter.exchangeCurrency("USD", "EUR", 12);

    // Assert
    double expected_EUR_sum = 7.5;
    EXPECT_DOUBLE_EQ(bought_EUR, expected_EUR_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Incorrect_Code) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("UsD", "Eu", 12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Unknown_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "RUB", 12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Incorrect_Sum) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "EUR", -12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Empty_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "", 12), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Add_Revers_Currency_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair reverse_pair("USD/EUR", 1.3, 1.5);
    EXPECT_THROW(converter.addCurrencyPair(reverse_pair), string);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Add_Pair_Of_Same_Currency) {
    // Arrange
    CurrencyConverter converter;

    // Act & Assert
    EXPECT_THROW(CurrencyPair("USD/USD", 1, 1), string);
}
