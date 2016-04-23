// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>

#include "include/mass_formatter.h"

TEST(MassFormatter, Can_Create) {
    // Arrange
    MassFormatter<MassUnit::Kilogram> *a;

    // Act
    a = new MassFormatter<MassUnit::Kilogram>();

    // Assert
    EXPECT_NE(nullptr, a);
}

TEST(MassFormatter, Can_Format_Kilogram_With_Default_Precision) {
    // Arrange
    MassFormatter<MassUnit::Kilogram> formatter;
    double value = 1.5295;

    // Act
    std::string result = formatter.format(value);

    // Assert
    std::string excepted_value = "1.53 kg";
    EXPECT_EQ(excepted_value, result);
}