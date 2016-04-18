#include "include\Triangle.h"
#include "math.h"

point::point()
{
    x = 0.0;
    y = 0.0;
}

point::point(double A, double B)
{
    x = A;
    y = B;
}

point::point(point &A)
{
    x = A.x;
    y = A.y;
}

point Triangle::get_A()
{
    return A;
}

point Triangle::get_B()
{
    return B;
}

point Triangle::get_C()
{
    return C;
}

void Triangle::set_A(point _A)
{
    A.x = _A.x;
    A.y = _A.y;
}

void Triangle::set_B(point _B)
{
    B.x = _B.x;
    B.y = _B.y;
}

void Triangle::set_C(point _C)
{
    C.x = _C.x;
    C.y = _C.y;
}

Triangle::Triangle()
{
    A.x = 0.0;
    A.y = 0.0;
    B.x = 2.0;
    B.y = 2.0;
    C.x = 4.0;
    C.y = 0.0;
}

Triangle::Triangle(point _A, point _B, point _C)
{
    set_A(A);
    set_B(B);
    set_C(C);
}

Triangle::Triangle(Triangle& T)
{
    set_A(T.A);
    set_B(T.B);
    set_C(T.C);
}

double Triangle::triangle_side_length(point first_point, point second_point)
{
    double side = hypot(second_point.x-first_point.x,second_point.y-first_point.x);
    return side;
}

double Triangle::angle_A_of_triangle()
{
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(second_side,2)+pow(third_side,2)-pow(first_side,2))/2*second_side*third_side);
    return angle;
}

double Triangle::angle_B_of_triangle()
{
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(third_side, 2) - pow(second_side, 2)) / 2 * first_side*third_side);
    return angle;
}

double Triangle::angle_C_of_triangle()
{
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(second_side, 2) - pow(third_side, 2)) / 2 * first_side*second_side);
    return angle;
}

double Triangle::cos_of_angle(double angle)
{
    return(cos(angle));
}

double Triangle::sin_of_angle(double angle)
{
    return(sin(angle));
}

double Triangle::tan_of_angle(double angle)
{
    return(tan(angle));
}

double Triangle::ctan_of_angle(double angle)
{
    return(1.0/tan(angle));
}

double Triangle::perimeter_of_triangle()
{
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double perimeter = ab + bc + ac;
    return perimeter;
}

double Triangle::area_of_triangle()
{
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A,C);    
    double p = perimeter_of_triangle() / 2;
    double area = pow(p*(p-ab)*(p-bc)*(p-ac), 0.5);
    return area;
}

double Triangle::inradius()
{
    double p = perimeter_of_triangle() / 2;
    double r = area_of_triangle() / p;
    return r;
}

double Triangle::circumradius()
{
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double R = (ab*bc*ac) / (4 * area_of_triangle());
    return R;
}
