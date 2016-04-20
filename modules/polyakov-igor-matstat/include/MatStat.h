// Copyright 2016 Polyakov Igor

#ifndef MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_
#define MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_

#include <vector>
#include <exception>

using std::vector;

const double SAMPLE_EPSILON = 0.001;


class IncorrectSample :public std::exception {
 public:
     IncorrectSample();
};

class IncorrectProbabilities :public std::exception {
 public:
    IncorrectProbabilities();
};

class IncorrectSizesOfSampleAndProbs :public std::exception {
 public:
     IncorrectSizesOfSampleAndProbs();
};


class Sample {
 private:
    int sample_size;
    vector<double> sample;
    vector<double> probabilities;

    bool IsSummOfProbsEqualUnity(const vector<double> _pr) const;
    bool AreProbsCorrect(const vector<double> _pr) const;
    bool IsSampleCorrect(const vector<double> _sample) const;

 public:
    Sample();
    Sample(const vector<double> _sample,
           const vector<double> _probabilities);
    ~Sample();

    Sample& operator=(const Sample& S);
    bool operator==(const Sample& S) const;

    int GetSampleSize() const;
    vector<double> GetSample() const;
    vector<double> GetProbabilities() const;

    double CalcMathematicalExpectation() const;
    double CalcMoment(const double relative_point, const int exponent) const;
    double CalcElementaryMoment(const int exponent) const;
    double CalcDispersion() const;
    double CalcAverageQuadraticDeviation() const;
    double CalcCentralMoment(const int exponent) const;
};

#endif  // MODULES_POLYAKOV_IGOR_MATSTAT_INCLUDE_MATSTAT_H_
