// Copyright 2016 Baydina Olga

#include <gtest/gtest.h>
#include "include/complex_number.h"


TEST(Baydina_Olga_ComplexNumberTest, Can_Operation_With_Zero) {
	 // Arrange
		ComplexNumber a(0.0, 0.0);
	    ComplexNumber b(5.0, 3.0);
	
	 // Act
		ComplexNumber result = (a * b) + (a / b);
	
	 // Assert
		EXPECT_EQ(a, result);
	
}

TEST(Baydina_Olga_ComplexNumberTest, Compare) {
	  // Arrange
		ComplexNumber a(-1.0, 1.0);
	    ComplexNumber b(1.0, 1.0);
	
	  // Act
		
      // Assert
		EXPECT_FALSE(a == b);
	
}

TEST(Baydina_Olga_ComplexNumberTest, Is_Distributivity){
	 // Arrange
	   ComplexNumber a(1.0, 2.0);
	   ComplexNumber b(1.0, 3.0);
	   ComplexNumber c(2.0, 2.0);

	 // Act
	   ComplexNumber result1 = a*(b + c);
	   ComplexNumber result2 = a*b + a*c;

	 // Assert
	   EXPECT_EQ(result1, result2);
}

TEST(Baydina_Olga_ComplexNumberTest, Sum_Re_Of_Complex_Numbers){
	 // Arrange
	   ComplexNumber a(5.0, 8.0);
	   ComplexNumber b(3.0, -1.0);

	 // Act
	   ComplexNumber result = a + b;

	 // Assert
	   EXPECT_EQ(result.getRe(), 8.0);
}
     
TEST(Baydina_Olga_ComplexNumberTest, Sum_Im_Of_Conjurate_Numbers){
	// Arrange
	   ComplexNumber a(3.0, 1.0);
	   ComplexNumber b(3.0, -1.0);

	// Act
	   ComplexNumber result = a + b;

    // Assert 
	   EXPECT_EQ(result.getIm(), 0.0);

     
}