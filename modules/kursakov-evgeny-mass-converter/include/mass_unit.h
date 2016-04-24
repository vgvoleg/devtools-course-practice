// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_

#include <string>
#include <vector>

class MassUnit {
 public:
    MassUnit(double coefficient, std::string qualifier);

    MassUnit(const MassUnit &other)
            : coefficient(other.get_coefficient()),
              qualifier(other.get_qualifier()) { }

    MassUnit &operator=(const MassUnit &other);

    double get_coefficient() const {
        return coefficient;
    }

    std::string get_qualifier() const {
        return qualifier;
    }

    bool operator==(const MassUnit &other) const;

    bool operator!=(const MassUnit &other) const;

 private:
    double coefficient;
    std::string qualifier;
};

extern const MassUnit kMassUnitKilogram;
extern const MassUnit kMassUnitGram;

extern const std::vector<MassUnit> kDefaultMassUnits;

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
