// Copyright 2016 Koshechkin Vlad

#ifndef MODULES_KOSHECHKIN_VLAD_DETERMENANT_INCLUDE_MATRIX_DETERMENANT_H_
#define MODULES_KOSHECHKIN_VLAD_DETERMENANT_INCLUDE_MATRIX_DETERMENANT_H_

#include <string>
#include <stdexcept>
#include <vector>

using std::vector;

class Matrix {
 private:
    int n;
    double Determenant(Matrix &a);

 public:
    vector<int> p_m;
    Matrix();
    Matrix(int count_n);
    Matrix(int count_n, vector<int> matrix);
    Matrix Minor(const int row, const int col);
    int Set(int i, int j, int value);
    int Get(int i, int j);
    double Determenant();
};

class Exception {
 public:
    const char *msg;
    Exception(const char *arg)
        : msg(arg) {
    }
};

#endif  // MODULES_KOSHECHKIN_VLAD_DETERMENANT_INCLUDE_MATRIX_DETERMENANT_H_
