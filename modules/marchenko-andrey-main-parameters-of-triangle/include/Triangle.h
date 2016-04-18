struct point
{
    double x;
    double y;

    point();
    point(double A, double B);
    point(point &A);
};

class Triangle
{
private:
    point A;
    point B;
    point C;
public:
    Triangle();
    Triangle(point a,point b, point c);
    Triangle(Triangle &T);

    point get_A();
    point get_B();
    point get_C();

    void set_A(point A);
    void set_B(point B);
    void set_C(point C);

    double triangle_side_length(point first_point, point second_point);
    double angle_A_of_triangle();
    double angle_B_of_triangle();
    double angle_C_of_triangle();
    double cos_of_angle(double angle);
    double sin_of_angle(double angle);
    double tan_of_angle(double angle);
    double ctan_of_angle(double angle);
    double perimeter_of_triangle();
    double area_of_triangle();
    double inradius();
    double circumradius();
};
