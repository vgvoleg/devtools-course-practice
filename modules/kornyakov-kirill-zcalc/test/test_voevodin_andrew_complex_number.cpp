// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>

#include <math.h>

#include "include/complex_number.h"

TEST(Voevodin_Andrew_ComplexNumberTest, Can_Create_From_ComplexNumber) {
    // Arrange
    ComplexNumber ñ(12.34, 5);

    // Act
	ComplexNumber z_new(ñ);


    // Assert
    EXPECT_EQ(z_new.getRe(), ñ.getRe());
    EXPECT_EQ(z_new.getIm(), ñ.getIm());
}

TEST(Voevodin_Andrew_ComplexNumberTest, Triangle_Inequality) {
    // Arrange
    ComplexNumber z1(5.0, 5.0);
	ComplexNumber z2(5.0, 5.0);
	double Model_Sum, Sum_Model;
	bool l=false;
    // Act
    Model_Sum = pow(pow((z1+z2).getRe(), 2) + pow((z1+z2).getIm(), 2), 0.5);
    Sum_Model = pow(pow(z1.getRe(), 2) + pow(z1.getIm(), 2), 0.5) + pow(pow(z2.getRe(), 2) + pow(z2.getIm(), 2), 0.5);
    if (Model_Sum <= Sum_Model) l = true;

    // Assert
    EXPECT_EQ(l, true);
}

TEST(Voevodin_Andrew_ComplexNumberTest, Mult_Complex_Conjugate_Numbers_Is_Real_Number) {
    // Arrange
    ComplexNumber z1(6.0, 5.12);
    ComplexNumber z2(6.0, -5.12);
    ComplexNumber Model_Mult;
    double Square;

    // Act
    Model_Mult = z1*z2;
    Square = pow(z1.getRe(), 2) + pow(z1.getIm(), 2);

    // Assert
    EXPECT_EQ(Model_Mult.getIm(), 0.0);
    EXPECT_EQ(Model_Mult.getRe(), Square);
}

TEST(Voevodin_Andrew_ComplexNumberTest, Sum_Complex_Conjugate_Numbers_Is_Real_Number) {
    // Arrange
    ComplexNumber z1(6.0, 5.12);
    ComplexNumber z2(6.0, -5.12);
    ComplexNumber Model_Mult;
    double Square;

    // Act
    Model_Mult = z1+z2;
    Square = 2.0*z1.getRe();

    // Assert
    EXPECT_EQ(Model_Mult.getIm(), 0.0);
    EXPECT_EQ(Model_Mult.getRe(), Square);
}

TEST(Voevodin_Andrew_ComplexNumberTest, Complex_Conjugate_Division_Is_Division_Complex_Conjugate) {
    // Arrange
    ComplexNumber z1(3.14, 13.12);
    ComplexNumber z1_conj(3.14, -13.12);
    ComplexNumber z2(29.2, 1.0);
    ComplexNumber z2_conj(29.2, -1.0);
    ComplexNumber Model_Div, Div_Model;

    // Act
    Model_Div = z1/z2;
    Model_Div.setIm((-1.0)*Model_Div.getIm());
    Div_Model=z1_conj/z2_conj;

    // Assert
    EXPECT_EQ(Div_Model.getRe(), Model_Div.getRe());
    EXPECT_EQ(Div_Model.getIm(), Model_Div.getIm());
}