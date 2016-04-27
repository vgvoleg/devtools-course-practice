// Copyright 2016 Sharadze Georgy

#ifndef COMPLEX_NUMBER_H_
#define COMPLEX_NUBMER_H_

class ComplexNumber {
 private:
    double re;
    double im;
    bool equalsToZero(const ComplexNumber& z) const;
 public:
     ComplexNumber();
     ComplexNumber(double _re, double _im);
     ComplexNumber(const ComplexNumber& z);

     double getRe() const;
     double getIm() const;
     void setRe(const double _re);
     void setIm(const double _im);

     ComplexNumber operator+(const ComplexNumber& z) const;
     ComplexNumber operator-(const ComplexNumber& z) const;
     ComplexNumber operator*(const ComplexNumber& z) const;
     ComplexNumber operator/(const ComplexNumber& z) const;
     ComplexNumber operator=(const ComplexNumber& z);
     bool operator==(const ComplexNumber& z) const;
     bool operator!=(const ComplexNumber& z) const;
     friend ComplexNumber calc(const ComplexNumber& z1, 
                          const ComplexNumber& z2, 
                          const char op);
};

#endif
