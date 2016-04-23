// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

#include "include/mass_unit.h"

template<typename FromUnit, typename ToUnit>
class MassConverter {
 public:
    MassConverter() {
        if (!std::is_base_of<MassUnit, FromUnit>::value ||
            !std::is_base_of<MassUnit, ToUnit>::value) {
            throw std::invalid_argument(
                    "Template parameters must subclass MassUnit class");
        }

        this->fromUnit = new FromUnit();
        this->toUnit = new ToUnit();
    }

    virtual ~MassConverter() {
        delete fromUnit;
        delete toUnit;
    }

    double convert(double value) {
        if (value < 0)
            throw std::invalid_argument("Value must be not negative");

        if (value == 0) return 0;

        double conversion_coefficient = fromUnit->get_relative_coefficient() /
                                        toUnit->get_relative_coefficient();

        return value * conversion_coefficient;
    }

 private:
    MassUnit *fromUnit;
    MassUnit *toUnit;
};

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
