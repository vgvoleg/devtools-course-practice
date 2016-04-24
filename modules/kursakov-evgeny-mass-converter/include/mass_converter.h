// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

#include <vector>
#include <string>
#include <utility>

#include "include/mass_unit.h"

class MassConverter {
 public:
    explicit MassConverter(std::vector<MassUnit> units = kDefaultMassUnits);

    void addUnit(MassUnit unit);

    std::vector<MassUnit> getUnits() const;

    void clearUnits();

    double convert(MassUnit from, MassUnit to, double value) const;

    std::string to_string(MassUnit unit,
                          double value,
                          int precision = 2) const;

    double from_string(std::string input, MassUnit toUnit) const;

 private:
    std::vector<MassUnit> units;

    std::pair<MassUnit, double> from_string(std::string input) const;
    static bool check_input(std::string input);
};

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
