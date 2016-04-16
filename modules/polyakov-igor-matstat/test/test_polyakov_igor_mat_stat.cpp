// Copyright 2016 Polyakov Igor

#include <gtest/gtest.h>
#include <cmath>
#include "include/MatStat.h"

using namespace std;

TEST(Polyakov_Igor_MatStatTest, Is_Initialization_Sample_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = {0.2, 0.1, 0.3333, 0.1, 0.2777};

    Sample S(sample, probabilities);

    // Act

    int get_size_sample = S.GetSampleSize();
    vector<double> get_sample = S.GetSample();
    vector<double> get_probabilities = S.GetProbabilities();

    // Assert

    EXPECT_EQ(size_sample, get_size_sample);

    for (int i = 0; i < size_sample; i++)
    {

        EXPECT_EQ(sample[i], get_sample[i]);
        EXPECT_EQ(probabilities[i], get_probabilities[i]);

    }

}

TEST(Polyakov_Igor_MatStatTest, Is_Calc_Mathematical_Expectation_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    // Act

    double mathematical_expectation = S.CalcMathematicalExpectation();

    // Assert

    EXPECT_NEAR(1.9332, mathematical_expectation, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Dispersion_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    // Act

    double dispersion = S.CalcDispersion();

    // Assert

    EXPECT_NEAR(2.7956, dispersion, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calc_Average_Quadratic_Deviation_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    // Act

    double average_quadratic_deviation = S.CalcAverageQuadraticDeviation();

    // Assert

    EXPECT_NEAR(1.672, average_quadratic_deviation, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Moment_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    double relative_point = 1.0;
    int exponent = 3;

    // Act

    double moment = S.CalcMoment(relative_point, exponent);

    // Assert

    EXPECT_NEAR(8.7214, moment, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Elementary_Moment_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    int exponent = 3;

    // Act

    double elementary_moment = S.CalcElementaryMoment(exponent);

    // Assert

    EXPECT_NEAR(24.1312, elementary_moment, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Central_Moment_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = { 0.2, 0.1, 0.3333, 0.1, 0.2777 };

    Sample S(sample, probabilities);

    int exponent = 3;

    // Act

    double central_moment = S.CalcCentralMoment(exponent);

    // Assert

    EXPECT_NEAR(-1.6285, central_moment, SAMPLE_EPSILON);

}