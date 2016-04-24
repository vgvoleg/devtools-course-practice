// Copyright 2016 Pronina Maria
#ifndef MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#define MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#include <vector>
#include <string>
class RomanConverter {
    static const std::vector<int> values;
    static const std::vector<std::string> symbols;
    static const int maxValue;
 public:
    static bool CheckArabicNumber(const int& arabic);
    static bool CheckRomanNumber(std::string roman);    
    static int ConvertRomanToArabic(std::string roman);
    static std::string ConvertArabicToRoman(const int& arabic);

 private:
    static std::vector<std::string> ParseRoman(std::string roman);
    static bool CheckNumeralsRepeats(std::vector<std::string> parsed_roman);
    static bool CheckNumeralsOrder(std::vector<std::string> parsed_roman);
    static bool CheckForInvalidSymbols(std::vector<std::string> parsed_roman);
    static bool CheckForInvalidNumerals(std::vector<std::string> parsed_roman);
};
#endif  // MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
