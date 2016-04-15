// Copyright 2016 Polyakov Igor

#include "include/MatStat.h"

#include <string.h>
#include <cmath>

#define eps 0.001;

bool Sample::IsSummOfProbabilitiesEqualUnity(vector<double> _probabilities)
{

    double sum_of_probabilities = 0.0;

    for (int i = 0; i < _probabilities.size(); i++)
        sum_of_probabilities += _probabilities[i];

    if (abs(1.0 - sum_of_probabilities) > eps)
        return false;

    return true;

}
bool Sample::AreProbabilitiesCorrect(vector<double> _probabilities)
{

    for (int i = 0; i < _probabilities.size(); i++)
        if (_probabilities[i] <= 0.0 || _probabilities[i] > 1.0)
            return false;

    if (!IsSummOfProbabilitiesEqualUnity(_probabilities))
        return false;

    return true;

}

Sample::Sample(vector<double> _sample,
               vector<double> _probabilities)
{

    if (_sample.size() != _probabilities.size())
        throw std::string("Sizes of _sample and _probabilities must be equal");
    else
        sample_size = _sample.size();

    if (!(Sample::AreProbabilitiesCorrect(_probabilities)))
        throw std::string("Probabilities are not correct");
    else
        probabilities = _probabilities;

    sample = _sample;

}

Sample::~Sample()
{}

