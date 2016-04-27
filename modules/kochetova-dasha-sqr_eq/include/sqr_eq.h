// Copyright 2016 Kochetova Dasha
#pragma once

#ifndef MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_
#define MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_

#include <math.h>
#include <iostream>
#include <set>
#include <complex>
#include <array>

using std::cout;
using std::endl;
using std::complex;
using std::set;
using std::array;

typedef double DType;

class Equation {
 private:
    DType _a;
    DType _b;
    DType _c;
    double _x1;
    complex<DType> _cx1;
    double _x2;
    complex<DType> _cx2;
    bool error;

 public:
    Equation();
    Equation(DType a, DType b, DType c);
    DType Discrim();
    set<double> SolveDiscrim();
    set<double> SolveViet();
    void SolveComplex();
    array<double, 2> ParabolaTop();
    DType GetA();
    DType GetB();
    DType GetC();
    DType GetX1();
    complex<DType> GetCx1();
    double GetX2();
    complex<DType> GetCx2();
    bool GetFlag();
    void PutParametrs(DType a, DType b, DType c);
};
#endif  // MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_
