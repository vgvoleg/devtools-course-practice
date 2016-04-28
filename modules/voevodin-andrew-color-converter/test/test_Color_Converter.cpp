// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>
#include <math.h>
#include <vector>
#include <string>
#include "include/Color_Converter.h"


TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_HSVToRGB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(hsv), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(hsv), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(rgb), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_LABToRGB) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(lab), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_LABToHSV) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(lab), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector_In_RGBToHSV) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(rgb), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_HSVToRGB) {
    // Arrange
    vector<double> _vec1({ 5.0, 0.0, 0.0 });
    vector<double> _vec2({ 0.0, 5.0, 0.0 });
    vector<double> _vec3({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(_vec1), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter::HSVToRGB(_vec2), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter::HSVToRGB(_vec3), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_HSVToLAB) {
    // Arrange
    vector<double> _vec1({ 5.0, 0.0, 0.0 });
    vector<double> _vec2({ 0.0, 5.0, 0.0 });
    vector<double> _vec3({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(_vec1), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter::HSVToLAB(_vec2), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter::HSVToLAB(_vec3), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_LABToRGB) {
    // Arrange
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, 200, 0 });
    vector<int> _vec3({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(_vec1), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter::LABToRGB(_vec2), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter::LABToRGB(_vec3), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_LABToHSV) {
    // Arrange
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, 200, 0 });
    vector<int> _vec3({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(_vec1), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter::LABToHSV(_vec2), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter::LABToHSV(_vec3), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_RGBToLAB) {
    // Arrange
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, -1, 0 });
    vector<int> _vec3({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(_vec1), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter::RGBToLAB(_vec2), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter::RGBToLAB(_vec3), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_RGBToHSV) {
    // Arrange
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, -1, 0 });
    vector<int> _vec3({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(_vec1), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter::RGBToHSV(_vec2), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter::RGBToHSV(_vec3), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> rgb;
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb[0], 255);
    EXPECT_EQ(rgb[1], 0);
    EXPECT_EQ(rgb[2], 0);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToRGB) {
    // Arrange
    vector<int> lab{ 20, 10, 18 };
    vector<int> rgb;
    // Act
    rgb = color_converter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb[0], 69);
    EXPECT_EQ(rgb[1], 43);
    EXPECT_EQ(rgb[2], 23);
}


TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb({ 255, 0, 0 });
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_DOUBLE_EQ(hsv[0], 0.0);
    EXPECT_DOUBLE_EQ(hsv[1], 1.0);
    EXPECT_DOUBLE_EQ(hsv[2], 1.0);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> lab{ 20, 10, 10 };
    // Act
    hsv = color_converter::LABToHSV(lab);
    // Assert
    EXPECT_NEAR(hsv[0], 0.04167, 0.001);
    EXPECT_NEAR(hsv[1], 0.4776, 0.0001);
    EXPECT_NEAR(hsv[2], 0.2627, 0.0001);
}


TEST(Voevodin_Andrew_Color_Converter, Check_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> lab;
    // Act
    lab = color_converter::HSVToLAB(hsv);
    // Assert
    EXPECT_EQ(lab[0], 54);
    EXPECT_EQ(lab[1], 80);
    EXPECT_EQ(lab[2], 68);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 255, 67, 0 };
    vector<int> lab;
    // Act
    lab = color_converter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab[0], 58);
    EXPECT_EQ(lab[1], 69);
    EXPECT_EQ(lab[2], 69);
}
