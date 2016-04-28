// Copyright 2016 Voevodin Andrew

#ifndef MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
#define MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_

#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

class IncorrectInputNamespace: public std::runtime_error {
 public:
IncorrectInputNamespace() :
    std::runtime_error("Name_color_space is not correct, use: RGB, HSV, LAB") {}
};

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
 private:
    vector<double> *XYZ;

    bool RightSizeVector(const vector<double> _vector) const;
    bool RightSizeVector(const vector<int> _vector) const;
    bool IsRGBinRange(const vector<int> RGB) const;
    bool IsHSVinRange(const vector<double> HSV) const;
    bool IsLABinRange(const vector<int> LAB) const;

    vector<int> XYZtoRGB(const vector<double> _XYZ) const;
    vector<double> XYZtoHSV(const vector<double> _XYZ) const;
    vector<int> XYZtoLAB(const vector<double> _XYZ) const;

    vector<double> RGBToXYZ(const vector<int> RGB) const;
    vector<double> HSVtoXYZ(const vector<double> HSV) const;
    vector<double> LABtoXYZ(const vector<int> LAB) const;

    double FunctionLAB(const double s) const;

 public:
    color_converter(const vector<int> _Color, string _name_space);
    color_converter(const vector<double> HSV = {0.0, 0.0, 0.0});
    color_converter(const color_converter&  _color_vector);
    ~color_converter();
    color_converter& operator=(const color_converter&  _color_vector);

    vector<int> GetRGB() const;
    vector<double> GetHSV() const;
    vector<int> GetLAB() const;
    vector<double> GetXYZ() const;

    void SetRGBVector(const vector<int> RGB);
    void SetHSVVector(const vector<double> HSV);
    void SetLABVector(const vector<int> LAB);

    vector<int> HSVToRGB(const vector<double> HSV);
    vector<int> LABToRGB(const vector<int> LAB);

    vector<double> RGBToHSV(const vector<int> RGB);
    vector<double> LABToHSV(const vector<int> LAB);

    vector<int> RGBToLAB(const vector<int> RGB);
    vector<int> HSVToLAB(const vector<double> HSV);
};
#endif  // MODULES_VOEVODIN_ANDREW_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
