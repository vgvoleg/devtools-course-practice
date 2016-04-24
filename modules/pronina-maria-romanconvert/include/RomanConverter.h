// Copyright 2016 Pronina Maria
#ifndef MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#define MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
#include <vector>
#include <string>
using namespace std;
class RomanConverter {
    static const vector<int> values;
    static const vector<string> symbols;
    static const int maxValue;
 public:
    static bool CheckArabicNumber(int arabic);
    static bool CheckRomanNumber(string roman);    
    static int ConvertRomanToArabic(string roman);
    static string ConvertArabicToRoman(int arabic);

 private:
    static vector<string> ParseRoman(string roman);
    static bool CheckNumeralsRepeats(vector<string> parsed_roman);
    static bool CheckNumeralsOrder(vector<string> parsed_roman);
    static bool CheckForInvalidSymbols(vector<string> parsed_roman);
    static bool CheckForInvalidNumerals(vector<string> parsed_roman);
};
#endif  // MODULES_PRONINA_MARIA_ROMANCONVERT_INCLUDE_ROMANCONVERTER_H_
