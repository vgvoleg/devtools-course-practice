// Copyright 2016 Voevodin Andrew

#include "include/Color_Converter.h"
#include <math.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool color_converter::RightSizeVector(const vector<double> _vector) const {
    if (_vector.size() != 3) return false;
    return true;
}

bool color_converter::RightSizeVector(const vector<int> _vector) const {
    if (_vector.size() != 3) return false;
    return true;
}

bool color_converter::IsRGBinRange(const vector<int> RGB) const {
    for (unsigned int i = 0; i < RGB.size(); i++)
        if ((RGB[i] > 255) || (RGB[i] < 0)) return false;
    return true;
}

bool color_converter::IsHSVinRange(const vector<double> HSV) const {
    if ((HSV[0] > 1.0) || (HSV[0] < 0.0) ||
       (HSV[1] > 1.0) || (HSV[1] < 0.0) ||
       (HSV[2] > 1.0) || (HSV[2] < 0.0)) return false;
    return true;
}

bool color_converter::IsLABinRange(const vector<int> LAB) const {
    if ((LAB[0] > 100) || (LAB[0] < 0) ||
        (LAB[1] > 128) || (LAB[1] < -127) ||
        (LAB[2] > 128) || (LAB[2] < -127)) return false;
    return true;
}

double color_converter::FunctionLAB(const double s) const {
    if (s > pow(6.0 / 29.0, 3)) return pow(s, 1.0 / 3.0);
    return (1.0 / 3.0)*pow(29.0 / 6.0, 2)*s + 4.0 / 29.0;
}

vector<int> color_converter::XYZtoRGB(const vector<double> _XYZ) const {
    vector<int> RGB(3);

    double var_X = _XYZ[0] / 100.0;
    double var_Y = _XYZ[1] / 100.0;
    double var_Z = _XYZ[2] / 100.0;

    double var_R = var_X *  3.2404542 + var_Y * (-1.5371385)
           + var_Z * (-0.4985314);
    double var_G = var_X * (-0.9693660) + var_Y *  1.87560108
           + var_Z *  0.0415560;
    double var_B = var_X *  0.0556434 + var_Y * (-0.2040259)
           + var_Z *  1.0572252;

    if (var_R > 0.0031308) var_R = 1.055 * pow(var_R, (1.0 / 2.4)) - 0.055;
    else
        var_R = 12.92 * var_R;
    if (var_G > 0.0031308) var_G = 1.055 * pow(var_G, (1.0 / 2.4)) - 0.055;
    else
        var_G = 12.92 * var_G;
    if (var_B > 0.0031308) var_B = 1.055 * pow(var_B, (1.0 / 2.4)) - 0.055;
    else
        var_B = 12.92 * var_B;

    RGB[0] = floor(var_R * 255 +0.9);
    RGB[1] = floor(var_G * 255 +0.9);
    RGB[2] = floor(var_B * 255 +0.9);

    return RGB;
}

vector<double> color_converter::XYZtoHSV(const vector<double> _XYZ) const {
    vector<double> HSV(3), RGB(3);
    vector<int> RGB1(3);
    double H = 0.0;
    double S = 0.0;
    RGB1 = XYZtoRGB(_XYZ);
    double var_R = (1.0*RGB1[0] / 255.0);
    double var_G = (1.0*RGB1[1] / 255.0);
    double var_B = (1.0*RGB1[2] / 255.0);

    double var_Min = 1.0 * RGB1[0] / 255.0;
    double var_Max = 1.0 * RGB1[0] / 255.0;
    for (unsigned int i = 1; i < RGB1.size(); i++) {
        if (1.0*RGB1[i] / 255.0 < var_Min) var_Min = 1.0*RGB1[i] / 255.0;
        if (1.0*RGB1[i] / 255.0 > var_Max) var_Max = 1.0*RGB1[i] / 255.0;
    }
    double del_Max = var_Max - var_Min;

    double V = var_Max;

    if (del_Max == 0) {
       H = 0;
       S = 0;
     } else {
           S = del_Max / var_Max;

           double del_R = (((var_Max - var_R) / 6.0) +
                 (del_Max / 2.0)) / del_Max;
           double del_G = (((var_Max - var_G) / 6.0) +
                 (del_Max / 2.0)) / del_Max;
           double del_B = (((var_Max - var_B) / 6.0) +
                 (del_Max / 2.0)) / del_Max;

           if (var_R == var_Max) H = del_B - del_G;
           else if (var_G == var_Max) H = (1.0 / 3.0) + del_R - del_B;
           else if (var_B == var_Max) H = (2.0 / 3.0) + del_G - del_R;

           if (H < 0.0) H += 1.0;
           if (H > 1.0) H -= 1.0;
    }
    HSV[0] = H;
    HSV[1] = S;
    HSV[2] = V;

    return HSV;
}

vector<int> color_converter::XYZtoLAB(const vector<double> _XYZ) const {
    vector<int> LAB(3);
    vector<double> LAB1(3);
    double ref_X = 95.047;
    double ref_Y = 100.000;
    double ref_Z = 108.883;
    double var_X = _XYZ[0] / ref_X;
    double var_Y = _XYZ[1] / ref_Y;
    double var_Z = _XYZ[2] / ref_Z;

    if (var_X > 0.008856) var_X = pow(var_X, (1.0 / 3.0));
    else
        var_X = (7.787 * var_X) + (16.0 / 116.0);
    if (var_Y > 0.008856) var_Y = pow(var_Y , (1.0 / 3.0));
    else
        var_Y = (7.787 * var_Y) + (16.0 / 116.0);
    if (var_Z > 0.008856) var_Z = pow(var_Z , (1.0 / 3.0));
    else
        var_Z = (7.787 * var_Z) + (16.0 / 116.0);

    LAB1[0] = ((116.0 * var_Y) - 16.0);
    LAB1[1] = (500.0 * (var_X - var_Y));
    LAB1[2] = (200.0 * (var_Y - var_Z));
    for (unsigned int i = 0; i < LAB.size(); i++) {
        if (LAB1[i] < 0) {
           LAB[i] = static_cast<int>(LAB1[i] - 0.9);
        } else {
            LAB[i] = static_cast<int>(LAB1[i] + 0.9);
        }
    }
    return LAB;
}

vector<double> color_converter::RGBToXYZ(const vector<int> RGB) const {
    vector<double> _XYZ(3);
    double var_R = (1.0*RGB[0] / 255.0);
    double var_G = (1.0*RGB[1] / 255.0);
    double var_B = (1.0*RGB[2] / 255.0);

    if (var_R > 0.04045) var_R = pow(((var_R + 0.055) / 1.055) , 2.4);
    else
        var_R = var_R / 12.92;
    if (var_G > 0.04045) var_G = pow(((var_G + 0.055) / 1.055) , 2.4);
    else
        var_G = var_G / 12.92;
    if (var_B > 0.04045) var_B = pow(((var_B + 0.055) / 1.055) , 2.4);
    else
        var_B = var_B / 12.92;
    var_R = var_R * 100.0;
    var_G = var_G * 100.0;
    var_B = var_B * 100.0;

    _XYZ[0] = var_R * 0.4124564 + var_G * 0.3575761 + var_B * 0.1804375;
    _XYZ[1] = var_R * 0.2126729 + var_G * 0.7151522 + var_B * 0.0721750;
    _XYZ[2] = var_R * 0.0193339 + var_G * 0.1191920 + var_B * 0.9503041;
    return _XYZ;
}

vector<double> color_converter::HSVtoXYZ(const vector<double> HSV) const {
    vector<double> RGB(3);
    vector<int> RGB1(3);
    double var_r;
    double var_g;
    double var_b;
    double H = HSV[0];
    if (HSV[1] == 0.0) {
        RGB1[0] = HSV[2] * 255.0;
        RGB1[1] = HSV[2] * 255.0;
        RGB1[2] = HSV[2] * 255.0;
     } else {
        double var_h = H * 6.0;
        if (var_h == 6.0) var_h = 0.0;
        int var_i = static_cast<int>(var_h);
        double var_1 = HSV[2] * (1.0 - HSV[1]);
        double var_2 = HSV[2] * (1.0 - HSV[1] * (var_h - var_i));
        double var_3 = HSV[2] * (1.0 - HSV[1] * (1.0 - (var_h - var_i)));
        double V = HSV[2];
        if (var_i == 0) {
            var_r = V; var_g = var_3; var_b = var_1;
        } else if (var_i == 1) {
            var_r = var_2; var_g = V; var_b = var_1;
        } else if (var_i == 2) {
            var_r = var_1; var_g = V; var_b = var_3;
        } else if (var_i == 3) {
            var_r = var_1; var_g = var_2; var_b = V;
        } else if (var_i == 4) {
            var_r = var_3; var_g = var_1; var_b = V;
        } else {
            var_r = V; var_g = var_1; var_b = var_2;
        }
        RGB1[0] = static_cast<int>(var_r * 255.0);
        RGB1[1] = static_cast<int>(var_g * 255.0);
        RGB1[2] = static_cast<int>(var_b * 255.0);
    }
    return RGBToXYZ(RGB1);
}

vector<double> color_converter::LABtoXYZ(const vector<int> LAB) const {
    vector<double> _XYZ(3);
    double  var_Y = (1.0*LAB[0] +16.0) / 116.0;
    double  var_X =  1.0*LAB[1] / 500.0 + var_Y;
    double  var_Z = var_Y - 1.0*LAB[2] / 200.0;

    if (pow(var_Y, 3) > 0.008856) var_Y = pow(var_Y, 3.0);
    else
        var_Y = (var_Y - 16.0 / 116.0) / 7.787;
    if (pow(var_X, 3) > 0.008856) var_X = pow(var_X, 3.0);
    else
        var_X = (var_X - 16.0 / 116.0) / 7.787;
    if (pow(var_Z, 3) > 0.008856) var_Z = pow(var_Z, 3.0);
    else
        var_Z = (var_Z - 16.0 / 116.0) / 7.787;
    double ref_X = 95.047;
    double ref_Y = 100.000;
    double ref_Z = 108.883;
    _XYZ[0] = ref_X * var_X;
    _XYZ[1] = ref_Y * var_Y;
    _XYZ[2] = ref_Z * var_Z;
    return _XYZ;
}


color_converter::color_converter(const vector<int> _Color, string _name_space) {
    XYZ = new vector<double>(3);
    if (!RightSizeVector(_Color)) {
       throw IncorrectSizeOfVector();
    } else {
        if (_name_space == "RGB") {
            if (!IsRGBinRange(_Color)) throw IncorrectValueOfRGB();
            else
                *XYZ = RGBToXYZ(_Color);
        } else if (_name_space == "LAB") {
            if (!IsLABinRange(_Color)) throw IncorrectValueOfLAB();
            else
                *XYZ = LABtoXYZ(_Color);
        } else {
             throw IncorrectInputNamespace();
        }
    }
}

color_converter::color_converter(const vector<double> HSV) {
    XYZ = new vector<double>(3);
    *XYZ = { 0.0, 0.0, 0.0 };
    if (!RightSizeVector(HSV)) {
       throw IncorrectSizeOfVector();
    } else {
            if (!IsHSVinRange(HSV)) throw IncorrectValueOfHSV();
            else
                *XYZ = HSVtoXYZ(HSV);
        }
}

color_converter::color_converter(const color_converter& _color_vector) {
    XYZ = new vector<double>(3);
    *XYZ = *_color_vector.XYZ;
}

color_converter::~color_converter() {}

color_converter& color_converter::
                          operator=(const color_converter&  _color_vector) {
    *XYZ = *_color_vector.XYZ;
    return *this;
}

vector<int> color_converter::GetRGB() const {
    return XYZtoRGB(*XYZ);
}

vector<double> color_converter::GetHSV() const {
    return XYZtoHSV(*XYZ);
}

vector<int> color_converter::GetLAB() const {
    return XYZtoLAB(*XYZ);
}

vector<double> color_converter::GetXYZ() const {
    return *XYZ;
}

void color_converter::SetRGBVector(const vector<int> RGB) {
    if (!RightSizeVector(RGB)) {
       throw IncorrectSizeOfVector();
    } else {
        if (!IsRGBinRange(RGB)) throw IncorrectValueOfRGB();
        else
            *XYZ = RGBToXYZ(RGB);
    }
}

void color_converter::SetHSVVector(const vector<double> HSV) {
    if (!RightSizeVector(HSV)) {
       throw IncorrectSizeOfVector();
    } else {
        if (!IsHSVinRange(HSV)) throw IncorrectValueOfHSV();
        else
            *XYZ = HSVtoXYZ(HSV);
    }
}

void color_converter::SetLABVector(const vector<int> LAB) {
    if (!RightSizeVector(LAB)) {
       throw IncorrectSizeOfVector();
    } else {
        if (!IsLABinRange(LAB)) throw IncorrectValueOfLAB();
        else
            *XYZ = LABtoXYZ(LAB);
    }
}

vector<int> color_converter::HSVToRGB(const vector<double> HSV) {
    SetHSVVector(HSV);
    return GetRGB();
}

vector<int> color_converter::LABToRGB(const vector<int> LAB) {
    SetLABVector(LAB);
    return GetRGB();
}


vector<double> color_converter::RGBToHSV(const vector<int> RGB) {
    SetRGBVector(RGB);
    return GetHSV();
}

vector<double> color_converter::LABToHSV(const vector<int> LAB) {
    SetLABVector(LAB);
    return GetHSV();
}


vector<int> color_converter::RGBToLAB(const vector<int> RGB) {
    SetRGBVector(RGB);
    return GetLAB();
}

vector<int> color_converter::HSVToLAB(const vector<double> HSV) {
    SetHSVVector(HSV);
    return GetLAB();
}
