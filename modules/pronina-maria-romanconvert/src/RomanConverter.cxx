// Copyright 2016 Pronina Maria
#include "include/RomanConverter.h"
#include <string>
#include <vector>
#include <algorithm>
const std::vector<int> RomanConverter::values =
{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const std::vector<std::string> RomanConverter::symbols =
{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int RomanConverter::maxValue = 3999;

std::vector<std::string> RomanConverter::ParseRoman(std::string roman) {
    int state = 0;
    std::vector<std::string> result;
    for (size_t i = 0; i < roman.length(); ++i) {
        switch (state) {
        case 0: {
                if (i == roman.length() - 1) {
                    std::string tmp(1, roman[i]);
                    result.push_back(tmp);
                } else {
                    if (roman[i] == 'I') {
                        state = 1;
                    } else if (roman[i] == 'X') {
                        state = 2;
                    } else if (roman[i] == 'C') {
                        state = 3;
                    } else {
                        std::string tmp(1, roman[i]);
                        result.push_back(tmp);
                    }
                }
            }
            break;
        case 1: {
                if (roman[i] == 'V') {
                    result.push_back("IV");
                } else if (roman[i] == 'X') {
                    result.push_back("IX");
                } else {
                    result.push_back("I");
                    if (i != roman.length() - 1) {
                        if (roman[i] == 'I') {
                            state = 1;
                            break;
                        }
                        if (roman[i] == 'X') {
                            state = 2;
                            break;
                        }
                        if (roman[i] == 'C') {
                            state = 3;
                            break;
                        }
                    }
                    std::string tmp(1, roman[i]);
                    result.push_back(tmp);
                    state = 0;
                }
            }
            break;
        case 2: {
                if (roman[i] == 'L') {
                    result.push_back("XL");
                } else if (roman[i] == 'C') {
                    result.push_back("XC");
                } else {
                    result.push_back("X");
                    if (i != roman.length() - 1) {
                        if (roman[i] == 'I') {
                            state = 1;
                            continue;
                        }
                        if (roman[i] == 'X') {
                            state = 2;
                            continue;
                        }
                        if (roman[i] == 'C') {
                            state = 3;
                            continue;
                        }
                    }
                    std::string tmp(1, roman[i]);
                    result.push_back(tmp);
                    state = 0;
                }
            }
            break;
        case 3: {
                if (roman[i] == 'D') {
                    result.push_back("CD");
                } else if (roman[i] == 'M') {
                    result.push_back("CM");
                } else {
                    result.push_back("C");
                    if (i != roman.length() - 1) {
                        if (roman[i] == 'I') {
                            state = 1;
                            continue;
                        }
                        if (roman[i] == 'X') {
                            state = 2;
                            continue;
                        }
                        if (roman[i] == 'C') {
                            state = 3;
                            continue;
                        }
                    }
                    std::string tmp(1, roman[i]);
                    result.push_back(tmp);
                    state = 0;
                }
            }
            break;
        }
    }
    return result;
}

bool RomanConverter::CheckNumeralsRepeats
        (std::vector<std::string> parsed_roman) {
    auto repeated_symbol = parsed_roman.front();
    int repeat_count = 1;
    for (auto it = parsed_roman.begin() + 1; it != parsed_roman.end(); ++it) {
        if (*it == repeated_symbol) {
            repeat_count++;
        } else {
            repeated_symbol = *it;
            repeat_count = 1;
        }
        if (repeat_count > 3)
            return false;
    }
    return true;
}
bool RomanConverter::CheckForInvalidNumerals
        (std::vector<std::string> parsed_roman) {
    auto prev = parsed_roman.front();
    for (auto it = parsed_roman.begin()+1; it != parsed_roman.end(); ++it) {
        if ((*it == "I")|| (*it == "X")|| (*it == "M")|| (*it == "C")) {
            prev = *it;
            continue;
        }
        if (prev == *it)
            return false;
    }
    return true;
}
bool RomanConverter::CheckNumeralsOrder
        (std::vector<std::string> parsed_roman) {
    auto previous = parsed_roman.front();
    for (auto it = parsed_roman.begin() + 1; it != parsed_roman.end(); ++it) {
        auto previousPos = find(symbols.begin(), symbols.end(), previous);
        auto currentPos = find(symbols.begin(), symbols.end(), *it);
        if (currentPos > previousPos)
            return false;
        previous = *it;
    }
    return true;
}

bool RomanConverter::CheckForInvalidSymbols
        (std::vector<std::string> parsed_roman) {
    for (auto it = parsed_roman.begin(); it != parsed_roman.end(); ++it) {
        auto position = find(symbols.begin(), symbols.end(), *it);
        if (position == symbols.end())
            return false;
    }
    return true;
}

bool RomanConverter::CheckArabicNumber(const int& arabic) {
    if ((arabic <= 0) || (arabic > maxValue))
        return false;
    return true;
}

bool RomanConverter::CheckRomanNumber(std::string roman) {
    if (roman.empty()) return false;
    std::vector<std::string> parsed_roman = ParseRoman(roman);
    if (!CheckForInvalidSymbols(parsed_roman)) return false;
    if (!CheckNumeralsRepeats(parsed_roman)) return false;
    if (!CheckNumeralsOrder(parsed_roman)) return false;
    if (!CheckForInvalidNumerals(parsed_roman)) return false;
    return true;
}

int RomanConverter::ConvertRomanToArabic(std::string roman) {
    if (!CheckRomanNumber(roman)) return -1;
    int result = 0;
    std::vector<std::string> parsedRoman = ParseRoman(roman);
    for (auto it = parsedRoman.begin(); it != parsedRoman.end(); ++it) {
        auto  index_of_symbol = find(symbols.begin(), symbols.end(), *it)
                                - symbols.begin();
        result += values[index_of_symbol];
    }
    return result;
}

std::string RomanConverter::ConvertArabicToRoman(const int& arabic) {
    if (!CheckArabicNumber(arabic)) return std::string();
    int copy_arabic = arabic;
    std::string result;
    for (size_t i = values.size(); i != 0; i--) {
        if (copy_arabic <= 0) break;
        while (copy_arabic >= values[i-1]) {
            result.append(symbols[i-1]);
            copy_arabic -= values[i-1];
        }
    }

    return result;
}



