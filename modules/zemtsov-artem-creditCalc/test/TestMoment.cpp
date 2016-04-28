// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>
#include <include/Moments.h>

TEST(Moments, can_get_and_set_day)
{
    // Arrange
    const int day=4;
    const int month=4;
    const int year=2076;
    Moment example;
    
    // Act
    example.setTime(day, month, year);
    
    // Assert
    EXPECT_EQ(4, example.getDay() );
}

TEST(Moments, can_get_and_set_month)
{
    // Arrange
    const int day=4;
    const int month=4;
    const int year=2076;
    Moment example;
    
    // Act
    example.setTime(day, month, year);
    
    // Assert
    EXPECT_EQ(4, example.getMonth() );
}

TEST(Moments, can_get_and_set_year)
{
    // Arrange
    const int day=4;
    const int month=4;
    const int year=2076;
    Moment example;
    
    // Act
    example.setTime(day, month, year);
    
    // Assert
    EXPECT_EQ(2076, example.getYear() );
}