// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_FORMATTER_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_FORMATTER_H_

#include <string>

#include "include/mass_unit.h"

template<typename Unit>
class MassFormatter {
 public:
    MassFormatter() {
        unit = new Unit();
    }

    virtual ~MassFormatter() {
        delete unit;
    }

    std::string format(double value, int precision = 2);
    //std::string parse(double value, int precision = 2);

 private:
    MassUnit *unit;
};

template<typename Unit>
std::string MassFormatter<Unit>::format(double value, int precision) {
    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit->get_qualifier();
    return stringStream.str();
}

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_FORMATTER_H_
