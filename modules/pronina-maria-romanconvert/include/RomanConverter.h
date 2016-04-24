// Copyright 2016 Pronina Maria
#ifndef MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#define MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#include <vector>
#include <string>
class RomanConvertor {
    static const std::vector<int> values;
    static const std::vector<std::string> symbols;
    static const int maxValue;
 public:
    static bool checkArabNumber(int arab);
    static bool checkRomanNumber(std::string roman);
    static bool checkCharsRomanNumber(const char * roman);
    static int convertRomanToArab(std::string roman);
    static std::string convertArabToRoman(int arab);

 private:
    static std::vector<std::string> parseRoman(std::string roman);
    static bool checkNumeralsRepeats(std::vector<std::string> parsedRoman);
    static bool checkNumeralsOrder(std::vector<std::string> parsedRoman);
    static bool checkForInvalidSymbols(std::vector<std::string> parsedRoman);
    static bool checkForInvalidNumerals(std::vector<std::string> parsedRoman);
};

