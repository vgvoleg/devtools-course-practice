// Copyright 2016 Maksimenko Alex

#include <gtest/gtest.h>
#include "include/convertertemp.h"

TEST(ConverterTemperature, cant_create_negative_kelvin) {
    // Act
    const double value = -1.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_create_temperature) {
    // Act
    const double value = 10.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value, dimension);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::OK);
}

TEST(ConverterTemperature, can_convert_kelvin_to_kelvin) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension);

    // Act & Assert
    Temperature.converter(dimension);
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_convert_kelvin_to_degree) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension1 = Measure::KELVIN;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::DEGREE;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = -273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_kelvin_to_fahrenheit) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension1 = Measure::KELVIN;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::FAHRENHEIT;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 215.4;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_kelvin_to_newton) {
    // Arrange
    const double value1 = 274.0;
    const Measure dimension1 = Measure::KELVIN;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::NUTON;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 0.33;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_degree_to_kelvin) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension1 = Measure::DEGREE;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::KELVIN;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, cant_convert_negative_degrees_into_kelvin) {
    // Act
    const double value = -274.0;
    const Measure dimension1 = Measure::DEGREE;
    const Measure dimension2 = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension1);
    Temperature.converter(dimension2);

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
    const Measure dimension1 = Measure::DEGREE;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::FAHRENHEIT;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 32.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_degree_to_newton) {
    // Arrange
    const double value1 = 100.0;
    const Measure dimension1 = Measure::DEGREE;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::NUTON;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_fahrenheit_to_kelvin) {
    // Arrange
    const double value1 = 32.0;
    const Measure dimension1 = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::KELVIN;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, cant_convert_Fahrenheit_to_negative_kelvin) {
    // Act
    const double value = -700.0;
    const Measure dimension1 = Measure::FAHRENHEIT;
    const Measure dimension2 = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension1);
    Temperature.converter(dimension2);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_convert_fahrenheit_to_degree) {
    // Arrange
    const double value1 = 32.0;
    const Measure dimension1 = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::DEGREE;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 0.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
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
    const double value1 = 212.0;
    const Measure dimension1 = Measure::FAHRENHEIT;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::NUTON;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 33.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_newton_to_kelvin) {
    // Arrange
    const double value1 = 0.0;
    const Measure dimension1 = Measure::NUTON;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::KELVIN;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 273.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, cant_convert_nuwton_into_negative_Kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension1 = Measure::NUTON;
    const Measure dimension2 = Measure::KELVIN;
    ConverterTemp Temperature(value, dimension1);

    // Act
    Temperature.converter(dimension2);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, can_convert_newton_to_degree) {
    // Arrange
    const double value1 = 33.0;
    const Measure dimension1 = Measure::NUTON;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::DEGREE;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 100.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
}

TEST(ConverterTemperature, can_convert_newton_to_fahrenheit) {
    // Arrange
    const double value1 = 33.0;
    const Measure dimension1 = Measure::NUTON;
    ConverterTemp Temperature(value1, dimension1);

    // Act
    const Measure dimension2 = Measure::FAHRENHEIT;
    Temperature.converter(dimension2);

    // Assert
    const double value2 = 212.0;
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value2);
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
    const Measure dimension1 = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension1);

    // Act
    const Measure dimension2 = Measure::NUTON;
    Temperature.converter(dimension2);
    Temperature.converter(dimension1);

    // Assert
    EXPECT_DOUBLE_EQ(Temperature.getValue(), value);
}

TEST(ConverterTemperature, can_return_the_dimension_of_this_obj) {
    // Arrange
    const double value = 33.0;
    const Measure dimension1 = Measure::DEGREE;
    ConverterTemp Temperature(value, dimension1);

    // Act
    const Measure dimension2 = Measure::NUTON;
    const Measure dimension3 = Measure::FAHRENHEIT;
    const Measure dimension4 = Measure::KELVIN;
    Temperature.converter(dimension1);
    Temperature.converter(dimension2);
    Temperature.converter(dimension3);
    Temperature.converter(dimension4);
    Temperature.converter(dimension3);

    // Assert
    EXPECT_EQ(Temperature.getMeasure(), dimension3);
}
