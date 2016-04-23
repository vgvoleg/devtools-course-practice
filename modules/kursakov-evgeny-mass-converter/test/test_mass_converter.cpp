// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>

#include "include/mass_converter.h"

TEST(MassConverter, Can_Create) {
    // Arrange
    MassConverter<MassUnit::Kilogram, MassUnit::Gram> *a;

    // Act
    a = new MassConverter<MassUnit::Kilogram, MassUnit::Gram>();

    // Assert
    EXPECT_NE(nullptr, a);
}

TEST(MassConverter, Throws_When_Value_Is_Negative) {
    // Arrange
    MassConverter<MassUnit::Kilogram, MassUnit::Gram> converter;
    double bad_value = -1;

    // Act & Assert
    EXPECT_THROW(converter.convert(bad_value), std::invalid_argument);
}

TEST(MassConverter, Can_Convert_Zero_Mass) {
    // Arrange
    MassConverter<MassUnit::Gram, MassUnit::Kilogram> converter;
    double value = 0;

    // Act
    double result = converter.convert(value);

    // Assert
    double exceptedValue = 0;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(MassConverter, Can_Convert_Gram_To_Gram) {
    // Arrange
    MassConverter<MassUnit::Gram, MassUnit::Gram> converter;
    double value = 1.213;

    // Act
    double result = converter.convert(value);

    // Assert
    double exceptedValue = 1.213;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(MassConverter, Can_Convert_Gram_To_Kilogram) {
    // Arrange
    MassConverter<MassUnit::Gram, MassUnit::Kilogram> converter;
    double value = 500;

    // Act
    double result = converter.convert(value);

    // Assert
    double exceptedValue = 0.5;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}

TEST(MassConverter, Can_Convert_Kilogram_To_Gram) {
    // Arrange
    MassConverter<MassUnit::Kilogram, MassUnit::Gram> converter;
    double value = 1.2;

    // Act
    double result = converter.convert(value);

    // Assert
    double exceptedValue = 1200;
    EXPECT_DOUBLE_EQ(result, exceptedValue);
}
