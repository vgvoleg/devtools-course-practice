// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>
#include <math.h>
#include <vector>
#include <string>
#include "include/Color_Converter.h"


TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Vector) {
    // Arrange
    vector<int> _vec({ 0, 0, 0, 0 });
    // Act & Assert
    EXPECT_THROW(color_converter(_vec, "RGB"), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_HSV) {
    // Arrange
    vector<double> _vec1({ 370.0, 0.0, 0.0 });
    vector<double> _vec2({0.0, 5.0, 0.0});
    vector<double> _vec3({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(color_converter c1(_vec1), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter c2(_vec2), IncorrectValueOfHSV);
    EXPECT_THROW(color_converter c3(_vec3), IncorrectValueOfHSV);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_LAB) {
    // Arrange
    vector<int> _vec1({-1, 0, 0});
    vector<int> _vec2({ 0, 200, 0 });
    vector<int> _vec3({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(color_converter(_vec1, "LAB"), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter(_vec2, "LAB"), IncorrectValueOfLAB);
    EXPECT_THROW(color_converter(_vec3, "LAB"), IncorrectValueOfLAB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Name_Space) {
    // Arrange
    vector<int> _vec1({0, 0, 0});
    // Act & Assert
    EXPECT_THROW(color_converter(_vec1, "LUV"), IncorrectInputNamespace);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Size_Vector_HSV) {
    // Arrange
    vector<double> _vec1({ 0.0, 0.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(color_converter c1(_vec1), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Incorrect_Value_In_Vector_RGB) {
    // Arrange
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, -1, 0 });
    vector<int> _vec3({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(color_converter(_vec1, "RGB"), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter(_vec2, "RGB"), IncorrectValueOfRGB);
    EXPECT_THROW(color_converter(_vec3, "RGB"), IncorrectValueOfRGB);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Copy_Constructor) {
    // Arrange
    vector<int> _vec1({1, 0, 0});
    color_converter cc(_vec1, "RGB");
    // Act
    color_converter cc1(cc);
    // Assert
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[0], cc1.GetXYZ()[0]);
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[1], cc1.GetXYZ()[1]);
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[2], cc1.GetXYZ()[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Check_Operator_Equal) {
    // Arrange
    vector<double> _vec1({ 1.0, 0.0, 0.0 });
    color_converter cc(_vec1);

    // Act
    color_converter cc1 = cc;

    // Assert
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[0], cc1.GetXYZ()[0]);
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[1], cc1.GetXYZ()[1]);
    EXPECT_DOUBLE_EQ(cc.GetXYZ()[2], cc1.GetXYZ()[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Check_GetRGB) {
    // Arrange
    vector<int> _vec1({255, 255, 255});
    vector<int> _vec2({7, 7, 13});
    vector<int> _vec3;
    vector<int> _vec4;
    color_converter cc(_vec1, "RGB");
    color_converter cc1(_vec2, "RGB");

    // Act
    _vec3 = cc.GetRGB();
    _vec4 = cc1.GetRGB();
    // Assert
    EXPECT_DOUBLE_EQ(_vec1[0], _vec3[0]);
    EXPECT_DOUBLE_EQ(_vec1[1], _vec3[1]);
    EXPECT_DOUBLE_EQ(_vec1[2], _vec3[2]);

    EXPECT_DOUBLE_EQ(_vec2[0], _vec4[0]);
    EXPECT_DOUBLE_EQ(_vec2[1], _vec4[1]);
    EXPECT_DOUBLE_EQ(_vec2[2], _vec4[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Check_GetHSV) {
    // Arrange
   vector<double> _vec1({ 0.0, 1.0, 1.0 });
   vector<double> _vec2;
   vector<double> _vec3({ 70.0, 1.0, 1.0 });
   vector<double> _vec4;
   vector<double> _vec5({ 140.0, 1.0, 1.0 });
   vector<double> _vec6;
   vector<double> _vec7({ 190.0, 1.0, 1.0 });
   vector<double> _vec8;
   vector<double> _vec9({ 260.0, 1.0, 1.0 });
   vector<double> _vec10;
   vector<double> _vec11({ 320.0, 1.0, 1.0 });
   vector<double> _vec12;
   color_converter cc(_vec1);
   color_converter cc1(_vec3);
   color_converter cc2(_vec5);
   color_converter cc3(_vec7);
   color_converter cc4(_vec9);
   color_converter cc5(_vec11);
    // Act
   _vec2 = cc.GetHSV();
   _vec4 = cc.GetHSV();
   _vec6 = cc.GetHSV();
   _vec8 = cc.GetHSV();
   _vec10 = cc.GetHSV();
   _vec12 = cc.GetHSV();
    // Assert
   EXPECT_DOUBLE_EQ(_vec1[0], _vec2[0]);
   EXPECT_DOUBLE_EQ(_vec1[1], _vec2[1]);
   EXPECT_DOUBLE_EQ(_vec1[2], _vec2[2]);

   EXPECT_DOUBLE_EQ(_vec3[0], _vec4[0]);
   EXPECT_DOUBLE_EQ(_vec3[1], _vec4[1]);
   EXPECT_DOUBLE_EQ(_vec3[2], _vec4[2]);

   EXPECT_DOUBLE_EQ(_vec5[0], _vec6[0]);
   EXPECT_DOUBLE_EQ(_vec5[1], _vec6[1]);
   EXPECT_DOUBLE_EQ(_vec5[2], _vec6[2]);

   EXPECT_DOUBLE_EQ(_vec7[0], _vec8[0]);
   EXPECT_DOUBLE_EQ(_vec7[1], _vec8[1]);
   EXPECT_DOUBLE_EQ(_vec7[2], _vec8[2]);

   EXPECT_DOUBLE_EQ(_vec9[0], _vec10[0]);
   EXPECT_DOUBLE_EQ(_vec9[1], _vec10[1]);
   EXPECT_DOUBLE_EQ(_vec9[2], _vec10[2]);

   EXPECT_DOUBLE_EQ(_vec11[0], _vec12[0]);
   EXPECT_DOUBLE_EQ(_vec11[1], _vec12[1]);
   EXPECT_DOUBLE_EQ(_vec11[2], _vec12[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Check_GetLAB) {
    // Arrange
    vector<int> _vec1({2, 2, 2});
    vector<int> _vec2;
    color_converter cc(_vec1, "LAB");

    // Act
    _vec2 = cc.GetLAB();

    // Assert
    EXPECT_DOUBLE_EQ(_vec1[0], _vec2[0]);
    EXPECT_DOUBLE_EQ(_vec1[1], _vec2[1]);
    EXPECT_DOUBLE_EQ(_vec1[2], _vec2[2]);
}



TEST(Voevodin_Andrew_Color_Converter, Check_SetRGBVector) {
    // Arrange
    vector<double> _vec1({ 0.0, 1.0, 1.0 });
    vector<int> _vec2({ 1, 1, 1 });
    color_converter cc(_vec1);

    // Act
    cc.SetRGBVector(_vec2);

    // Assert
    EXPECT_DOUBLE_EQ(cc.GetRGB()[0], _vec2[0]);
    EXPECT_DOUBLE_EQ(cc.GetRGB()[1], _vec2[1]);
    EXPECT_DOUBLE_EQ(cc.GetRGB()[2], _vec2[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Size_Vec_In_SetRGBVec) {
    // Arrange
    vector<int> _vec1({ 0, 0, 0 });
    vector<int> _vec2({ 0, 0, 0, 0 });
    color_converter cc(_vec1, "RGB");
    // Act & Assert
    EXPECT_THROW(cc.SetRGBVector(_vec2), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Value_Vec_RGB_SetRGBVec) {
    // Arrange
    vector<int> _vec({ 0, 0, 0 });
    color_converter cc(_vec, "RGB");
    vector<int> _vec1({-1, 0, 0});
    vector<int> _vec2({ 0, -1, 0 });
    vector<int> _vec3({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(cc.SetRGBVector(_vec1), IncorrectValueOfRGB);
    EXPECT_THROW(cc.SetRGBVector(_vec2), IncorrectValueOfRGB);
    EXPECT_THROW(cc.SetRGBVector(_vec3), IncorrectValueOfRGB);
}



TEST(Voevodin_Andrew_Color_Converter, Check_SetHSVVector) {
    // Arrange
    vector<double> _vec1({ 1.0, 1.0, 1.0 });
    vector<double> _vec2({ 10.0, 1.0, 1.0 });
    color_converter cc(_vec1);

    // Act
    cc.SetHSVVector(_vec2);

    // Assert
    EXPECT_DOUBLE_EQ(cc.GetHSV()[0], 10.0);
    EXPECT_DOUBLE_EQ(cc.GetHSV()[1], 1.0);
    EXPECT_DOUBLE_EQ(cc.GetHSV()[2], 1.0);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Size_Vec_In_SetHSVVector) {
    // Arrange
    vector<double> _vec1({ 0.0, 0.0, 0.0 });
    vector<double> _vec({ 0.0, 0.0, 0.0, 0.0 });
    color_converter cc(_vec1);
    // Act & Assert
    EXPECT_THROW(cc.SetHSVVector(_vec), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Value_Vec_In_SetHSVVector) {
    // Arrange
    vector<int> _vec({ 0, 0, 0 });
    vector<double> _vec1({ -1.0, 0.0, 0.0 });
    vector<double> _vec2({ 0.0, 5.0, 0.0 });
    vector<double> _vec3({ 0.0, 0.0, 5.0 });
    color_converter cc(_vec, "RGB");
    // Act & Assert
    EXPECT_THROW(cc.SetHSVVector(_vec1), IncorrectValueOfHSV);
    EXPECT_THROW(cc.SetHSVVector(_vec2), IncorrectValueOfHSV);
    EXPECT_THROW(cc.SetHSVVector(_vec3), IncorrectValueOfHSV);
}



TEST(Voevodin_Andrew_Color_Converter, Check_SetLABVector) {
    // Arrange
    vector<int> _vec1({ 80, -120, -20 });
    vector<int> _vec2({ 2, 2, 2 });
    color_converter cc({1.0, 1.0, 1.0});
    color_converter cc1({ 1.0, 1.0, 1.0 });

    // Act
    cc.SetLABVector(_vec1);
    cc1.SetLABVector(_vec2);

    // Assert
    EXPECT_DOUBLE_EQ(cc.GetLAB()[0], _vec1[0]);
    EXPECT_DOUBLE_EQ(cc.GetLAB()[1], _vec1[1]);
    EXPECT_DOUBLE_EQ(cc.GetLAB()[2], _vec1[2]);

    EXPECT_DOUBLE_EQ(cc1.GetLAB()[0], _vec2[0]);
    EXPECT_DOUBLE_EQ(cc1.GetLAB()[1], _vec2[1]);
    EXPECT_DOUBLE_EQ(cc1.GetLAB()[2], _vec2[2]);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Size_Vec_In_SetLABVector) {
    // Arrange
    vector<int> _vec1({ 0, 0, 0 });
    vector<int> _vec({0, 0, 0, 0});
    color_converter cc(_vec1, "LAB");
    // Act & Assert
    EXPECT_THROW(cc.SetLABVector(_vec), IncorrectSizeOfVector);
}

TEST(Voevodin_Andrew_Color_Converter, Incorrect_Value_Vec_In_SetLABVector) {
    // Arrange
    vector<int> _vec({ 0, 0, 0 });
    vector<int> _vec1({ -1, 0, 0 });
    vector<int> _vec2({ 0, 200, 0 });
    vector<int> _vec3({ 0, 200, 0 });
    color_converter cc(_vec, "LAB");
    // Act & Assert
    EXPECT_THROW(cc.SetLABVector(_vec1), IncorrectValueOfLAB);
    EXPECT_THROW(cc.SetLABVector(_vec2), IncorrectValueOfLAB);
    EXPECT_THROW(cc.SetLABVector(_vec3), IncorrectValueOfLAB);
}



TEST(Voevodin_Andrew_Color_Converter, Check_HSVToRGB) {
    // Arrange
    vector<double> _vec({ 0.0, 1.0, 1.0 });
    vector<int> _vec1;
    color_converter cc({1.0, 1.0, 1.0});
    // Act
    _vec1 = cc.HSVToRGB(_vec);
    // Assert
    EXPECT_EQ(_vec1[0], 255);
    EXPECT_EQ(_vec1[1], 0);
    EXPECT_EQ(_vec1[2], 0);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToRGB) {
    // Arrange
    vector<int> _vec({ 100, 128, 128 });
    vector<int> _vec1;
    color_converter cc(_vec, "LAB");
    // Act
    _vec1 = cc.LABToRGB(_vec);
    // Assert
    EXPECT_EQ(_vec1[0], cc.GetRGB()[0]);
    EXPECT_EQ(_vec1[1], cc.GetRGB()[1]);
    EXPECT_EQ(_vec1[2], cc.GetRGB()[2]);
}


TEST(Voevodin_Andrew_Color_Converter, Check_RGBToHSV) {
    // Arrange
    vector<double> _vec1;
    vector<int> _vec({ 255, 0, 0 });
    color_converter cc(_vec, "RGB");
    // Act
    _vec1 = cc.RGBToHSV(_vec);
    // Assert
    EXPECT_DOUBLE_EQ(_vec1[0], 0.0);
    EXPECT_DOUBLE_EQ(_vec1[1], 1.0);
    EXPECT_DOUBLE_EQ(_vec1[2], 1.0);
}

TEST(Voevodin_Andrew_Color_Converter, Check_LABToHSV) {
    // Arrange
    vector<double> _vec1;
    vector<int> _vec({ 20, 10, 10 });
    color_converter cc(_vec, "LAB");
    // Act
    _vec1 = cc.LABToHSV(_vec);
    // Assert
    EXPECT_DOUBLE_EQ(_vec1[0], 15.0);
    EXPECT_NEAR(_vec1[1], 0.4776, 0.0001);
    EXPECT_NEAR(_vec1[2], 0.2627, 0.0001);
}


TEST(Voevodin_Andrew_Color_Converter, Check_HSVToLAB) {
    // Arrange
    vector<double> _vec({ 0.0, 1.0, 1.0 });
    vector<int> _vec1;
    color_converter cc(_vec);
    // Act
    _vec1 = cc.HSVToLAB(_vec);
    // Assert
    EXPECT_EQ(_vec1[0], 54);
    EXPECT_EQ(_vec1[1], 80);
    EXPECT_EQ(_vec1[2], 68);
}

TEST(Voevodin_Andrew_Color_Converter, Check_RGBToLAB) {
    // Arrange
    vector<int> _vec({ 255, 67, 0 });
    vector<int> _vec1;
    color_converter cc(_vec, "RGB");
    // Act
    _vec1 = cc.RGBToLAB(_vec);
    // Assert
    EXPECT_EQ(_vec1[0], 58);
    EXPECT_EQ(_vec1[1], 69);
    EXPECT_EQ(_vec1[2], 69);
}
