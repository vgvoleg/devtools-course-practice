// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"

#include <stdbool.h>
#include <string>
#include <limits>

bool compareComplexWithZero(const Complex& complex);
bool compareComplexWithZero(const Complex& complex) {
    if (complex.getReal() < std::numeric_limits<ValueType>::epsilon() &&
        complex.getReal() > -std::numeric_limits<ValueType>::epsilon() &&

        complex.getImaginary() < std::numeric_limits<ValueType>::epsilon() &&
        complex.getImaginary() > -std::numeric_limits<ValueType>::epsilon())
        return true;
    else
        return false;
}

Complex::Complex() : real_(0), imaginary_(0) {}
Complex::Complex(const ValueType real,
                 const ValueType imaginary) : real_(real),
                                                  imaginary_(imaginary) {}

Complex::Complex(const Complex& complex) : real_(complex.getReal()),
                                           imaginary_(complex.getImaginary()) {}

Complex& Complex::operator=(const Complex& complex) {
    real_ = complex.getReal();
    imaginary_ = complex.getImaginary();

    return *this;
}
ValueType Complex::getReal() const {
    return real_;
}
ValueType Complex::getImaginary() const {
    return imaginary_;
}

void Complex::setReal(const ValueType real) {
    real_ = real;
}
void Complex::setImaginary(const ValueType imaginary) {
    imaginary_ = imaginary;
}

Complex operator+(const Complex& a, const Complex& b) {
    Complex sum;

    sum.setReal(a.getReal() + b.getReal());
    sum.setImaginary(a.getImaginary() + b.getImaginary());

    return sum;
}
Complex operator-(const Complex& a, const Complex& b) {
    Complex difference;

    difference.setReal(a.getReal() - b.getReal());
    difference.setImaginary(a.getImaginary() - b.getImaginary());

    return difference;
}
Complex operator*(const Complex& a, const Complex& b) {
    Complex multiplication;

    multiplication.setReal(a.getReal() * b.getReal() -
                           a.getImaginary() * b.getImaginary());
    multiplication.setImaginary(a.getReal() * b.getImaginary() +
                                a.getImaginary() * b.getReal());

    return multiplication;
}
Complex operator/(const Complex& a, const Complex& b) {
    Complex division;

    if (compareComplexWithZero(b)) {
        throw std::string("Can't divide by zero");
    } else {
        ValueType dnmtr = static_cast<ValueType>(1) /
                          (b.getReal() * b.getReal() +
                           b.getImaginary() * b.getImaginary());

        division.setReal(dnmtr * a.getReal() * b.getReal() +
                         dnmtr * a.getImaginary() * b.getImaginary());
        division.setImaginary(dnmtr * b.getReal() * a.getImaginary() -
                              dnmtr * b.getImaginary() * a.getReal());
    }

    return division;
}
