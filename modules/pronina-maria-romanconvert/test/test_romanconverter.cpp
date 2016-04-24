// Copyright 2016 Pronina Maria
#include <gtest/gtest.h>
#include <string>
#include "include/RomanConvertor.h"
TEST(RomanConverter, Can_Validate_Arab) {
     // Arrange
     int arab = 5;
     // Act
     bool isValid = RomanConvertor::checkArabNumber(arab);

     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Negative_Arab_Invalid) {
     // Arrange
     int arab = -5;
     // Act
     bool isValid = RomanConvertor::checkArabNumber(arab);

     // Assert
     EXPECT_FALSE(isValid);
}

TEST(RomanConverter, Is_Zero_Arab_Invalid) {
     // Arrange
     int arab = 0;
     // Act
     bool isValid = RomanConvertor::checkArabNumber(arab);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Greater_Than_Max_Arab_Invalid) {
     // Arrange
     int arab = 4000;
     // Act
     bool isValid = RomanConvertor::checkArabNumber(arab);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Can_Validate_Roman) {
     // Arrange
     std::string roman = "V";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Empty_Roman_Invalid) {
     // Arrange
     std::string roman = "";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Roman_With_Four_Repeats_Invalid) {
     // Arrange
     std::string roman = "IIII";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Roman_Without_Four_Repeats_Valid) {
     // Arrange
     std::string roman = "MMMDCCLXXXVIII";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);
     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Roman_With_Combinations_IV_Repeats_Valid) {
     // Arrange
     std::string roman = "MMMDCCLXXXVIII";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);
     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Roman_With_Other_Symbols_Invalid) {
     // Arrange
     std::string roman = "Ia";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Simple_Roman_With_Incorrect_Order_Invalid) {
     // Arrange
     std::string roman = "VL";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Roman_With_End_Symbol_From_XCI_Valid) {
     // Arrange
     std::string roman = "X";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Roman_With_End_Symbol_And_Repeats_From_XCI_Valid) {
     // Arrange
     std::string roman = "CXXXII";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_TRUE(isValid);
}
TEST(RomanConverter, Is_Roman_With_Incorrect_Numerals_Use_Invalid) {
     // Arrange
     std::string roman = "IXIX";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Roman_With_Subs_Numerals_And_Incorrect_Order_Invalid) {
     // Arrange
     std::string roman = "XIIV";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Is_Roman_With_All_Type_Of_Errors_Invalid) {
     // Arrange
     std::string roman = "IIIIIVa";
     // Act
     bool isValid = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_FALSE(isValid);
}
TEST(RomanConverter, Can_Convert_Arab) {
     // Arrange
     int arab = 2009;
     // Act
     std::string actual = RomanConvertor::convertArabToRoman(arab);

     // Assert
     std::string expected = "MMIX";
     EXPECT_EQ(expected, actual);
}

TEST(RomanConverter, Can_Not_Convert_Negative_Arab) {
     // Arrange
     int arab = -2009;
     // Act
     std::string actual = RomanConvertor::convertArabToRoman(arab);

     // Assert
     std::string expected = "";
     EXPECT_EQ(expected, actual);
}

TEST(RomanConverter, Can_Not_Convert_Zero_Arab) {
     // Arrange
     int arab = 0;
     // Act
     std::string actual = RomanConvertor::convertArabToRoman(arab);

     // Assert
     std::string expected = "";
     EXPECT_EQ(expected, actual);
}
TEST(RomanConverter, Can_Not_Convert_Greater_Than_Max_Arab) {
     // Arrange
     int arab = 58900;
     // Act
     std::string actual = RomanConvertor::convertArabToRoman(arab);

     // Assert
     std::string expected = "";
     EXPECT_EQ(expected, actual);
}
TEST(RomanConverter, Can_Convert_Roman) {
     // Arrange
     std::string roman = "MMMDCCLXXXVIII";
     // Act
     int actual = RomanConvertor::convertRomanToArab(roman);

     // Assert
     int expected = 3788;
     EXPECT_EQ(expected, actual);
}
TEST(RomanConverter, Can_Not_Convert_Empty_Roman) {
     // Arrange
     std::string roman = "";
     // Act
     int actual = RomanConvertor::convertRomanToArab(roman);

     // Assert
     int expected = -1;
     EXPECT_EQ(expected, actual);
}
TEST(RomanConverter, Can_Not_Convert_Roman_With_Other_Symbols) {
     // Arrange
     std::string roman = "-1";
     // Act
     int actual = RomanConvertor::convertRomanToArab(roman);

     // Assert
     int expected = -1;
     EXPECT_EQ(expected, actual);
}
TEST(RomanConverter, Can_Not_Convert_Roman_Invalid_Order) {
     // Arrange
     std::string roman = "XXXVMMMDCCLIII";
     // Act
     int actual = RomanConvertor::convertRomanToArab(roman);

     // Assert
     int expected = -1;
     EXPECT_EQ(expected, actual);
}

TEST(RomanConverter, Can_Convert_Roman_From_C_String) {
     // Arrange
     char * roman = "MMMDCCLXXXVIII";
     // Act
     int actual = RomanConvertor::convertRomanToArab(roman);

     // Assert
     int expected = 3788;
     EXPECT_EQ(expected, actual);
}

TEST(RomanConverter, Can_Check_Roman_From_C_String) {
     // Arrange
     char * roman = "MMMDCCLXXXVIII";
     // Act
     bool actual = RomanConvertor::checkRomanNumber(roman);

     // Assert
     EXPECT_TRUE(actual);
}

