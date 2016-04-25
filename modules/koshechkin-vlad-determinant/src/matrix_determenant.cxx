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
}

Matrix::Matrix(int count_n) {
    if (count_n <= 0)
        throw Incorrect();
    n = count_n;
    p_m.resize(n * n, 0);
}

Matrix::Matrix(int count_n, vector<int> v) {
    if (count_n <= 0)
        throw Incorrect();
    n = count_n;
    p_m = v;
}


int Matrix::Get(int i, int j) const {
    return p_m[i * n + j];
}

int Matrix::Set(int i, int j, int value) {
    return p_m[i * n + j] = value;
}

Matrix Matrix::Minor(const int row, const int col) const {
    if (row >= 0 && row < n && col >= 0 && col < n) {
        Matrix res(n - 1);

        // copy the content of the matrix to the minor, except the selected
        for (int i = 0; i < n; i++) {
            if (i == row) continue;

            for (int j = 0; j < n; j++) {
                if (j == col) continue;

                res.Set(i - (i > row ? 1 : 0),
                        j - (i > col ? 1 : 0),
                        p_m[i * n + j]);
            }
        }
        return res;
    } else {
        throw Incorrect();
    }
}


double Matrix::Determenant(const Matrix &a) const {
    double det = 0;

    // this is a square matrix
    if (a.n == 1) {
        // this is a 1 x 1 matrix
        det = a.Get(0, 0);
    } else {
        if (a.n == 2) {
            // this is a 2 x 2 matrix
            // the determinant of [a11,a12;a21,a22] is det = a11*a22-a21*a12
            det = a.Get(0, 0) * a.Get(1, 1) - a.Get(1, 0) * a.Get(0, 1);
        } else {
            // this is a matrix of 3 x 3 or larger
            for (int i = 0; i < n; i++) {
                Matrix M = a.Minor(0, i);
                det = det + (pow(-1, i + 2) * a.Get(0, i) * Determenant(M));
            }
        }
    }


    return det;
}
