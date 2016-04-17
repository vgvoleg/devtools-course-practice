// Copyright 2016 Polyakov Igor

#include "include/MatStat.h"

#include <string.h>
#include <cmath>
#include <vector>


bool Sample::IsSummOfProbabilitiesEqualUnity(std::vector<double> _prob) {
    double sum_of_probabilities = 0.0;

    for (unsigned int i = 0; i < _prob.size(); i++) {
        sum_of_probabilities += _prob[i];
    }

    if (abs(1.0 - sum_of_probabilities) > SAMPLE_EPSILON) {
        return false;
    }

    return true;
}

bool Sample::AreProbabilitiesCorrect(std::vector<double> _probabilities) {
    for (unsigned int i = 0; i < _probabilities.size(); i++) {
        if (_probabilities[i] <= 0.0 || _probabilities[i] > 1.0) {
            return false;
        }
    }

    if (!IsSummOfProbabilitiesEqualUnity(_probabilities)) {
        return false;
    }

    return true;
}

bool Sample::IsSampleCorrect(std::vector<double> _sample) {
    for (unsigned int i = 0; i < _sample.size() - 1; i++) {
        for (unsigned int j = i + 1; j < _sample.size(); j++) {
            if (_sample[i] == _sample[j]) {
                return false;
            }
        }
    }

    return true;
}

Sample::Sample(std::vector<double> _sample,
    std::vector<double> _probabilities) {
    if (_sample.size() != _probabilities.size()) {
        throw IncorrectSizesOfSampleAndProbabilities();
    } else {
        sample_size = _sample.size();
    }

    if (!AreProbabilitiesCorrect(_probabilities)) {
        throw IncorrectProbabilities();
    } else {
        probabilities = _probabilities;
    }

    if (!IsSampleCorrect(_sample)) {
        throw IncorrectSample();
    } else {
        sample = _sample;
    }
}

Sample::~Sample() {
}

Sample::Sample(const Sample& S) {
    sample_size = S.sample_size;
    sample = S.sample;
    probabilities = S.probabilities;
}

Sample& Sample::operator=(const Sample& S) {
    sample_size = S.sample_size;
    sample = S.sample;
    probabilities = S.probabilities;

    return *this;
}

bool Sample::operator==(const Sample& S) const {
    if (sample_size < S.sample_size) {
        return false;
    }

    for (int i = 0; i < sample_size; i++) {
        if (sample[i] != S.sample[i] ||
            probabilities[i] != S.probabilities[i]) {
            return false;
        }
    }

    return true;
}

int Sample::GetSampleSize() {
    return sample_size;
}

std::vector<double> Sample::GetSample() {
    return sample;
}

std::vector<double> Sample::GetProbabilities() {
    return probabilities;
}

double Sample::CalcMathematicalExpectation() {
    double mathematical_expectation = 0.0;

    for (int i = 0; i < sample_size; i++) {
        mathematical_expectation += sample[i] * probabilities[i];
    }

    return mathematical_expectation;
}

double Sample::CalcMoment(double relative_point,
                          int exponent) {
    double moment = 0.0;

    for (int i = 0; i < sample_size; i++) {
        double power = pow((sample[i] - relative_point), exponent);
        moment += power * probabilities[i];
    }

    return moment;
}

double Sample::CalcElementaryMoment(int exponent) {
    double elementary_moment = 0.0;

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i], exponent);
        elementary_moment += power * probabilities[i];
    }

    return elementary_moment;
}

double Sample::CalcDispersion() {
    double dispersion = 0.0;
    double mathematical_expectation = CalcMathematicalExpectation();

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i] - mathematical_expectation, 2.0);
        dispersion += power * probabilities[i];
    }

    return dispersion;
}

double Sample::CalcAverageQuadraticDeviation() {
    return sqrt(CalcDispersion());
}

double Sample::CalcCentralMoment(int exponent) {
    double central_moment = 0.0;
    double mathematical_expectation = CalcMathematicalExpectation();

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i] - mathematical_expectation, exponent);
        central_moment += power * probabilities[i];
    }

    return central_moment;
}
