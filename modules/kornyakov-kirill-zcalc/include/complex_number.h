// Copyright 2016 Kornyakov Kirill

#ifndef MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_NUMBER_H_

class ComplexNumber {
 public:
    ComplexNumber();
    ComplexNumber(const double real, const double imaginary);
    ComplexNumber(const ComplexNumber& z);

    ComplexNumber& operator=(const ComplexNumber& z);

    double getRe() const;
    double getIm() const;
    void setRe(const double real);
    void setIm(const double imaginary);

    ComplexNumber operator + (const ComplexNumber& z);
    ComplexNumber operator - (const ComplexNumber& z);
    ComplexNumber operator * (const ComplexNumber& z);
    ComplexNumber operator / (const ComplexNumber& z);

 private:
    double real_;
    double imaginary_;
};

#endif  // MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEX_NUMBER_H_
