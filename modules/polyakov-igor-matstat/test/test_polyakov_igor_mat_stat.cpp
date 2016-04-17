// Copyright 2016 Polyakov Igor

#include <gtest/gtest.h>
#include <cmath>
#include "include/MatStat.h"

using namespace std;

TEST(Polyakov_Igor_MatStatTest, Is_Initialization_Sample_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    // Act

    int get_size_sample = S.GetSampleSize();
    vector<double> get_sample = S.GetSample();
    vector<double> get_probabilities = S.GetProbabilities();

    // Assert

    EXPECT_EQ(size_sample, get_size_sample);
    EXPECT_EQ(sample, get_sample);
    EXPECT_EQ(probabilities, get_probabilities);

}

TEST(Polyakov_Igor_MatStatTest, Is_Handle_Incorrect_Sample) {

    // Arrange

    double mas_sample[5] = { 1.0, 3.0, 4.0, 1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    // Act & Assert

    EXPECT_THROW(Sample(sample, probabilities), IncorrectSample);
}

TEST(Polyakov_Igor_MatStatTest, Is_Handle_Negative_Probability) {

    // Arrange

    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, -0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    // Act & Assert

    EXPECT_THROW(Sample(sample, probabilities), IncorrectProbabilities);
}

TEST(Polyakov_Igor_MatStatTest, Is_Handle_Summ_Probability_Not_Equal_One) {

    // Arrange

    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.0 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    // Act & Assert

    EXPECT_THROW(Sample(sample, probabilities), IncorrectProbabilities);
}

TEST(Polyakov_Igor_MatStatTest, Is_Handle_Sizes_Sample_And_Prob_Differ) {

    // Arrange

    double mas_sample[4] = { 1.0, 3.0, 4.0, -1.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 4);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    // Act & Assert

    EXPECT_THROW(Sample(sample, probabilities),
                 IncorrectSizesOfSampleAndProbabilities);
}

TEST(Polyakov_Igor_MatStatTest, Can_Assign_Sample_With_Other_Size) {

    // Arrange

    double mas_sample_1[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities_1[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample_1(mas_sample_1, mas_sample_1 + 5);
    vector<double> probabilities_1(mas_probabilities_1, mas_probabilities_1 + 5);

    double mas_sample_2[4] = { 1.0, 3.0, 4.0, -1.0};
    double mas_probabilities_2[4] = { 0.2, 0.1, 0.3333, 0.3667};
    vector<double> sample_2(mas_sample_2, mas_sample_2 + 4);
    vector<double> probabilities_2(mas_probabilities_2, mas_probabilities_2 + 4);

    Sample S_1(sample_1, probabilities_1);
    Sample S_2(sample_2, probabilities_2);

    // Act

    S_2 = S_1;

    // Assert

    EXPECT_EQ(S_1, S_2);
}

TEST(Polyakov_Igor_MatStatTest, Are_Samples_With_Differ_Size_Inequal) {

    // Arrange

    double mas_sample_1[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities_1[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample_1(mas_sample_1, mas_sample_1 + 5);
    vector<double> probabilities_1(mas_probabilities_1, mas_probabilities_1 + 5);

    double mas_sample_2[4] = { 1.0, 3.0, 4.0, -1.0};
    double mas_probabilities_2[4] = { 0.2, 0.1, 0.3333, 0.3667 };
    vector<double> sample_2(mas_sample_2, mas_sample_2 + 4);
    vector<double> probabilities_2(mas_probabilities_2, mas_probabilities_2 + 4);

    Sample S_1(sample_1, probabilities_1);
    Sample S_2(sample_2, probabilities_2);

    // Act & Assert

    EXPECT_EQ(false, S_1 == S_2);
}

TEST(Polyakov_Igor_MatStatTest, Are_Samples_With_Differ_Prob_Inequal) {

    // Arrange

    double mas_sample_1[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities_1[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample_1(mas_sample_1, mas_sample_1 + 5);
    vector<double> probabilities_1(mas_probabilities_1, mas_probabilities_1 + 5);

    double mas_sample_2[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities_2[5] = { 0.2, 0.1, 0.2667, 0.1, 0.3333 };
    vector<double> sample_2(mas_sample_2, mas_sample_2 + 5);
    vector<double> probabilities_2(mas_probabilities_2, mas_probabilities_2 + 5);

    Sample S_1(sample_1, probabilities_1);
    Sample S_2(sample_2, probabilities_2);

    // Act & Assert

    EXPECT_EQ(false, S_1 == S_2);
}

TEST(Polyakov_Igor_MatStatTest, Is_Calc_Mathematical_Expectation_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    // Act

    double mathematical_expectation = S.CalcMathematicalExpectation();

    // Assert

    EXPECT_NEAR(1.7332, mathematical_expectation, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Dispersion_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    // Act

    double dispersion = S.CalcDispersion();

    // Assert

    EXPECT_NEAR(3.5289, dispersion, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calc_Average_Quadratic_Deviation_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    // Act

    double average_quadratic_deviation = S.CalcAverageQuadraticDeviation();

    // Assert

    EXPECT_NEAR(1.8785, average_quadratic_deviation, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Moment_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    double relative_point = 1.0;
    int exponent = 3;
    
    // Act

    double moment = S.CalcMoment(relative_point, exponent);

    // Assert

    EXPECT_NEAR(8.7324, moment, SAMPLE_EPSILON);

}

TEST(Polyakov_Igor_MatStatTest, Is_Calculate_Elementary_Moment_Correct) {

    // Arrange

    int size_sample = 5;
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

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
    double mas_sample[5] = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    double mas_probabilities[5] = { 0.2, 0.1, 0.3333, 0.1, 0.2667 };
    vector<double> sample(mas_sample, mas_sample + 5);
    vector<double> probabilities(mas_probabilities, mas_probabilities + 5);

    Sample S(sample, probabilities);

    int exponent = 3;

    // Act

    double central_moment = S.CalcCentralMoment(exponent);

    // Assert

    EXPECT_NEAR(0.5762, central_moment, SAMPLE_EPSILON);

}
