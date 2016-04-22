  // Copyright 2016 Maksimenko Alex

#include "include/convertertemp.h"

ConverterTemp::ConverterTemp(const double val, Measure measure) {
    if ((val < 0) && (measure == KELVIN)) {
        retcode_ = Data::ERROR;
    } else {
        retcode_ = Data::OK;
        this->value_ = val;
        this->measure_ = measure;
        }
}

void ConverterTemp::converter(const Measure measure) {
    double num1 = 273;
    double num2 = 32;
    double num3 = 1.8;
    double num4 = 33;
    double num5 = 100;
    switch (measure) {
    case KELVIN:
            switch (measure_) {
            case KELVIN:
                this->measure_ = measure;
                break;
            case DEGREE:
                if ((value_ + num1) < 0) {
                    retcode_ = Data::ERROR;
                } else {
                    this->value_ = value_ + num1;
                    this->measure_ = measure;
                    }
                break;
            case FAHRENHEIT:
                if (((value_ - num2) / num3 + num1) < 0) {
                    retcode_ = Data::ERROR;
                } else {
                    this->value_ = (value_ - num2) / num3 + num1;
                    this->measure_ = measure;
                    }
                break;
            case NUTON:
                if ((num5*(value_) / num4 + num1) < 0) {
                    retcode_ = Data::ERROR;
                } else {
                    this->value_ = num5*(value_) / num4 + num1;
                    this->measure_ = measure;
                    }
                break;
            }
        break;
    case DEGREE:
            switch (measure_) {
            case KELVIN:
                this->value_ = value_ - num1;
                this->measure_ = measure;
                break;
            case DEGREE:
                this->measure_ = measure;
                break;
            case FAHRENHEIT:
                this->value_ = (value_ - num2) / num3;
                this->measure_ = measure;
                break;
            case NUTON:
                this->value_ = num5*value_ / num4;
                this->measure_ = measure;
                break;
            }
        break;
    case FAHRENHEIT:
            switch (measure_) {
            case KELVIN:
                this->value_ = (value_ - num2) * num3 + num1;
                this->measure_ = measure;
                break;
            case DEGREE:
                this->value_ = num3*value_ + num2;
                this->measure_ = measure;
                break;
            case FAHRENHEIT:
                this->measure_ = measure;
                break;
            case NUTON:
                this->value_ = num3*(num5*(value_ / num4)) + num2;
                this->measure_ = measure;
                break;
            }
        break;
    case NUTON:
            switch (measure_) {
            case KELVIN:
                this->value_ = (num4*(value_ - num1)) / num5;
                this->measure_ = measure;
                break;
            case DEGREE:
                this->value_ = num4*value_ / num5;
                this->measure_ = measure;
                break;
            case FAHRENHEIT:
                this->value_ = (num4*(value_ - num2) / num3) / num5;
                this->measure_ = measure;
                break;
            case NUTON:
                measure_ = measure;
                break;
            }
        break;
    }
}

int ConverterTemp::getRetCode() {
    return retcode_;
    retcode_ = Data::OK;
}

const double ConverterTemp::getValue() {
    return value_;
}
