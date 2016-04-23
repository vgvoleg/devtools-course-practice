// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/mass_converter.h"

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Create) {
    // Arrange
    MassConverter *a;

    // Act
    a = new MassConverter();

    // Assert
    EXPECT_NE(nullptr, a);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Throws_When_Value_Is_Negative) {
    // Arrange
    MassConverter converter;
    double bad_value = -1;

    // Act & Assert
    EXPECT_THROW(
            converter.convert(MassUnit::Gram,
                              MassUnit::Kilogram,
                              bad_value),
            std::invalid_argument);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Zero_Mass) {
    // Arrange
    MassConverter converter;
    double value = 0;

    // Act
    double result = converter.convert(MassUnit::Gram,
                                      MassUnit::Kilogram,
                                      value);

    // Assert
    double exceptedValue = 0;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Gram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.213;

    // Act
    double result = converter.convert(MassUnit::Gram,
                                      MassUnit::Gram,
                                      value);

    // Assert
    double exceptedValue = 1.213;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Gram_To_Kilogram) {
    // Arrange
    MassConverter converter;
    double value = 500;

    // Act
    double result = converter.convert(MassUnit::Gram,
                                      MassUnit::Kilogram,
                                      value);

    // Assert
    double exceptedValue = 0.5;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.2;

    // Act
    double result = converter.convert(MassUnit::Kilogram,
                                      MassUnit::Gram,
                                      value);

    // Assert
    double exceptedValue = 1200;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Add_New_Unit) {
    // Arrange
    std::vector<MassUnit> emptyArray;
    MassConverter converter(emptyArray);

    // Act
    converter.addUnit(MassUnit(3.14, "test"));

    // Assert
    MassUnit unit = converter.getUnits()[0];
    EXPECT_DOUBLE_EQ(unit.get_relative_coefficient(), 3.14);
    EXPECT_EQ(unit.get_qualifier(), "test");
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_From_String_With_Custom_Unit) {
    // Arrange
    MassConverter converter;
    MassUnit megaGramUnit = MassUnit(1000, "Mg");

    // Act
    converter.addUnit(megaGramUnit);
    double result = converter.from_string("0.001 Mg", MassUnit::Kilogram);

    // Assert
    EXPECT_DOUBLE_EQ(result, 1);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_To_String_With_Default_Precision) {
    // Arrange
    MassConverter converter;

    // Act
    std::string result = converter.to_string(MassUnit::Kilogram, 42.26681);

    // Assert
    EXPECT_EQ(result, "42.27 kg");
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Throws_When_Parse_Unknown_Unit) {
    // Arrange
    MassConverter converter;

    // Act & Assert
    EXPECT_THROW(converter.from_string("2 om", MassUnit::Kilogram),
                 std::logic_error);
}
