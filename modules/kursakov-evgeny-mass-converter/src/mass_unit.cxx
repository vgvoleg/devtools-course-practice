// Copyright 2016 Kursakov Evgeny

#include <stdexcept>
#include <string>
#include <vector>

#include "include/mass_unit.h"

const MassUnit kMassUnitGram = MassUnit(0.001, "g");
const MassUnit kMassUnitKilogram = MassUnit(1, "kg");
const MassUnit kMassUnitTon = MassUnit(1000, "t");

const std::vector<MassUnit> kDefaultMassUnits = {
        kMassUnitGram,
        kMassUnitKilogram,
        kMassUnitTon
};


MassUnit::MassUnit(double coefficient, std::string qualifier)
        : coefficient_(coefficient), qualifier_(qualifier) {
    if (coefficient <= 0)
        throw std::invalid_argument("coefficient must be positive");

    if (qualifier.empty())
        throw std::invalid_argument("qualifier must not be empty");
}

MassUnit &MassUnit::operator=(const MassUnit &z) {
    coefficient_ = z.coefficient();
    qualifier_ = z.qualifier();

    return *this;
}

bool MassUnit::operator==(const MassUnit &other) const {
    return this->qualifier() == other.qualifier() &&
            this->coefficient() == other.coefficient();
}

bool MassUnit::operator!=(const MassUnit &other) const {
    return !(*this == other);
}
