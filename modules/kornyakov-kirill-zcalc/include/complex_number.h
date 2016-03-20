// Copyright 2016 Kornyakov Kirill

#ifndef MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEXCALCULATOR_H_
#define MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEXCALCULATOR_H_

class ComplexNumber {
 private:
    double real_;
    double imaginary_;

 public:
    ComplexNumber();
    ComplexNumber(const double real, const double imaginary);
    ComplexNumber(const ComplexNumber& z);

    ComplexNumber& operator=(const ComplexNumber& z);

    double getReal() const;
    double getImaginary() const;

    void setReal(const double real);
    void setImaginary(const double imaginary);

    ComplexNumber operator + (const ComplexNumber& z);
    ComplexNumber operator - (const ComplexNumber& z);
    ComplexNumber operator * (const ComplexNumber& z);
    ComplexNumber operator / (const ComplexNumber& z);
};

#endif  // MODULES_KORNYAKOV_KIRILL_ZCALC_INCLUDE_COMPLEXCALCULATOR_H_
