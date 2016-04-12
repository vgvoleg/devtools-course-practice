// Copyright 2016 Lebedev Ilya

#ifndef MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_
#define MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_

typedef double(*tFunction)(int, double*);

class RandomSearch {
public:
    RandomSearch(tFunction function, int dimention = 1, int iterationCount = 1);
    ~RandomSearch();

    double FindMinimum(double* globalMinimum);

    void SetDimention(int dimention);
    int GetDimention();
    void SetIterationCount(int iterationCount);
    int GetIterationCount();


private:
    void Bounds();

    int dimention_;
    int iterationCount_;
    double* lowerBorder_;
    double* upperBorder_;
    tFunction function_;
};

#endif // MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_
