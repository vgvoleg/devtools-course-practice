// Copyright 2016 Kornyakov Kirill

#include "include/complex_number.h"

#include <stdbool.h>
#include <string>
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

// bool compareComplexWithZero(const ComplexNumber& z);
bool compareComplexWithZero(const ComplexNumber& z) {
    return z.getRe() < eps && z.getRe() > -eps &&
           z.getIm() < eps && z.getIm() > -eps;
}

ComplexNumber::ComplexNumber() : real_(0), imaginary_(0) {}

ComplexNumber::ComplexNumber(const double real,
                             const double imaginary)
                             : real_(real), imaginary_(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber& z)
                             : real_(z.getRe()), imaginary_(z.getIm()) {}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z) {
    real_ = z.getRe();
    imaginary_ = z.getIm();

    return *this;
}

double ComplexNumber::getRe() const {
    return real_;
}

double ComplexNumber::getIm() const {
    return imaginary_;
}

void ComplexNumber::setRe(const double real) {
    real_ = real;
}

void ComplexNumber::setIm(const double imaginary) {
    imaginary_ = imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) {
    ComplexNumber sum;

    sum.setRe(this->getRe() + z.getRe());
    sum.setIm(this->getIm() + z.getIm());

    return sum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) {
    ComplexNumber difference;

    difference.setRe(this->getRe() - z.getRe());
    difference.setIm(this->getIm() - z.getIm());

    return difference;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) {
    ComplexNumber multiplication;

    multiplication.setRe(this->getRe() * z.getRe() -
                           this->getIm() * z.getIm());
    multiplication.setIm(this->getRe() * z.getIm() +
                                this->getIm() * z.getRe());

    return multiplication;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) {
    ComplexNumber division;

    if (compareComplexWithZero(z)) {
        throw std::string("Can't divide by zero");
    } else {
        double denominator = 1.0 / (z.getRe() * z.getRe() +
                                    z.getIm() * z.getIm());

        division.setRe(denominator * this->getRe() * z.getRe() +
                         denominator * this->getIm() * z.getIm());
        division.setIm(denominator * z.getRe() * this->getIm() -
                              denominator * z.getIm() * this->getRe());
    }

    return division;
}
