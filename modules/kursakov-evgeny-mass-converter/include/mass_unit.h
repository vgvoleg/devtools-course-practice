// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_

#include <string>

class MassUnit {
 public:
    MassUnit(double relative_coefficient, std::string qualifier);

    double get_relative_coefficient() const {
        return relative_coefficient;
    }

    std::string get_qualifier() const {
        return qualifier;
    }

    static const MassUnit Kilogram;
    static const MassUnit Gram;

    bool operator==(const MassUnit &other) const;

 private:
    double relative_coefficient;
    std::string qualifier;
};

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
