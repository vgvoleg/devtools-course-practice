// Copyright 2016 Polyakov Igor

#ifndef MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_SAMPLE_H_
#define MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_SAMPLE_H_

#include <vector>
#include <exception>

const double SAMPLE_EPSILON = 0.001;

using namespace std;


class IncorrectSample :public exception {
public:
    IncorrectSample(){
        string("Sample is not correct. Values must be different.");
    }
};

class IncorrectProbabilities :public exception {
public:
    IncorrectProbabilities(){ // конструктор
        string("Probabilities is not correct.");
    }
};

class IncorrectSizesOfSampleAndProbabilities :public exception {
public:
    IncorrectSizesOfSampleAndProbabilities(){
        string("Sizes of sample and probabilities must be identical");
    }
};

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
