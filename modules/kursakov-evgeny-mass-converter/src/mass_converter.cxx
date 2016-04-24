// Copyright 2016 Kursakov Evgeny

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>
#include <regex>

#include "include/mass_converter.h"

MassConverter::MassConverter(std::vector<MassUnit> units) {
    this->units = std::vector<MassUnit>(units);

    auto last = std::unique(this->units.begin(),
                            this->units.end(),
                            [](const MassUnit &a, const MassUnit &b) {
                                return a.get_qualifier() == b.get_qualifier();
                            });

    if (last != this->units.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void MassConverter::addUnit(MassUnit new_unit) {
    for (auto &unit : units) {
        if (unit.get_qualifier() == new_unit.get_qualifier())
            throw std::invalid_argument("unit is already added to converter");
    }

    units.push_back(new_unit);
}

std::vector<MassUnit> MassConverter::getUnits() const {
    return units;
}

void MassConverter::clearUnits() {
    units.clear();
}

double MassConverter::convert(const MassUnit from,
                              const MassUnit to,
                              double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    if (value == 0) return 0;

    double conversion_coefficient = from.get_coefficient() /
                                    to.get_coefficient();

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
    stringStream << unit.get_qualifier();
    return stringStream.str();
}

std::pair<MassUnit, double>
MassConverter::from_string(const std::string input) const {
    if (!MassConverter::check_input(input))
        throw std::invalid_argument("invalid input");

    double value;
    std::string qualifier;

    std::istringstream inputStringStream(input);
    inputStringStream >> value;
    inputStringStream >> qualifier;

    for (auto &unit : units) {
        if (unit.get_qualifier() == qualifier)
            return std::pair<MassUnit, double>(unit, value);
    }

    throw std::logic_error("Unit not found");
}

bool MassConverter::check_input(std::string input) {
    std::regex check_input_regex("^\\d+(.\\d+)? \\w+$");

    bool valid = std::regex_search(input, check_input_regex);

    return valid;
}

double MassConverter::from_string(const std::string input,
                                  const MassUnit toUnit) const {
    std::pair<MassUnit, double> result = from_string(input);
    return convert(result.first, toUnit, result.second);
}

