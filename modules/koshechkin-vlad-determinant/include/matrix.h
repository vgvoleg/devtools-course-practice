// Copyright 2016 Koshechkin Vlad

#ifndef MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_
#define MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_

#include <string>
#include <stdexcept>
#include <vector>

using std::vector;

class Matrix {
 private:
    int n;
 public:
    vector<int> p_m;
    Matrix();
    explicit Matrix(int count_n);
    Matrix(int count_n, vector<int> matrix);
    Matrix Minor(const int row, const int col) const;
    int Set(int i, int j, int value);
    int Get(int i, int j) const;
    double Determinant(const Matrix &a) const;
};

class Exception {
 public:
    const char *msg;
    explicit Exception(const char *arg)
        : msg(arg) {
    }
};

#endif  // MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_
