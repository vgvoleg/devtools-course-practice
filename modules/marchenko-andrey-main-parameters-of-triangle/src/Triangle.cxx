// Copyright 2016 Marchenko Andrey

#include <math.h>
#include <string.h>
#include "include/Triangle.h"

ThreeSamePoints::ThreeSamePoints() {
    std::string("Triangle is not correct, three points are idential");
}

TwoSamePoints::TwoSamePoints() {
    std::string("Triangle is not correct, two points are idential");
}

IncorrectPoints::IncorrectPoints() {
    std::string("Triangle is not correct, all points on one straight line");
}

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(const double A, const double B) {
    x = A;
    y = B;
}

point::point(const point &p) {
    x = p.x;
    y = p.y;
}

bool point::operator==(const point& p) const {
    if (this->x == p.x && this->y == p.y)
        return true;
    else
        return false;
}

point Triangle::get_A() const {
    return A;
}

point Triangle::get_B() const {
    return B;
}

point Triangle::get_C() const {
    return C;
}

double Triangle::get_A_x() const {
    double x = A.x;
    return x;
}

double Triangle::get_A_y() const {
    double y = A.y;
    return y;
}

double Triangle::get_B_x() const {
    double x = B.x;
    return x;
}

double Triangle::get_B_y() const {
    double y = B.y;
    return y;
}

double Triangle::get_C_x() const {
    double x = C.x;
    return x;
}

double Triangle::get_C_y() const {
    double y = C.y;
    return y;
}

void Triangle::set_A(const point _A) {
    A.x = _A.x;
    A.y = _A.y;
}

void Triangle::set_B(const point _B) {
    B.x = _B.x;
    B.y = _B.y;
}

void Triangle::set_C(const point _C) {
    C.x = _C.x;
    C.y = _C.y;
}

Triangle::Triangle() {
    A.x = 0.0;
    A.y = 0.0;
    B.x = 1.0;
    B.y = 1.0;
    C.x = 1.0;
    C.y = 0.0;
}

int Triangle::istreanglecorrect(point _A, point _B, point _C) {
    if (_A == _B && _B == _C) {
        return 1;
    } else if (_A == _B || _A == _C || _B == _C) {
        return 2;
    } else if ((_A.x == _B.x && _B.x == _C.x)
        || (_A.y == _B.y && _B.y == _C.y)) {
        return 3;
    } else if ((_C.y > _B.y && _B.y > _A.y)
        && (_C.x > _B.x && _B.x > _A.x)
        && ((_C.y - _B.y) == (_B.y - _A.y))
        && ((_C.x - _B.x) == (_B.x - _A.x))) {
        return 3;
    } else if ((_C.y > _A.y && _A.y > _B.y)
        && (_C.x > _A.x && _A.x > _B.x)
        && ((_C.y - _A.y) == (_A.y - _B.y))
        && ((_C.x - _A.x) == (_A.x - _B.x))) {
        return 3;
    } else if ((_A.y > _C.y && _C.y > _B.y)
        && (_A.x > _C.x && _C.x > _B.x)
        && ((_A.y - _C.y) == (_C.y - _B.y))
        && ((_A.x - _C.x) == (_C.x - _B.x))) {
        return 3;
    } else if ((_A.y > _B.y && _B.y> _C.y)
        && (_A.x > _B.x && _B.x > _C.x)
        && ((_A.y - _B.y) == (_B.y - _C.y))
        && ((_A.x - _B.x) == (_B.x - _C.x))) {
        return 3;
    } else if ((_B.y > _C.y && _C.y > _A.y)
        && (_B.x > _C.x && _C.x > _A.x)
        && ((_B.y - _C.y) == (_C.y - _A.y))
        && ((_B.x - _C.x) == (_C.x - _A.x))) {
        return 3;
    } else if ((_B.y > _A.y && _A.y > _C.y)
        && (_B.x > _A.x && _A.x > _C.x)
        && ((_B.y - _A.y) == (_A.y - _C.y))
        && ((_B.x - _A.x) == (_A.x - _C.x))) {
        return 3;
    } else 
        return 0;
}

Triangle::Triangle(point _A, point _B, point _C) {
    int key = istreanglecorrect(_A, _B, _C);
    switch (key) {
    case 0: {
                set_A(_A);
                set_B(_B);
                set_C(_C);
                break;
    }
    case 1: {
                throw ThreeSamePoints();
                break;
    }
    case 2: {
                throw TwoSamePoints();
                break;
    }
    case 3: {
                throw IncorrectPoints();
                break;
    }
    }
}

Triangle::Triangle(const Triangle& T) {
    set_A(T.A);
    set_B(T.B);
    set_C(T.C);
}

double Triangle::triangle_side_length(const point first_point,
    const point second_point) const {
    double side = pow(pow((second_point.x - first_point.x), 2)
        + pow(second_point.y - first_point.y, 2), 0.5);
    return side;
}

double Triangle::angle_A_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(third_side, 2)
        - pow(second_side, 2)) / (2 * first_side*third_side));
    return angle;
}

double Triangle::angle_B_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(second_side, 2)
        - pow(third_side, 2)) / (2 * first_side*second_side));
    return angle;
}

double Triangle::angle_C_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(second_side, 2) + pow(third_side, 2)
        - pow(first_side, 2)) / (2 * third_side*second_side));
    return angle;
}

double Triangle::cos_of_angle(const double angle) const {
    return(cos(angle));
}

double Triangle::sin_of_angle(const double angle) const {
    return(sin(angle));
}

double Triangle::tan_of_angle(const double angle) const {
    return(tan(angle));
}

double Triangle::ctan_of_angle(const double angle) const {
    return(1.0/tan(angle));
}

double Triangle::perimeter_of_triangle() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double perimeter = ab + bc + ac;
    return perimeter;
}

double Triangle::area_of_triangle() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double p = perimeter_of_triangle() / 2;
    double area = pow(p*(p-ab)*(p-bc)*(p-ac), 0.5);
    return area;
}

double Triangle::inradius() const {
    double p = perimeter_of_triangle() / 2;
    double r = area_of_triangle() / p;
    return r;
}

double Triangle::circumradius() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double R = (ab*bc*ac) / (4 * area_of_triangle());
    return R;
}

bool Triangle::operator==(const Triangle& T) const {
    if (this->A == T.A && this->B == T.B && this->C == T.C) return true;
    else
        return false;
}
