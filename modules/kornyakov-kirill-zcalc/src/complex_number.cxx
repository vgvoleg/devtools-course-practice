// Copyright 2016 Kornyakov Kirill

#include "include/complex_number.h"

#include <stdbool.h>
#include <string>
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

// bool compareComplexWithZero(const ComplexNumber& z);
bool compareComplexWithZero(const ComplexNumber& z) {
    return z.getReal() < eps && z.getReal() > -eps &&
           z.getImaginary() < eps && z.getImaginary() > -eps;
}

ComplexNumber::ComplexNumber() : real_(0), imaginary_(0) {}

ComplexNumber::ComplexNumber(const double real,
                             const double imaginary) :
                             real_(real), imaginary_(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber& z) :
                             real_(z.getReal()), imaginary_(z.getImaginary()) {}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z) {
    real_ = z.getReal();
    imaginary_ = z.getImaginary();

    return *this;
}

double ComplexNumber::getReal() const {
    return real_;
}

double ComplexNumber::getImaginary() const {
    return imaginary_;
}

void ComplexNumber::setReal(const double real) {
    real_ = real;
}

void ComplexNumber::setImaginary(const double imaginary) {
    imaginary_ = imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) {
    ComplexNumber sum;

    sum.setReal(this->getReal() + z.getReal());
    sum.setImaginary(this->getImaginary() + z.getImaginary());

    return sum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) {
    ComplexNumber difference;

    difference.setReal(this->getReal() - z.getReal());
    difference.setImaginary(this->getImaginary() - z.getImaginary());

    return difference;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) {
    ComplexNumber multiplication;

    multiplication.setReal(this->getReal() * z.getReal() -
                           this->getImaginary() * z.getImaginary());
    multiplication.setImaginary(this->getReal() * z.getImaginary() +
                                this->getImaginary() * z.getReal());

    return multiplication;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) {
    ComplexNumber division;

    if (compareComplexWithZero(z)) {
        throw std::string("Can't divide by zero");
    } else {
        double denominator = 1.0 / (z.getReal() * z.getReal() +
                                    z.getImaginary() * z.getImaginary());

        division.setReal(denominator * this->getReal() * z.getReal() +
                         denominator * this->getImaginary() * z.getImaginary());
        division.setImaginary(denominator * z.getReal() * this->getImaginary() -
                              denominator * z.getImaginary() * this->getReal());
    }

    return division;
}
