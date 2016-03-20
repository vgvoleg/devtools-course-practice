// Copyright 2014 Gladilov Gleb

#ifndef CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_
#define CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_

typedef double ValueType;

class Complex {
// members
 private:
    ValueType real_;
    ValueType imaginary_;

 public:
    // constructors
    Complex();
    Complex(const ValueType real, const ValueType imaginary);
    Complex(const Complex& complex);

    Complex& operator=(const Complex& complex);

    // getters for real and imaginary
    ValueType getReal() const;
    ValueType getImaginary() const;

    // setters for real and imaginary
    void setReal(const ValueType real);
    void setImaginary(const ValueType imaginary);
};

Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);

Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);

#endif  // CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_
