// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_PCALC_INCLUDE_PARSE_H_
#define MODULES_PETROV_KIRILL_PCALC_INCLUDE_PARSE_H_

#include "include/tpolynom.h"

#include <string>

using std::string;

enum TOperation { ADDITION, SUBTRACTION, COMPUTE, SUMMARIZE_ALL };

class Parse {
public:
  static int number (const char* arg, const int lower, const int top);
  static tCoeff value (const char* arg);
  static TPolynom polynom (const string& arg);
  static TOperation operation (const string& arg);
};

#endif  // MODULES_PETROV_KIRILL_PCALC_INCLUDE_PARSE_H_