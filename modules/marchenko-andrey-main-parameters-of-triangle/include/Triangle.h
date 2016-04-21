// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_

#include <stdexcept>

class ThreeSamePoints :public std::runtime_error {
 public:
     ThreeSamePoints() : std::runtime_error("Triangle is not correct, three points are idential") {}
};

class TwoSamePoints :public std::runtime_error {
 public:
     TwoSamePoints() : std::runtime_error("Triangle is not correct, two points are idential") {}
};

class IncorrectPoints :public std::runtime_error {
 public:
     IncorrectPoints() : std::runtime_error("Triangle is not correct, all points on one straight line") {}
};

struct point{
    double x;
    double y;

    point();
    point(const double A, const double B);
    point(const point &A);

    bool operator==(const point& p) const;
};

class Triangle{
 private:
    point A;
    point B;
    point C;
    void set_A(const point A_);
    void set_B(const point B_);
    void set_C(const point C_);

 public:
    Triangle();
    Triangle(const point A_, const point B_, const point C_);
    Triangle(const Triangle &T);

    point get_A() const;
    point get_B() const;
    point get_C() const;

    double get_A_x() const;
    double get_A_y() const;
    double get_B_x() const;
    double get_B_y() const;
    double get_C_x() const;
    double get_C_y() const;

    int istreanglecorrect(point A_, point B_, point C_);

    bool operator==(const Triangle& T1) const;

    double triangle_side_length(const point first_point,
        const point second_point) const;
    double angle_A_of_triangle_in_radians() const;
    double angle_B_of_triangle_in_radians() const;
    double angle_C_of_triangle_in_radians() const;
    double cos_of_angle(const double angle) const;
    double sin_of_angle(const double angle) const;
    double tan_of_angle(const double angle) const;
    double ctan_of_angle(const double angle) const;
    double perimeter_of_triangle() const;
    double area_of_triangle() const;
    double inradius() const;
    double circumradius() const;
};

#endif  // MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
