// Copyright 2016 Maksimenko Alex

#include <gtest/gtest.h>
#include "include/convertertemp.h"

TEST(ConverterTemperature, cant_create_negative_kelvin) {
    // Arrange
    const double value = -1.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_create_temperature) {
    // Arrange
    const double value = 10.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::OK);
}

TEST(ConverterTemperature, can_convert_kelvin_to_kelvin) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_convert_kelvin_to_degree) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value1, dimension);

    // Act
    const Measure expected_dimension = Measure::DEGREE;
    Temperature.converter(expected_dimension);

    // Assert
    const double value2 = -273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_kelvin_to_fahrenheit) {
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

TEST(ConverterTemperature, can_convert_kelvin_to_newton) {
    // Arrange
    const double value = 274.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NUTON;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.33;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, can_convert_degree_to_kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, cant_convert_negative_degrees_into_kelvin) {
    // Arrange
    const double value = -274.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_convert_degree_to_degree) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_convert_degree_to_fahrenheit) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value1, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    Temperature.converter(result_dimension);

    // Assert
    const double value2 = 32.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_degree_to_newton) {
    // Arrange
    const double value1 = 100.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value1, dimension);

    // Act
    const Measure result_dimension = Measure::NUTON;
    Temperature.converter(result_dimension);

    // Assert
    const double value2 = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_fahrenheit_to_kelvin) {
    // Arrange
    const double value1 = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value1, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, cant_convert_fahrenheit_to_negative_kelvin) {
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

TEST(ConverterTemperature, can_convert_fahrenheit_to_degree) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::DEGREE;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, can_convert_fahrenheit_to_fahrenheit) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_convert_fahrenheit_to_newton) {
    // Arrange
    const double value = 212.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NUTON;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, can_convert_newton_to_kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::NUTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, cant_convert_nuwton_into_negative_kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension = Measure::NUTON;
    const Measure result_dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_convert_newton_to_degree) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NUTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::DEGREE;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 100.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, can_convert_newton_to_fahrenheit) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NUTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    Temperature.converter(result_dimension);

    // Assert
    const double expected_value = 212.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, can_convert_newton_to_newton) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NUTON;
    ConverterTemp Temperature(value, dimension);

    // Act
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_i_convert_multiple_times) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NUTON;
    Temperature.converter(result_dimension);
    Temperature.converter(dimension);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_return_the_dimension_of_this_obj) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NUTON;
    Temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(Temperature.getMeasure(), result_dimension);
}
