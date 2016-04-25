// Copyright 2016 Koshechkin Vlad

#include "include/matrix_determenant.h"
#include <math.h>
#include <utility>
#include <cstdlib>
#include <vector>


using std::vector;

Matrix::Matrix() {
// create a Matrix object without content
    n = 0;
};

Matrix::Matrix(int count_n) {

    if (count_n <= 0) {

        throw Exception("Index for matrix out of range");

    }
    else {
        n = count_n;
        p_m.resize(n*n, 0);

    }
};

Matrix::Matrix(int count_n, vector<int> v) {

    if (count_n <= 0) {

        throw Exception("Index for matrix out of range");

    }
    else {
        n = count_n;
        p_m = v;
    }
};


int Matrix::Get(int i, int j) {
    return p_m[i * n + j];
}

int Matrix::Set(int i, int j, int value) {
    return p_m[i * n + j] = value;
}

Matrix Matrix::Minor(const int row, const int col) {
    if (row > 0 && row <= n && col > 0 && col <= n) {
        Matrix res(n - 1);

        // copy the content of the matrix to the minor, except the selected
        for (int i = 1; i <= (n - (row >= n)); i++) {
            for (int j = 1; j <= (n - (col >= n)); j++) {
                res.Set(i - (i > row),
                        j - (j > row),
                        p_m[(i - 1) * n + (j - 1)]);
            }
        }
        return res;
    }
    else {
        throw Exception("Index for minor out of range");
    }
}

double Matrix::Determenant() {

    double det = 1;

    // this is a square matrix
    if (n == 1) {
        // this is a 1 x 1 matrix
        det = Get(0, 0);
    }
    else {
        if (n == 2) {
            // this is a 2 x 2 matrix
            // the determinant of [a11,a12;a21,a22] is det = a11*a22-a21*a12
            det = Get(0, 0) * Get(1, 1) - Get(1, 0) * Get(0, 1);
        }
        else {
            // this is a matrix of 3 x 3 or larger
            for (int i = 0; i <= n; i++) {
                Matrix M = Minor(0, i);
                det += (i % 2 + i % 2 - 1) * Get(0, i) * Determenant(M);
            }
        }
    }

    return det;
};
double Matrix::Determenant(Matrix &a) {

    double det = 1;

    // this is a square matrix
    if (n == 1) {
        // this is a 1 x 1 matrix
        det = Get(0, 0);
    }
    if (n == 2) {
        // this is a 2 x 2 matrix
        // the determinant of [a11,a12;a21,a22] is det = a11*a22-a21*a12
        det = a.Get(0, 0) * a.Get(1, 1) - a.Get(1, 0) * a.Get(0, 1);
    }
    else {
        // this is a matrix of 3 x 3 or larger
        for (int i = 1; i <= n; i++) {
            Matrix M = a.Minor(0, i);
            det += (i % 2 + i % 2 - 1) * a.Get(0, i) * Determenant(M);
        }
    }


    return det;
};
