// Copyright 2016 Voevodin Andrew

#include "include/Color_Converter.h"
#include <math.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

const vector<vector<double>> MatrCoefXYZToRGB{
    { 3.2404542, -1.5371385, -0.4985314 },
    { -0.9693660, 1.87560108, 0.0415560},
    { 0.0556434, -0.2040259, 1.0572252},
};

const vector<vector<double>> MatrCoefRGBToXYZ{
    { 0.4124564, 0.3575761, 0.1804375 },
    { 0.2126729, 0.7151522, 0.0721750 },
    { 0.0193339, 0.1191920, 0.9503041 },
};

const double Epsilon_In_lab = 0.008856;
const double Epsilon_In_RGBToXYZ = 0.04045;
const double Epsilon_In_XYZToRGB = 0.0031308;
const double MaxValueInRGB = 255.0;
const double NormalizingNumberXYZToRGB = 100.0;
const double Const_K_In_LAB = 7.787;
const vector<double> NormalizingVectorXYZToLAB { 95.047, 100.000, 108.883 };

bool color_converter::IncorrectSizeVector(const vector<double>& vector) {
    if (vector.size() != 3) return false;
    return true;
}

bool color_converter::IncorrectSizeVector(const vector<int>& vector) {
    if (vector.size() != 3) return false;
    return true;
}

bool color_converter::IsRGBVectorinRange(const vector<int>& rgb) {
    for (unsigned int i = 0; i < rgb.size(); i++)
        if ((rgb[i] > 255) || (rgb[i] < 0)) return false;
    return true;
}

bool color_converter::IsHSVVectorinRange(const vector<double>& hsv) {
    for (unsigned int i = 0; i < hsv.size(); i++)
        if ((hsv[i] > 1.0) || (hsv[i] < 0.0)) return false;
    return true;
}

bool color_converter::IsLABVectorinRange(const vector<int>& lab) {
    if ((lab[0] > 100) || (lab[0] < 0) ||
        (lab[1] > 128) || (lab[1] < -127) ||
        (lab[2] > 128) || (lab[2] < -127)) return false;
    return true;
}

vector<int> color_converter::XYZToRGB(const vector<double>& xyz) {
    vector<int> RGB(3);
    vector<double> norm_RGB(3);
    vector<double> norm_XYZ(3);
    for (unsigned int i = 0; i < norm_XYZ.size(); i++)
        norm_XYZ[i] = xyz[i] / NormalizingNumberXYZToRGB;

    for (unsigned int i = 0; i < norm_RGB.size(); i++)
        for (unsigned int j = 0; j < MatrCoefRGBToXYZ[i].size(); j++)
            norm_RGB[i] = norm_RGB[i] + norm_XYZ[j] * MatrCoefXYZToRGB[i][j];

    for (unsigned int i = 0; i < norm_XYZ.size(); i++) {
        if (norm_RGB[0] > Epsilon_In_XYZToRGB)
           norm_RGB[0] = 1.055 * pow(norm_RGB[0], (1.0 / 2.4)) - 0.055;
        else
            norm_RGB[0] = 12.92 * norm_RGB[0];
    }

    for (unsigned int i = 0; i < norm_XYZ.size(); i++)
        RGB[i] = static_cast<int>(norm_RGB[i] * MaxValueInRGB + 0.5);
    return RGB;
}

vector<int> color_converter::XYZToLAB(const vector<double>& xyz) {
    vector<int> LAB(3);
    vector<double> LAB_res(3);
    vector<double> norm_XYZ(3);
    for (unsigned int i = 0; i < norm_XYZ.size(); i++)
         norm_XYZ[i] = xyz[i] / NormalizingVectorXYZToLAB[i];

    for (unsigned int i = 0; i < norm_XYZ.size(); i++) {
        if (norm_XYZ[i] > Epsilon_In_lab)
            norm_XYZ[i] = pow(norm_XYZ[i], (1.0 / 3.0));
        else
            norm_XYZ[i] = (Const_K_In_LAB * norm_XYZ[i]) + (16.0 / 116.0);
    }

    LAB_res[0] = ((116.0 * norm_XYZ[1]) - 16.0);
    LAB_res[1] = (500.0 * (norm_XYZ[0] - norm_XYZ[1]));
    LAB_res[2] = (200.0 * (norm_XYZ[1] - norm_XYZ[2]));
    for (unsigned int i = 0; i < LAB.size(); i++) {
        if (LAB_res[i] < 0) {
             LAB[i] = static_cast<int>(LAB_res[i] - 0.5);
        } else {
            LAB[i] = static_cast<int>(LAB_res[i] + 0.5);
        }
    }
    return LAB;
}

vector<double> color_converter::RGBToXYZ(const vector<int>& rgb) {
    vector<double> _XYZ{ 0.0, 0.0, 0.0 };
    vector<double> norm_RGB(3);
    for (unsigned int i = 0; i < _XYZ.size(); i++)
         norm_RGB[i] = (1.0*rgb[i] / MaxValueInRGB);

    for (unsigned int i = 0; i < norm_RGB.size(); i++) {
        if (norm_RGB[i] > Epsilon_In_RGBToXYZ)
            norm_RGB[i] = pow(((norm_RGB[i] + 0.055) / 1.055), 2.4);
        else
            norm_RGB[i] = norm_RGB[i] / 12.92;
    }

    for (unsigned int i = 0; i < _XYZ.size(); i++)
        for (unsigned int j = 0; j < MatrCoefRGBToXYZ[i].size(); j++)
            _XYZ[i] += norm_RGB[j] *
                       NormalizingNumberXYZToRGB * MatrCoefRGBToXYZ[i][j];
    return _XYZ;
}

vector<double> color_converter::LABToXYZ(const vector<int>& lab) {
    vector<double> _XYZ(3);
    vector<double> norm_XYZ(3);

    norm_XYZ[1] = (1.0*lab[0] + 16.0) / 116.0;
    norm_XYZ[0] = 1.0*lab[1] / 500.0 + norm_XYZ[1];
    norm_XYZ[2] = norm_XYZ[1] - 1.0*lab[2] / 200.0;

    for (unsigned int i = 0; i < _XYZ.size(); i++) {
         if (pow(norm_XYZ[i], 3) > Epsilon_In_lab)
             norm_XYZ[i] = pow(norm_XYZ[i], 3.0);
         else
             norm_XYZ[1] = (norm_XYZ[i] - 16.0 / 116.0) / Const_K_In_LAB;
    }

    for (unsigned int i = 0; i < _XYZ.size(); i++)
    _XYZ[i] = NormalizingVectorXYZToLAB[i] * norm_XYZ[i];
    return _XYZ;
}

vector<int> color_converter::HSVToRGB(const vector<double>& hsv) {
    if (!IncorrectSizeVector(hsv)) throw IncorrectSizeOfVector();
    if (!IsHSVVectorinRange(hsv)) throw IncorrectValueOfHSV();
    vector<int> RGB_res(3);
    vector<double> norm_RGB(3);
    vector<double> intermediate_HSV(3);
    double H = hsv[0];

    if (hsv[1] == 0.0) {
       for (unsigned int i = 0; i < RGB_res.size(); i++)
            RGB_res[i] = hsv[2] * MaxValueInRGB;
    } else {
    double normalized_angle_H = H * 6.0;
    if (normalized_angle_H == 6.0) normalized_angle_H = 0.0;
    int normalized_basis_angle_H = static_cast<int>(normalized_angle_H);
    intermediate_HSV[0] = hsv[2] * (1.0 - hsv[1]);
    intermediate_HSV[1] = hsv[2] * (1.0 - hsv[1] *
                       (normalized_angle_H - normalized_basis_angle_H));
    intermediate_HSV[2] = hsv[2] * (1.0 - hsv[1] *
                      (1.0 - (normalized_angle_H - normalized_basis_angle_H)));
    if (normalized_basis_angle_H == 0) {
        norm_RGB[0] = hsv[2];
        norm_RGB[1] = intermediate_HSV[2];
        norm_RGB[2] = intermediate_HSV[0];
    } else if (normalized_basis_angle_H == 1) {
        norm_RGB[0] = intermediate_HSV[1];
        norm_RGB[1] = hsv[2];
        norm_RGB[2] = intermediate_HSV[0];
    } else if (normalized_basis_angle_H == 2) {
        norm_RGB[0] = intermediate_HSV[0];
        norm_RGB[1] = hsv[2];
        norm_RGB[2] = intermediate_HSV[2];
    } else if (normalized_basis_angle_H == 3) {
        norm_RGB[0] = intermediate_HSV[0];
        norm_RGB[1] = intermediate_HSV[1];
        norm_RGB[2] = hsv[2];
    } else if (normalized_basis_angle_H == 4) {
        norm_RGB[0] = intermediate_HSV[2];
        norm_RGB[1] = intermediate_HSV[0];
        norm_RGB[2] = hsv[2];
    } else {
        norm_RGB[0] = hsv[2];
        norm_RGB[1] = intermediate_HSV[0];
        norm_RGB[2] = intermediate_HSV[1];
    }
    for (unsigned int i = 0; i < RGB_res.size(); i++)
        RGB_res[i] = static_cast<int>(norm_RGB[i] * MaxValueInRGB);
    }
    return RGB_res;
}

vector<int> color_converter::LABToRGB(const vector<int>& lab) {
    if (!IncorrectSizeVector(lab)) throw IncorrectSizeOfVector();
    if (!IsLABVectorinRange(lab)) throw IncorrectValueOfLAB();
    return XYZToRGB(LABToXYZ(lab));
}


vector<double> color_converter::RGBToHSV(const vector<int>& rgb) {
    if (!IncorrectSizeVector(rgb)) throw IncorrectSizeOfVector();
    if (!IsRGBVectorinRange(rgb)) throw IncorrectValueOfRGB();
    vector<double> HSV(3);
    vector<int> RGB_res(rgb);
    vector<double> norm_RGB(3);
    vector<double> del_RGB(3);
    for (unsigned int i = 0; i < norm_RGB.size(); i++)
        norm_RGB[i] = (1.0*RGB_res[i] / MaxValueInRGB);

    double CurrentMinValueInRGB = 1.0 * RGB_res[0] / MaxValueInRGB;
    double CurrentMaxValueInRGB = 1.0 * RGB_res[0] / MaxValueInRGB;
    for (unsigned int i = 1; i < RGB_res.size(); i++) {
      if (1.0*RGB_res[i] / 255.0 < CurrentMinValueInRGB)
         CurrentMinValueInRGB = 1.0*RGB_res[i] / MaxValueInRGB;
      if (1.0*RGB_res[i] / 255.0 > CurrentMaxValueInRGB)
         CurrentMaxValueInRGB = 1.0*RGB_res[i] / MaxValueInRGB;
    }
    double DifMaxInRGB = CurrentMaxValueInRGB - CurrentMinValueInRGB;
    HSV[2] = CurrentMaxValueInRGB;
    if (DifMaxInRGB == 0) {
        HSV[0] = 0.0;
        HSV[1] = 0.0;
    } else {
        HSV[1] = DifMaxInRGB / CurrentMaxValueInRGB;

        for (unsigned int i = 0; i < del_RGB.size(); i++)
            del_RGB[i] = (((CurrentMaxValueInRGB - norm_RGB[i]) / 6.0) +
                           (DifMaxInRGB / 2.0)) / DifMaxInRGB;

        if (norm_RGB[0] == CurrentMaxValueInRGB)
            HSV[0] = del_RGB[2] - del_RGB[1];
        else if (norm_RGB[1] == CurrentMaxValueInRGB)
            HSV[0] = (1.0 / 3.0) + del_RGB[0] - del_RGB[2];
        else if (norm_RGB[2] == CurrentMaxValueInRGB)
            HSV[0] = (2.0 / 3.0) + del_RGB[1] - del_RGB[0];

        if (HSV[0] < 0.0) HSV[0] += 1.0;
        if (HSV[0] > 1.0) HSV[0] -= 1.0;
    }
    return HSV;
}

vector<double> color_converter::LABToHSV(const vector<int>& lab) {
    if (!IncorrectSizeVector(lab)) throw IncorrectSizeOfVector();
    if (!IsLABVectorinRange(lab)) throw IncorrectValueOfLAB();
    return RGBToHSV(LABToRGB(lab));
}


vector<int> color_converter::RGBToLAB(const vector<int>& rgb) {
    if (!IncorrectSizeVector(rgb)) throw IncorrectSizeOfVector();
    if (!IsRGBVectorinRange(rgb)) throw IncorrectValueOfRGB();
    return XYZToLAB(RGBToXYZ(rgb));
}

vector<int> color_converter::HSVToLAB(const vector<double>& hsv) {
    if (!IncorrectSizeVector(hsv)) throw IncorrectSizeOfVector();
    if (!IsHSVVectorinRange(hsv)) throw IncorrectValueOfHSV();
    return RGBToLAB(HSVToRGB(hsv));
}
