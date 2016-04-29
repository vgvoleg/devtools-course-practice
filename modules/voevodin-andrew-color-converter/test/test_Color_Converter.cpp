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

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB1) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 255, 0, 0};
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB2) {
    // Arrange
    vector<double> hsv{ 0.167, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB3) {
    // Arrange
    vector<double> hsv{ 0.34, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB4) {
    // Arrange
    vector<double> hsv{ 0.51, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB5) {
    // Arrange
    vector<double> hsv{ 0.67, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB6) {
    // Arrange
    vector<double> hsv{ 0.85, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = color_converter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToRGB1) {
    // Arrange
    vector<int> lab{ 20, 10, 18 };
    vector<int> rgb;
    vector<int> rgb_res{ 69, 42, 22 };
    // Act
    rgb = color_converter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToRGB2) {
    // Arrange
    vector<int> lab{ 43, 0, 0 };
    vector<int> rgb;
    vector<int> rgb_res{ 102, 102, 102 };
    // Act
    rgb = color_converter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV1) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 255, 0, 0 };
    vector<double> hsv_res{ 0.0, 1.0, 1.0 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_EQ(hsv, hsv_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV2) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 0, 0 };
    vector<double> hsv_res{ 0.0, 0.0, 0.0 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_EQ(hsv, hsv_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV3) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 1, 0, 0 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.0, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV4) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 1, 0 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.33333333, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV5) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 0, 1 };
    // Act
    hsv = color_converter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.666667, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> lab{ 20, 10, 10 };
    // Act
    hsv = color_converter::LABToHSV(lab);
    // Assert
    EXPECT_NEAR(hsv[0], 0.040404, 0.00001);
    EXPECT_NEAR(hsv[1], 0.492537, 0.00001);
    EXPECT_NEAR(hsv[2], 0.262745, 0.00001);
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

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB1) {
    // Arrange
    vector<int> rgb{ 255, 67, 0 };
    vector<int> lab;
    vector<int> lab_res{ 57, 68, 69 };
    // Act
    lab = color_converter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab, lab_res);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB2) {
    // Arrange
    vector<int> rgb{ 0, 12, 0 };
    vector<int> lab;
    vector<int> lab_res{ 2, -5, 3 };
    // Act
    lab = color_converter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab, lab_res);
}
