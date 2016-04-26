// Copyright 2016 Koshechkin Vlad

#include "include/matrix.h"
#include <math.h>
#include <utility>
#include <cstdlib>
#include <vector>


using std::vector;

Matrix::Matrix(const int count_n) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    n = count_n;
    matrix.resize(n * n, 0);
}

Matrix::Matrix(const int count_n, const vector<int> v) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    long k = v.size();
    if (sqrt(k)!=count_n)
        throw std::invalid_argument("Vector must have the same size as matrix");
    n = count_n;
    matrix = v;
}


int Matrix::Get(const int i, const int j) const {
    return matrix[i * n + j];
}

int Matrix::Set(const int i, const int j, const int value) {
    return matrix[i * n + j] = value;
}

Matrix Matrix::Minor(const int row, const int col) const {
    if (row < 0 || row >= n || col < 0 || col >= n)
        throw std::out_of_range("Incorrect row or col");

    Matrix res(n - 1);
    for (int i = 0; i < n; i++) {
        if (i == row) continue;

        for (int j = 0; j < n; j++) {
            if (j == col) continue;

            res.Set(i - (i > row ? 1 : 0),
                    j - (j > col ? 1 : 0),
                    matrix[i * n + j]);
        }
    }
    return res;
}


double Matrix::Determinant(const Matrix &a) const {
    if (a.n == 1)
        return a.Get(0, 0);

    if (a.n == 2)
        return a.Get(0, 0) * a.Get(1, 1) - a.Get(1, 0) * a.Get(0, 1);

    double det = 0;
    for (int i = 0; i < n; i++) {
        Matrix M = a.Minor(0, i);
        det = det + (pow(-1, i + 2) * a.Get(0, i) * Determinant(M));
    }
    return det;
}
