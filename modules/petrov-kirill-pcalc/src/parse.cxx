// Copyright 2016 Petrov Kirill

#include "include/parse.h"

#include <../include/regex>
#include <string>

using std::regex;
using std::regex_iterator;

TPolynom Parse::polynom(const string &arg) {
  TPolynom polynom;
  string buf = arg;

  PTMonom pmonom;
  int index;
  tCoeff coeff;

  regex re_input("(([\\+-]|^)(\\d+)?(\\.\\d+)?x\\^\\dy\\^\\dz\\^\\d)+");
  regex re_coeff("(^|[-+])\\d+(\\.\\d+)?");
  regex re_index("\\^\\d");

  if (!regex_match(arg, re_input)) {
    throw string("Wrong polynoms format!");
  } else {
    polynom.pop_front();
    regex_iterator<string::iterator> it_index(buf.begin(), buf.end(), re_index);
    regex_iterator<string::iterator> it_coeff(buf.begin(), buf.end(), re_coeff);

    for (; it_coeff != regex_iterator<string::iterator>(); ++it_coeff) {
      coeff = atof(it_coeff->str().c_str());
      index = atoi(&it_index++->str()[1]) * 100 +
            atoi(&it_index++->str()[1]) * 10 +
          atoi(&it_index++->str()[1]);

      pmonom = new TMonom(coeff, index);
      polynom.push_back(*pmonom);
    }
    polynom.regulation();
  }
  return polynom;
}

TOperation Parse::operation(const string& arg) {
  TOperation operation;
  if (arg == "+")
    operation = ADDITION;
  else if (arg == "-")
    operation = SUBTRACTION;
  else if (arg == "compute")
    operation = COMPUTE;
  else if (arg == "sum_all")
    operation = SUMMARIZE_ALL;
  else
    throw string("No such operation!");
  return operation;
}

int Parse::number(const char* arg, const int lower, const int top) {
  char* end;
  int number = strtol(arg, &end, 10);
  if (*end) throw string("Wrong number!");
  else if (number < lower || number > top) throw string("Went abroad!");
  return number;
}

tCoeff Parse::value(const char* arg) {
  char* end;
  tCoeff value = strtod(arg, &end);
  if (*end) throw string("Incorrect value!");
  return value;
}
