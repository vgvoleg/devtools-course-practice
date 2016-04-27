// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>
#include <include/creditCalc.h>

TEST(creditPerson, throw_then_procent_less_than_zero)
{
    // Arrange
    CreditPerson example;
    
    // Act and Assert
    EXPECT_ANY_THROW( example.setProcentByUser(-30));
}

TEST(creditPerson, throw_then_procent_more_than_100)
{
    // Arrange
    CreditPerson example;
    
    // Act and Assert
    EXPECT_ANY_THROW( example.setProcentByUser(1300));
}

TEST(creditPerson, no_throw_then_procent_is_normal)
{
    // Arrange
    CreditPerson example;
    
    // Act and Assert
    for (int i=0; i<100; i++) {
        EXPECT_NO_THROW( example.setProcentByUser(i));
    }
}

TEST(creditPerson, throw_then_try_set_invalide_day)
{
    // Arrange
    CreditPerson example;
    const int month=4;
    const int year=2016;
    
    // Act and Assert
    for (int i=0;i<100;i=i+40)
        EXPECT_ANY_THROW(example.setStartTimeByUser(i, month, year));
}

TEST(creditPerson, throw_then_try_set_invalide_month)
{
    // Arrange
    CreditPerson example;
    const int day=4;
    const int year=2016;
    
    // Act and Assert
    for (int month=0;month<100;month=month+13)
        EXPECT_ANY_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, throw_then_try_set_year_less_than_1900)
{
    // Arrange
    CreditPerson example;
    const int day=4;
    const int month=12;
    
    // Act and Assert
    for (int year=0;year<1900;year=year+190)
        EXPECT_ANY_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, no_throw_then_try_set_normal_date)
{
    // Arrange
    CreditPerson example;
    const int day=10;
    const int month=4;
    const int year=1996;
    
    // Act and Assert
    EXPECT_NO_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, throw_then_try_to_set_credit_time_less_than_0)
{
    // Arrange
    CreditPerson example;
    const int creditTime=-5;
    
    // Act and Assert
    EXPECT_ANY_THROW(example.setFinishTimeByUser(creditTime));
}

TEST(creditPerson, no_throw_then_try_set_normal_credit_time)
{
    // Arrange
    CreditPerson example;
    const int creditTime=5;
    
    // Act and Assert
    EXPECT_NO_THROW(example.setFinishTimeByUser(creditTime));
}

TEST(creditPerson, throw_then_try_set_invalide_installment)
{
    // Arrange
    CreditPerson example;
    const int newInstallment=-500;
    
    // Act and Assert
    EXPECT_ANY_THROW(example.newInstallment(newInstallment));
}

TEST(creditPerson, no_throw_then_try_set_normal_installment)
{
    // Arrange
    CreditPerson example;
    const int newInstallment=500;
    
    // Act and Assert
    EXPECT_NO_THROW(example.newInstallment(newInstallment));
}

TEST(creditPerson, can_make_new_normal_installmen)
{
    // Arrange
    CreditPerson example;
    const int exampleCost=20000;
    
    // Act
    example.discoverCost(exampleCost);
    
    // Assert
    
}

