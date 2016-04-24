// Copyright 2016 Pronina Maria
#include "include/RomanConverter.h"
#include <string>
#include <vector>
const std::vector<int> RomanConverter::values =
{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const std::vector<std::string> RomanConverter::symbols =
{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int RomanConverter::maxValue = 3999;

std::vector<std::string> RomanConverter::parseRoman(std::string roman) {
    int state = 0;
    std::vector<std::string> result;
    for (size_t i = 0; i < roman.length(); ++i) {
        switch (state) {
        case 0: {
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
        }
    }
    return result;
}

bool RomanConverter::checkNumeralsRepeats
        (std::vector<std::string> parsedRoman) {
    auto repeatedSymbol = parsedRoman.front();
    int repeatCount = 1;
    for (auto it = parsedRoman.begin() + 1; it != parsedRoman.end(); ++it) {
        if (*it == repeatedSymbol) {
            repeatCount++;
        } else {
            repeatedSymbol = *it;
            repeatCount = 1;
        }
        if (repeatCount > 3)
            return false;
    }
    return true;
}
bool RomanConverter::checkForInvalidNumerals
        (std::vector<std::string> parsedRoman) {
    auto prev = parsedRoman.front();
    for (auto it = parsedRoman.begin()+1; it != parsedRoman.end(); ++it) {
        if ((*it == "I")|| (*it == "X")|| (*it == "M")) {
            prev = *it;
            continue;
        }
        if (prev == *it)
            return false;
    }
    return true;
}
bool RomanConverter::checkNumeralsOrder
        (std::vector<std::string> parsedRoman) {
    auto previous = parsedRoman.front();
    for (auto it = parsedRoman.begin() + 1; it != parsedRoman.end(); ++it) {
        auto previousPos = find(symbols.begin(), symbols.end(), previous);
        auto currentPos = find(symbols.begin(), symbols.end(), *it);
        if (currentPos > previousPos)
            return false;
        previous = *it;
    }
    return true;
}

bool RomanConverter::checkForInvalidSymbols
        (std::vector<std::string> parsedRoman) {
    for (auto it = parsedRoman.begin(); it != parsedRoman.end(); ++it) {
        auto position = find(symbols.begin(), symbols.end(), *it);
        if (position == symbols.end())
            return false;
    }
    return true;
}

bool RomanConverter::checkArabNumber(int arab) {
    if ((arab <= 0) || (arab > maxValue))
        return false;
    return true;
}

bool RomanConverter::checkRomanNumber(std::string roman) {
    if (roman != roman) return false;
    if (roman.empty()) return false;
    auto parsedRoman = parseRoman(roman);
    if (!checkForInvalidSymbols(parsedRoman)) return false;
    if (!checkNumeralsRepeats(parsedRoman)) return false;
    if (!checkNumeralsOrder(parsedRoman)) return false;
    if (!checkForInvalidNumeralsRepeat(parsedRoman)) return false;
    return true;
}

int RomanConverter::convertRomanToArab(std::string roman) {
    if (!checkRomanNumber(roman)) return -1;
    int result = 0;
    auto parsedRoman = parseRoman(roman);
    for (auto it = parsedRoman.begin(); it != parsedRoman.end(); ++it) {
        size_t pos = 0;
        for (pos; pos < symbols.size(); pos++) {
            if (symbols[pos] == *it)
                break;
        }

        result += values[pos];
    }
    return result;
}

std::string RomanConverter::convertArabToRoman(int arab) {
    if (!checkArabNumber(arab)) return std::string();
    std::string result;
    for (size_t i = values.size() - 1; i >= 0 , arab > 0; i--) {
        while (arab >= values[i]) {
            result.append(symbols[i]);
            arab -= values[i];
        }
    }

    return result;
}



