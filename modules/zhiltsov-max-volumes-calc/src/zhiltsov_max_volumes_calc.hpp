#ifndef ZHILTSOV_MAX_VOLUMES_CALC_H_
#define ZHILTSOV_MAX_VOLUMES_CALC_H_

#include <functional>

namespace volume_calc {
/*
Class for numerical integration of given function in given boundaries
accoridng to a formula: 
    volume = integral(a, b, dx, integral(g, h, dy, integral(u, v, dz, f))),
where 
    f = f(x, y) - function to be integrated, 
    a - const   - first integral lower boundary, 
    b - const   - first integral upper boundary,
    g = g(x)    - second internal lower boundary, 
    h = h(x)    - second internal upper boundary, 
    u = u(x, y) - third internal lower boundary,
    v = v(x, y) - third internal upper boundary.

It allows to use a dependent boundary functions for inner boundaries (functions
g(x) and h(x), u(x, y) and v(x, y)).

Class template parameter NumberType allows to use a custom numerical types in 
calculations.

Usage exmaple:

// Calculate a voulme of sphere of radius 10:
VolumeCalculator<double> calculator {
    [] (const double& const double&) { return 1; },
    0, 
    2 * MATH_PI,
    [] (const double&) { return - 0.5 * MATH_PI; },
    [] (const double&) { return + 0.5 * MATH_PI; },
    [] (const double&, const double&) { return 0; },
    [] (const double&, const double&) { return 10; }
};
sphereVolume = calculator.Calculate(); // approx. 4/3 * MATH_PI * 10^3

*/
template<class NumberType = float>
class VolumeCalculator {
  public:
    template<class Ret, class... Args>
    using function = std::function<Ret(Args...)>;
    using Boundary2Func = function<NumberType(*)(const NumberType&)>;
    using Boundary3Func = function<
        NumberType(*)(const NumberType&, const NumberType&)>;
    using Func = function<
        NumberType(*)(const NumberType&, const NumberType&, const NumberType&)>;
    static constexpr size_t kDefaultPartitionCount = 1000;

    VolumeCalculator(const Func& func,
        const NumberType& boundary1Min,
        const NumberType& boundary1Max,
        const Boundary2Func& boundary2Min,
        const Boundary2Func& boundary2Max,
        const Boundary3Func& boundary3Min,
        const Boundary3Func& boundary3Max
    ) :
        boundary1Min(boundary1Min),
        boundary1Max(boundary1Max),
        boundary2Min(boundary2Min),
        boundary2Max(boundary2Max),
        boundary3Min(boundary3Min),
        boundary3Max(boundary3Max),
        func(func)
    {}

    NumberType Calculate(size_t partitionCount = kDefaultPartitionCount) {
        using std::bind;
        using namespace std::placeholders;

        return integrate(boundary1Min, boundary1Max, 
            bind(integrate, boundary2Min(_1), boundary2Max(_1), 
                [&] (const NumberType& x) {
                    return integrate(boundary3Min(_1, x), boundary3Max(_1, x),
                        [&] (const NumberType& y) { return func(_1, x, y); }
                    );
                }
            ), 
            partitionCount);
    }

  private:
    NumberType boundary1Min;
    NumberType boundary1Max;
    Boundary2Func boundary2Min;
    Boundary2Func boundary2Max;
    Boundary3Func boundary3Min;
    Boundary3Func boundary3Max;
    Func func;

    NumberType integrate(const NumberType& lower, const NumberType& upper,
        const function<NumberType (*)(const NumberType&)>& f,
        size_t partitionCount = kDefaultPartitionCount) 
    {
        const auto step = (upper - lower) / partitionCount;
        NumberType result;
        for (size_t i = 0; i < partitionCount; ++i) {
            result += f(lower + step * i);
        }
        return result;
    }
};

} // namespace volume_calc


#endif // ZHILTSOV_MAX_VOLUMES_CALC_H_