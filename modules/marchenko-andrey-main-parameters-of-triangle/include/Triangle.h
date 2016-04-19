// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_

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

 public:
    Triangle();
    Triangle(const point a, const point b, const point c);
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

    void set_A(const point A);
    void set_B(const point B);
    void set_C(const point C);

    bool operator==(const Triangle& T1) const;

    double triangle_side_length(const point first_point,
        const point second_point) const;
    double angle_A_of_triangle() const;
    double angle_B_of_triangle() const;
    double angle_C_of_triangle() const;
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
