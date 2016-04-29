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

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_In_HSVToRGB) {
    // Arrange
    vector<double> _vec({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_In_HSVToRGB) {
    // Arrange
    vector<double> _vec({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_In_HSVToRGB) {
    // Arrange
    vector<double> _vec({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_In_HSVToLAB) {
    // Arrange
    vector<double> _vec({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_In_HSVToLAB) {
    // Arrange
    vector<double> _vec({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_In_HSVToLAB) {
    // Arrange
    vector<double> _vec({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(_vec), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_Vector_LABToRGB) {
    // Arrange
    vector<int> _vec({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_Vector_LABToRGB) {
    // Arrange
    vector<int> _vec({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_Vector_LABToRGB) {
    // Arrange
    vector<int> _vec({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_Vector_LABToHSV) {
    // Arrange
    vector<int> _vec({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_Vector_LABToHSV) {
    // Arrange
    vector<int> _vec({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_Vector_LABToHSV) {
    // Arrange
    vector<int> _vec({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(_vec), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_Vector_RGBToLAB) {
    // Arrange
    vector<int> _vec({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_Vector_RGBToLAB) {
    // Arrange
    vector<int> _vec({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_Vector_RGBToLAB) {
    // Arrange
    vector<int> _vec({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value1_Vector_RGBToHSV) {
    // Arrange
    vector<int> _vec({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value2_Vector_RGBToHSV) {
    // Arrange
    vector<int> _vec({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value3_Vector_RGBToHSV) {
    // Arrange
    vector<int> _vec({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(_vec), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 255, 0, 0};
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToRGB) {
    // Arrange
    vector<int> lab{ 20, 10, 18 };
    vector<int> rgb;
    vector<int> rgb_res{ 197, 6, 2 };
    // Act
    rgb = color_converter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}


TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 255, 0, 0 };
    vector<double> hsv_res{ 0.0, 1.0, 1.0 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_EQ(hsv, hsv_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> lab{ 20, 10, 10 };
    // Act
    hsv = color_converter::LABToHSV(lab);
    // Assert
    EXPECT_NEAR(hsv[0], 0.001745, 0.00001);
    EXPECT_NEAR(hsv[1], 0.979487, 0.00001);
    EXPECT_NEAR(hsv[2], 0.7647, 0.00001);
}


TEST(Voevodin_Andrew_Color_Converter, Check_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> lab;
    // Act
    lab = color_converter::HSVToLAB(hsv);
    // Assert
    EXPECT_EQ(lab[0], 53);
    EXPECT_EQ(lab[1], 80);
    EXPECT_EQ(lab[2], 67);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 255, 67, 0 };
    vector<int> lab;
    // Act
    lab = color_converter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab[0], 57);
    EXPECT_EQ(lab[1], 68);
    EXPECT_EQ(lab[2], 69);
}
