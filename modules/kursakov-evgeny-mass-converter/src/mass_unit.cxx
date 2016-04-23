// Copyright 2016 Kursakov Evgeny

#include <string>

#include "include/mass_unit.h"

const MassUnit MassUnit::Kilogram = MassUnit(1, "kg");
const MassUnit MassUnit::Gram = MassUnit(0.001, "g");

MassUnit::MassUnit(double relative_coefficient, std::string qualifier)
        : relative_coefficient(relative_coefficient), qualifier(qualifier) {
    if (relative_coefficient <= 0)
        throw std::invalid_argument("relative_coefficient must be positive");

    if (qualifier.empty())
        throw std::invalid_argument("qualifier must not be empty");
}

bool MassUnit::operator==(const MassUnit &other) const {
    return this->get_qualifier() == other.get_qualifier() &&
           this->get_relative_coefficient() == other.get_relative_coefficient();
}
