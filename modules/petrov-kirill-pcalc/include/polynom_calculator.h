// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_
#define MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_

#include "include/tpolynom.h"
#include "include/parse.h"

#include <string>

using std::string;

class PolynomCalculator {
public:
  PolynomCalculator();
  string operator()(int argc, const char** argv);

private:
  void help(const char* appname);

  static const int MINPOLYNOMS = 1;
  static const int MAXPOLYNOMS = 10;
  static const int NUMBERVARIABLES = 3;

  string message_;

  typedef struct {
    int        numberPoly;
    TPolynom   poly[MAXPOLYNOMS];
    TOperation operation;
    tCoeff     Point[NUMBERVARIABLES];
    int        idPoly[2];
  } Arguments;
};

#endif  // MODULES_PETROV_KIRILL_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_