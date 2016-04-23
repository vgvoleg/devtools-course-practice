// Copyright 2016 Maksimenko Alex

#include <gtest/gtest.h>
#include "include/convertertemp.h"

TEST(ConverterTemperature, Cant_Create_Negative_Kelvin) {
    // Arrange
    const double value = -1.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Create_Temperature) {
    // Arrange
    const double value = 10.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::OK);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Kelvin) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Celsius) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure expected_dimension = Measure::CELSIUS;
    Temperature.converter(expected_dimension);

    // Assert
    const double value2 = -273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Fahrenheit) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 215.4;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Newton) {
    // Arrange
    const double value = 274.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.33;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Celsius_To_Negative_Kelvin) {
    // Arrange
    const double value = -274.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Celsius) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Fahrenheit) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 32.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Newton) {
    // Arrange
    const double value = 100.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Kelvin) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Fahrenheit_To_Negative_Kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Celsius) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::CELSIUS;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Fahrenheit) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Newton) {
    // Arrange
    const double value = 212.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Nuwton_To_Negative_Kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension = Measure::NEWTON;
    const Measure result_dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Celsius) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::CELSIUS;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 100.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Fahrenheit) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 212.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Newton) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, Can_Convert_Multiple_Times) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    Temperature.converter(result_dimension);
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, Can_Return_The_Dimension_Of_This_Object) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getMeasure(), result_dimension);
}
