// Copyright 2016 Polyakov Igor

#include <gtest/gtest.h>
#include <cmath>
#include "include/MatStat.h"


TEST(Polyakov_Igor_MatStatTest, Is_Initialization_Sample_Correct) {

    // Arrange

    int size_sample = 5;
    vector<double> sample = { 1.0, 3.0, 4.0, -1.0, 0.0 };
    vector<double> probabilities = {0.2, 0.1, 0.3333, 0.1, 0.2777};

    Sample S(size_sample, sample, probabilities);

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