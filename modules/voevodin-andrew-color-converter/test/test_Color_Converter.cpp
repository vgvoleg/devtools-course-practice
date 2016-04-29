// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>
#include <math.h>
#include <vector>
#include <string>
#include "include/Color_Converter.h"


TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_HSVToRGB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(hsv), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(hsv), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(rgb), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_LABToRGB) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(lab), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_LABToHSV) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(lab), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_Size_In_RGBToHSV) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(rgb), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_H_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_S_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_V_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_H_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_S_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_V_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_L_LABToRGB) {
    // Arrange
    vector<int> lab({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_A_In_LABToRGB) {
    // Arrange
    vector<int> lab({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_B_In_LABToRGB) {
    // Arrange
    vector<int> lab({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_L_In_LABToHSV) {
    // Arrange
    vector<int> lab({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_A_In_LABToHSV) {
    // Arrange
    vector<int> lab({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_B_In_LABToHSV) {
    // Arrange
    vector<int> lab({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_R_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_G_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_B_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_R_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(rgb), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_G_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(rgb), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Unexpected_Incorrect_B_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter::RGBToHSV(rgb), IncorrectValueOfRGB);
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
    vector<int> lab_res{ 53, 80, 67 };
    // Act
    lab = color_converter::HSVToLAB(hsv);
    // Assert
    EXPECT_EQ(lab, lab_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 255, 67, 0 };
    vector<int> lab;
    vector<int> lab_res{ 57, 68, 69 };
    // Act
    lab = color_converter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab, lab_res);
}
