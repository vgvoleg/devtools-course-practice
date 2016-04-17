struct point
{
    double x;
    double y;
};

class Triangle
{
    point A;
    point B;
    point C;

    Triangle();
    Triangle(point a,point b, point c);
    Triangle(Triangle &T);

    point get_A();
    point get_B();
    point get_C();

    void set_A(point A);
    void set_B(point B);
    void set_C(point C);

    double triangle_side_length(point first, point second);
    double angle_of_triangle(double first_side, double second_side);
    double cos_of_angle(double angle);
    double sin_of_angle(double angle);
    double tan_of_angle(double angle);
    double ctan_of_angle(double angle);
    double area_of_triangle(Triangle &T);
    double perimeter_of_triangle(Triangle &T);
    double inradius(Triangle &T);
    double circumradius(Triangle &T);
};