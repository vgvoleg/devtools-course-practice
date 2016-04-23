// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_

#include <string>

class MassUnit {

 public:
    MassUnit() { }

    virtual ~MassUnit() { }

    virtual double get_relative_coefficient() = 0;

    virtual std::string get_qualifier() = 0;

    class Kilogram;
    class Gram;
};

class MassUnit::Kilogram : public MassUnit {
 public:
    virtual double get_relative_coefficient() override {
        return 1;
    }

    virtual std::string get_qualifier() override {
        return "kg";
    }
};

class MassUnit::Gram : public MassUnit {
 public:
    virtual double get_relative_coefficient() override {
        return 0.001;
    }

    virtual std::string get_qualifier() override {
        return "g";
    }
};

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_UNIT_H_
