// Copyright 2016 Lebedev Ilya

#include "include/random_search.h"

#include <stdlib.h>
#include <string>
#include <limits>

void RandomSearch::Bounds() {
    for (int i = 0; i < dimention_; i++) {
        lowerBorder_[i] = -1.0;
        upperBorder_[i] = 1.0;
    }
}

RandomSearch::RandomSearch(tFunction function,
    int dimention, int iterationCount) : function_(function) {
    lowerBorder_ = 0;
    upperBorder_ = 0;
    if (dimention <= 0)
        throw std::string("Not permissible dimension");
    if (iterationCount < 1)
        throw std::string("Invalid number of iterations");
    dimention_ = dimention;
    iterationCount_ = iterationCount;

    lowerBorder_ = new double[dimention_];
    upperBorder_ = new double[dimention_];
}
RandomSearch::~RandomSearch() {
    if (lowerBorder_ != 0) {
        delete[] lowerBorder_;
        lowerBorder_ = 0;
    }
    if (upperBorder_ != 0) {
        delete[] upperBorder_;
        upperBorder_ = 0;
    }
}

double RandomSearch::FindMinimum(double* globalMinimum) {
    Bounds();

    double* x = new double[dimention_];
    double* d = new double[dimention_];
    double val = 0;
    double minimumValue = std::numeric_limits<double>::max();

    for (int j = 0; j < dimention_; j++)
        d[j] = upperBorder_[j] - lowerBorder_[j];

    static unsigned int rand_state = 0;
    for (int i = 0; i < iterationCount_; i++) {
        for (int j = 0; j < dimention_; j++)
            x[j] = (static_cast<float>(rand_r(&rand_state)) / RAND_MAX) *
                d[j] + lowerBorder_[j];

        val = function_(dimention_, x);
        if (minimumValue > val) {
            minimumValue = val;
            for (int o = 0; o < dimention_; o++)
                globalMinimum[o] = x[o];
        }
    }
    return minimumValue;
}

void RandomSearch::SetDimention(int dimention) {
    if (dimention <= 0)
        throw std::string("Not permissible dimension");

    dimention_ = dimention;

    if (lowerBorder_ != 0)
        delete[] lowerBorder_;
    if (upperBorder_ != 0)
        delete[] upperBorder_;

    lowerBorder_ = new double[dimention_];
    upperBorder_ = new double[dimention_];
}

int RandomSearch::GetDimention() {
    return dimention_;
}

void RandomSearch::SetIterationCount(int iterationCount) {
    iterationCount_ = iterationCount;
}

int RandomSearch::GetIterationCount() {
    return iterationCount_;
}
