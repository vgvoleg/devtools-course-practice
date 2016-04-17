// Copyright 2016 Polyakov Igor

#ifndef MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_
#define MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_

#include <vector>
#include <exception>
#include <string>


const double SAMPLE_EPSILON = 0.001;


class IncorrectSample :public std::exception
{

public:
    IncorrectSample()
    {
        std::string("Sample is not correct, values must be different");
    }
};

class IncorrectProbabilities :public std::exception 
{

public:
    IncorrectProbabilities()
    {
        std::string("Probabilities is not correct");
    }
};

class IncorrectSizesOfSampleAndProbabilities :public std::exception
{

public:
    IncorrectSizesOfSampleAndProbabilities()
    {
        std::string("Sizes of sample and probabilities must be identical");
    }
};

class Sample
{

private:
    int sample_size;  //  Размер выборки
    std::vector<double> sample;  //  Значения выборки
    std::vector<double> probabilities;  //  Вероятности

    bool IsSummOfProbabilitiesEqualUnity(std::vector<double> _probabilities);
    bool AreProbabilitiesCorrect(std::vector<double> _probabilities);
    bool IsSampleCorrect(std::vector<double> _sample);

public:
    Sample(std::vector<double> _sample, std::vector<double> _probabilities);
    ~Sample();

    Sample(const Sample& S);

    Sample& operator=(const Sample& S);
    bool operator==(const Sample& S) const;

    int GetSampleSize();
    std::vector<double> GetSample();
    std::vector<double> GetProbabilities();

    double CalcMathematicalExpectation();
    double CalcMoment(double relative_point, int exponent);
    double CalcElementaryMoment(int exponent);
    double CalcDispersion();
    double CalcAverageQuadraticDeviation();
    double CalcCentralMoment(int exponent);
};

#endif  // MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_