  // Copyright 2016 Maksimenko Alex

#include "include/convertertemp.h"

#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

ConverterTemp::ConverterTemp(const double val, const Measure measure) {
    if ((val < eps) && (measure == Measure::KELVIN)) {
        retcode_ = Data::ERROR;
    } else {
        retcode_ = Data::OK;
        value_ = val;
        measure_ = measure;
        }
}

void ConverterTemp::converter(const Measure measure) {
    const double daughternum[5]{ 273.0, 32.0, 1.8, 33.0, 100.0 };
    switch (measure) {
    case Measure::KELVIN:
            switch (measure_) {
            case Measure::KELVIN:
                measure_ = measure;
                break;
            case Measure::DEGREE:
                if ((value_ + daughternum[0]) < eps) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = value_ + daughternum[0];
                    measure_ = measure;
                    }
                break;
            case Measure::FAHRENHEIT:
                if (((value_ - daughternum[1]) /
                    daughternum[2] + daughternum[0]) < eps) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = ((value_ - daughternum[1]) /
                        daughternum[2] + daughternum[0]);
                    measure_ = measure;
                    }
                break;
            case Measure::NUTON:
                if ((daughternum[4] *(value_) /
                    daughternum[3] + daughternum[0]) < eps) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = (daughternum[4] * value_) /
                        daughternum[3] + daughternum[0];
                    measure_ = measure;
                    }
                break;
            }
        break;
    case Measure::DEGREE:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = value_ - daughternum[0];
                measure_ = measure;
                break;
            case Measure::DEGREE:
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                value_ = (value_ - daughternum[1]) / daughternum[2];
                measure_ = measure;
                break;
            case Measure::NUTON:
                value_ = daughternum[4] *value_ / daughternum[3];
                measure_ = measure;
                break;
            }
        break;
    case Measure::FAHRENHEIT:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = (value_ - daughternum[1]) *
                    daughternum[2] + daughternum[0];
                measure_ = measure;
                break;
            case Measure::DEGREE:
                value_ = daughternum[2] *value_ + daughternum[1];
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                measure_ = measure;
                break;
            case Measure::NUTON:
                value_ = daughternum[2] *(daughternum[4] *(value_ /
                    daughternum[3])) + daughternum[1];
                measure_ = measure;
                break;
            }
        break;
    case Measure::NUTON:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = (daughternum[3] *(value_ - daughternum[0])) /
                   daughternum[4];
                measure_ = measure;
                break;
            case Measure::DEGREE:
                value_ = daughternum[3] *value_ / daughternum[4];
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                value_ = (daughternum[3] *(value_ - daughternum[1]) /
                    daughternum[2]) / daughternum[4];
                measure_ = measure;
                break;
            case Measure::NUTON:
                measure_ = measure;
                break;
            }
        break;
    }
}

Data ConverterTemp::getRetCode() {
    return retcode_;
    retcode_ = Data::OK;
}

double ConverterTemp::getValue()const {
    return value_;
}

Measure ConverterTemp::getMeasure()const {
    return measure_;
}
