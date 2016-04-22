// Copyright 2016 Maksimenko Aleksey

#include <gtest/gtest.h>
#include "include/convertertemp.h"

TEST(Maksimenko_Alex_ConverterTempTest, cant_create_negative_kelvin) {
    // Arrange
    const double Value = -1;
    const Measure Temp = KELVIN;
    ConverterTemp Temperature(Value, Temp);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_create_temperature) {
    // Arrange
    const double Value = 10;
    const Measure Temp = FAHRENHEIT;
    ConverterTemp Temperature(Value, Temp);

    // Act & Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::OK);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_kelvin_to_kelvin) {
    // Arrange
    const double Value = 23;
    const Measure Temp = KELVIN;
    ConverterTemp Temperature(Value, Temp);

    // Act
    Temperature.converter(Temp);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_kelvin_to_gradus) {
    // Arrange
    const double Value1 = 0;
    const double Value2 = -273;
    const Measure Temp1 = KELVIN;
    const Measure Temp2 = DEGREE;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_kelvin_to_fahrenheit) {
    // Arrange
    const double Value1 = 0;
    const double Value2 = 215.4;
    const Measure Temp1 = KELVIN;
    const Measure Temp2 = FAHRENHEIT;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_kelvin_to_newton) {
    // Arrange
    const double Value1 = 274;
    const double Value2 = 0.33;
    const Measure Temp1 = KELVIN;
    const Measure Temp2 = NUTON;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_gradus_to_kelvin) {
    // Arrange
    const double Value1 = 0;
    const double Value2 = 273;
    const Measure Temp1 = DEGREE;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, cant_convert_negative_in_kelvin_1) {
    // Arrange
    const double Value = -274;
    const Measure Temp1 = DEGREE;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_gradus_to_gradus) {
    // Arrange
    const double Value = 23;
    const Measure Temp = DEGREE;
    ConverterTemp Temperature(Value, Temp);

    // Act
    Temperature.converter(Temp);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_gradus_to_fahrenheit) {
    // Arrange
    const double Value1 = 0;
    const double Value2 = 32;
    const Measure Temp1 = DEGREE;
    const Measure Temp2 = FAHRENHEIT;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_gradus_to_newton) {
    // Arrange
    const double Value1 = 100;
    const double Value2 = 33;
    const Measure Temp1 = DEGREE;
    const Measure Temp2 = NUTON;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_fahrenheit_to_kelvin) {
    // Arrange
    const double Value1 = 32;
    const double Value2 = 273;
    const Measure Temp1 = FAHRENHEIT;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, cant_convert_in_negative_kelvin_2) {
    // Arrange
    const double Value = -700;
    const Measure Temp1 = FAHRENHEIT;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_fahrenheit_to_gradus) {
    // Arrange
    const double Value1 = 32;
    const double Value2 = 0;
    const Measure Temp1 = FAHRENHEIT;
    const Measure Temp2 = DEGREE;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_fahrenheit_to_fahrenheit) {
    // Arrange
    const double Value = 32;
    const Measure Temp = FAHRENHEIT;
    ConverterTemp Temperature(Value, Temp);

    // Act
    Temperature.converter(Temp);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_fahrenheit_to_newton) {
    // Arrange
    const double Value1 = 212;
    const double Value2 = 33;
    const Measure Temp1 = FAHRENHEIT;
    const Measure Temp2 = NUTON;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_newton_to_kelvin) {
    // Arrange
    const double Value1 = 0;
    const double Value2 = 273;
    const Measure Temp1 = NUTON;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, cant_convert_in_negative_kelvin_3) {
    // Arrange
    const double Value = -700;
    const Measure Temp1 = NUTON;
    const Measure Temp2 = KELVIN;
    ConverterTemp Temperature(Value, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getRetCode(), Data::ERROR);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_newton_to_gradus) {
    // Arrange
    const double Value1 = 33;
    const double Value2 = 100;
    const Measure Temp1 = NUTON;
    const Measure Temp2 = DEGREE;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_newton_to_fahrenheit) {
    // Arrange
    const double Value1 = 33;
    const double Value2 = 212;
    const Measure Temp1 = NUTON;
    const Measure Temp2 = FAHRENHEIT;
    ConverterTemp Temperature(Value1, Temp1);

    // Act
    Temperature.converter(Temp2);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value2);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_convert_newton_to_newton) {
    // Arrange
    const double Value = 33;
    const Measure Temp = NUTON;
    ConverterTemp Temperature(Value, Temp);

    // Act
    Temperature.converter(Temp);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value);
}

TEST(Maksimenko_Alex_ConverterTempTest, can_i_convert_multiple_times) {
    // Arrange
    const double Value = 33;
    const Measure Temp1 = DEGREE;
    const Measure Temp2 = NUTON;
    ConverterTemp Temperature(Value, Temp1);

    // Act
    Temperature.converter(Temp2);
    Temperature.converter(Temp1);

    // Assert
    EXPECT_EQ(Temperature.getValue(), Value);
}
