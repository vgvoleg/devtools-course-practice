// Copyright 2016 Hramov Ilya

#ifndef MODULES_HRAMOV_ILYA_QUATERNION_INCLUDE_QUATERNION_H_
#define MODULES_HRAMOV_ILYA_QUATERNION_INCLUDE_QUATERNION_H_

#include <math.h>
#include <limits>

const double epsilon = std::numeric_limits<double>::epsilon();

class Quaternion
{
public:
    // Fields
    double x;
    double y;
    double z;
    double w;

    // Constructor
	Quaternion(
        const double &_x = 0.0,
        const double &_y = 0.0,
        const double &_z = 0.0,
        const double &_w = 0.0);

    // Operators
    Quaternion operator+(const Quaternion &operand) const;
	Quaternion operator-(const Quaternion &operand) const;
	Quaternion& operator+=(const Quaternion &operand);
	Quaternion& operator-=(const Quaternion &operand);
	Quaternion operator*(const Quaternion &operand) const;
	Quaternion& operator*=(const Quaternion &operand);
	Quaternion operator!() const; // conjugate
	Quaternion operator~() const; // inverse
    bool operator==(const Quaternion &operand) const;
    bool operator!=(const Quaternion &operand) const;
    friend Quaternion operator*(const double &scalar, const Quaternion &operand);

    // Math actions
	double magnitude() const;
	double qmagnitude() const;
	Quaternion normalized() const;
    Quaternion inversed() const;
    Quaternion conjugated() const;

private:
    bool isZero(const Quaternion &operand) const;
};

#endif // MODULES_HRAMOV_ILYA_QUATERNION_INCLUDE_QUATERNION_H_
