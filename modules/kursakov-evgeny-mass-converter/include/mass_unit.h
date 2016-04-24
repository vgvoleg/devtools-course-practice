// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_

#include <string>
#include <vector>

class MassUnit {
 public:
    MassUnit(double coefficient, std::string qualifier);

    MassUnit(const MassUnit &other)
        : coefficient_(other.coefficient()),
          qualifier_(other.qualifier()) { }

    MassUnit &operator=(const MassUnit &other);

    double coefficient() const {
        return coefficient_;
    }

    std::string qualifier() const {
        return qualifier_;
    }

    bool operator==(const MassUnit &other) const;

    bool operator!=(const MassUnit &other) const;

 private:
    double coefficient_;
    std::string qualifier_;
};

extern const MassUnit kMassUnitKilogram;
extern const MassUnit kMassUnitGram;

extern const std::vector<MassUnit> kDefaultMassUnits;

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
