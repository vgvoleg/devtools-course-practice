// Copyright 2016 Lebedev Ilya

#ifndef MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_
#define MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_

typedef double(*tFunction)(int, double*);

class RandomSearch {
 public:
    explicit RandomSearch(tFunction function,
        int dimension = 1, int iterationCount = 1);
    ~RandomSearch();

    double FindMinimum(double* globalMinimum);

    void SetDimension(int dimension);
    int GetDimension();
    void SetIterationCount(int iterationCount);
    int GetIterationCount();


 private:
    void Bounds();

    int dimension_;
    int iterationCount_;
    double* lowerBorder_;
    double* upperBorder_;
    tFunction function_;
};

#endif  // MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_RANDOM_SEARCH_H_
