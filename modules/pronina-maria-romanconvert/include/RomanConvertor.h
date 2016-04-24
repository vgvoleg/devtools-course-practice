// Copyright 2016 Pronina Maria
#include <vector>
class RomanConvertor
{
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
	static bool checkForInvalidNumeralsRepeat(std::vector<std::string> parsedRoman);
};

