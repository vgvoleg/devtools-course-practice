// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>

#include <math.h>

#include "include/complex_number.h"

TEST(Voevodin_Andrew_ComplexNumberTest, Can_Create_From_ComplexNumber) {
    // Arrange
    ComplexNumber z(12.34, 5);

    // Act
	ComplexNumber z_new(z);


    // Assert
    EXPECT_EQ(z_new.getRe(), z.getRe());
    EXPECT_EQ(z_new.getIm(), z.getIm());
}

TEST(Voevodin_Andrew_ComplexNumberTest, Triangle_Inequality) {
    // Arrange
    ComplexNumber z1(5, 5);
	ComplexNumber z2(5, 5);
	double Model_Sum, Sum_Model;
	bool l=false;
    // Act
    Model_Sum = pow(pow((z1+z2).getRe(), 2) + pow((z1+z2).getIm(), 2), 0.5);
    Sum_Model = pow(pow(z1.getRe(), 2) + pow(z1.getIm(), 2), 0.5) + pow(pow(z2.getRe(), 2) + pow(z2.getIm(), 2), 0.5);
    if (Model_Sum <= Sum_Model) l = true;

    // Assert
    EXPECT_EQ(l, true);
}