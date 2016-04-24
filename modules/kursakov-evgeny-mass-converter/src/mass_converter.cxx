// Copyright 2016 Kursakov Evgeny

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/mass_converter.h"

MassConverter::MassConverter(std::vector<MassUnit> units) {
    this->units_ = std::vector<MassUnit>(units);

    auto last = std::unique(this->units_.begin(),
                            this->units_.end(),
                            [](const MassUnit &a, const MassUnit &b) {
                                return a.qualifier() == b.qualifier();
                            });

    if (last != this->units_.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void MassConverter::AddUnit(MassUnit new_unit) {
    for (auto &unit : units_) {
        if (unit.qualifier() == new_unit.qualifier())
            throw std::invalid_argument("unit is already added to converter");
    }

    units_.push_back(new_unit);
}

std::vector<MassUnit> MassConverter::units() const {
    return units_;
}

void MassConverter::ClearUnits() {
    units_.clear();
}

double MassConverter::Convert(MassUnit from,
                              MassUnit to,
                              double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    if (value == 0) return 0;

    double conversion_coefficient = from.coefficient() /
            to.coefficient();

    return value * conversion_coefficient;
}

std::string MassConverter::to_string(const MassUnit unit,
                                     double value,
                                     int precision) const {
    if (precision < 0)
        throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.qualifier();
    return stringStream.str();
}

std::pair<MassUnit, double>
MassConverter::ConvertFromString(std::string input) const {
    double value;
    std::string qualifier;

    std::istringstream inputStringStream(input);
    inputStringStream >> value;
    inputStringStream >> qualifier;

    if (!inputStringStream.eof() || qualifier.empty())
        throw std::invalid_argument("Invalid input");

    for (auto &unit : units_) {
        if (unit.qualifier() == qualifier)
            return std::pair<MassUnit, double>(unit, value);
    }

    throw std::logic_error("Unit not found");
}

double MassConverter::ConvertFromString(std::string input,
                                        MassUnit toUnit) const {
    std::pair<MassUnit, double> result = ConvertFromString(input);
    return Convert(result.first, toUnit, result.second);
}

