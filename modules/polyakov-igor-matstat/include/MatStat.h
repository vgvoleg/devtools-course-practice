// Copyright 2016 Polyakov Igor

#ifndef MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_SAMPLE_H_
#define MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_SAMPLE_H_

#include <vector>


const int PROBABILITIES_NOT_CORRECT - 3;
const int SAMPLE_NOT_CORRECT - 2;
const int SIZES_OF_SAMPLE_AND_PROB_DIFFER - 1;

const double SAMPLE_EPSILON = 0.001;


class Sample
{

private:

    int sample_size; // Размер выборки
    vector<double> sample; // Значения выборки
    vector<double> probabilities; // Вероятности

    bool IsSummOfProbabilitiesEqualUnity(vector<double> _probabilities);
    bool AreProbabilitiesCorrect(vector<double> _probabilities);
    bool IsSampleCorrect(vector<double> _sample);

public:

    Sample(vector<double> _sample, vector<double> _probabilities);
    ~Sample();

    Sample(const Sample& S);

    Sample& operator=(const Sample& S);

    int GetSampleSize();
    vector<double> GetSample();
    vector<double> GetProbabilities();

    double CalcMathematicalExpectation();
    double CalcMoment(double relative_point, int exponent);
    double CalcElementaryMoment(int exponent);
    double CalcDispersion();
    double CalcAverageQuadraticDeviation();
    double CalcCentralMoment(int exponent);

};

#endif  // MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_SAMPLE_H_
