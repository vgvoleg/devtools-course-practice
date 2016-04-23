// Copyright 2016 Zhiltsov Max

#include <cmath>
#include <functional>
#include "gtest/gtest.h"
#include "volumes_calc.hpp"


TEST(VolumeCalculatorTest, Example_1_Is_Working) {
    static constexpr double pi = 3.1415926535897932384626433832795;
    static constexpr double expectedVolume = 4188.7902047863909846168578443727;

    volume_calc::VolumeCalculator<double> calculator {
        [] (double phi, double theta, double r) {
            return r * r * std::cos(theta);
        },
        0.0,
        2.0 * pi,
        [] (double x) { return - 0.5 * pi; },
        [] (double x) { return + 0.5 * pi; },
        [] (double x, double y) { return 0.0; },
        [] (double x, double y) { return 10.0; }
    };
    const double calculatedVolume = calculator.Calculate(50);

    ASSERT_NEAR(expectedVolume, calculatedVolume, 0.0001 * expectedVolume);
}

TEST(VolumeCalculatorTest, Example_2_Is_Working) {
    static constexpr float pi = 3.1415926535897932384626433832795f;
    static constexpr float expectedVolume = 785.39816339744830961566084581988f;

    volume_calc::VolumeCalculator<float> calculator {
        [] (float phi, float r, float h) {
            return r;
        },
        0.f,
        2.f * pi,
        [] (float phi) { return 0.f; },
        [] (float phi) { return 5.f; },
        [] (float phi, float r) { return 0.f; },
        [] (float phi, float r) { return 10.f; }
    };
    float cylinderVolume = calculator.Calculate();

    ASSERT_NEAR(expectedVolume, cylinderVolume, 0.0001f * expectedVolume);
}

TEST(IntegrateTest, Example_1_Is_Working) {
    static constexpr double expectedResult = 9000.0;

    double result = volume_calc::integrate<double>(0, 30,
        [] (double x) { return x * x; }, 1000);

    ASSERT_NEAR(expectedResult, result, 0.0001 * expectedResult);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
