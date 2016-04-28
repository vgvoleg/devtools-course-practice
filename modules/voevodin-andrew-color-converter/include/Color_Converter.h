// Copyright 2016 Voevodin Andrew

#ifndef MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
#define MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_

#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

class IncorrectValueOfRGB :public std::runtime_error {
public:
    IncorrectValueOfRGB() :
        std::runtime_error("Value RGB is not correct, values - 0 to 255") {}
};

class IncorrectValueOfHSV :public std::runtime_error {
public:
    IncorrectValueOfHSV() :
        std::runtime_error("Value HSV is not correct, H: 0-1; S: 0-1; V: 0-1") {}
};

class IncorrectValueOfLAB :public std::runtime_error {
public:
    IncorrectValueOfLAB() :
        std::runtime_error("Value LAB is not correct,L:0-100;a:-127-128;b:-127-128") {}
};

class IncorrectSizeOfVector :public std::runtime_error {
public:
    IncorrectSizeOfVector() :
        std::runtime_error("Size vector is not correct, size must be equal to 3") {}
};

class color_converter {
 public:
    static vector<int> HSVToRGB(const vector<double> hsv);
    static vector<int> LABToRGB(const vector<int> lab);

    static vector<double> RGBToHSV(const vector<int> rgb);
    static vector<double> LABToHSV(const vector<int> lab);

    static vector<int> RGBToLAB(const vector<int> rgb);
    static vector<int> HSVToLAB(const vector<double> hsv);

 private:

    static bool IncorrectSizeVector(const vector<double> vector);
    static bool IncorrectSizeVector(const vector<int> vector);
    static bool IsRGBinRange(const vector<int> rgb);
    static bool IsHSVinRange(const vector<double> hsv);
    static bool IsLABinRange(const vector<int> lab);

    static vector<int> XYZToRGB(const vector<double> xyz);
    static vector<int> XYZToLAB(const vector<double> xyz);

    static vector<double> RGBToXYZ(const vector<int> rgb);
    static vector<double> LABToXYZ(const vector<int> lab);

};
#endif  // MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
