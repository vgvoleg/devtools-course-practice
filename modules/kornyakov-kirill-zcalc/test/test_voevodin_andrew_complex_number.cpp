// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>

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

