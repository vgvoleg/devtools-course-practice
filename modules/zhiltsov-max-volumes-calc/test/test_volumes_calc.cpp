// Copyright 2016 Zhiltsov Max

#include <cmath>
#include <functional>
#include "gtest/gtest.h"
#include "zhiltsov_max_volumes_calc.hpp"

using namespace volume_calc;

TEST(VolumeCalculatorTest, Example_1_Is_Working) {
    static constexpr double pi = 3.1415926535897932384626433832795;
    static constexpr double expectedVolume = 4188.7902047863909846168578443727;

    VolumeCalculator<double> calculator (
        [] (double, double theta, double r) {
            return r * r * std::cos(theta);
        },
        0.0,
        2.0 * pi,
        [=] (double) { return - 0.5 * pi; },
        [=] (double) { return + 0.5 * pi; },
        [] (double, double) { return 0.0; },
        [] (double, double) { return 10.0; }
    );
    const double calculatedVolume = calculator.Calculate(50);

    ASSERT_NEAR(expectedVolume, calculatedVolume, 0.0001 * expectedVolume);
}

TEST(VolumeCalculatorTest, Example_2_Is_Working) {
    static constexpr float pi = 3.1415926535897932384626433832795f;
    static constexpr float expectedVolume = 785.39816339744830961566084581988f;

    VolumeCalculator<float> calculator (
        [] (float, float r, float) {
            return r;
        },
        0.f,
        2.f * pi,
        [] (float) { return 0.f; },
        [] (float) { return 5.f; },
        [] (float, float) { return 0.f; },
        [] (float, float) { return 10.f; }
    );
    float cylinderVolume = calculator.Calculate();

    ASSERT_NEAR(expectedVolume, cylinderVolume, 0.0001f * expectedVolume);
}

TEST(IntegrateTest, Example_1_Is_Working) {
	static constexpr double expectedResult = 9000.0;

    double result = integrate<double>(0, 30,
        [] (double x) { return x * x; }, 500
    );

    ASSERT_NEAR(expectedResult, result, 0.0001 * expectedResult);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
