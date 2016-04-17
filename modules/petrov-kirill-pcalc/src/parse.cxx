// Copyright 2016 Petrov Kirill

#include "include/parse.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

TPolynom Parse::polynom(const string &arg) {
  TPolynom polynom;

  string str = "";

  int index;
  tCoeff coeff;
  PTMonom pmonom;

  string monom;
  vector<string> monoms;

  string buf;
  const string delim_string("+-");

  string::size_type beg_idx = 0;
  string::size_type end_idx = 0;

  if (arg[0] !='-' && isdigit(arg[0]))
    str+="+";
  str += arg;
  if (arg.find_first_of(delim_string, end_idx) == string::npos) {
    monoms.push_back(arg);
  } else {
    while (string::npos != (beg_idx =
         str.find_first_not_of(delim_string, end_idx))) {
      monom = str[str.find_first_of(delim_string, end_idx)];
      if (string::npos == (end_idx = str.find_first_of(delim_string, beg_idx)))
        monom += str.substr(beg_idx);
      else
        monom += str.substr(beg_idx, end_idx - beg_idx);
      monoms.push_back(monom);
    }
  }
  try {
    string::size_type pos = 0;
    for (auto mon : monoms) {
      pos = mon.find("x^");
      buf = mon.substr(0, pos);

      coeff = Parse::value(buf.c_str());

      index = Parse::number(mon[pos + 2]) * 100;

      pos = mon.find("y^");
      index += Parse::number(mon[pos + 2]) * 10;

      pos = mon.find("z^");
      index += Parse::number(mon[pos + 2]) * 1;

      pmonom = new TMonom(coeff, index);
      polynom.push_back(*pmonom);
    }
  }
  catch (string) {
    throw string("Wrong polynoms format!");
  }
  polynom.regulation();
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
  char* end = 0;
  int number = strtol(arg, &end, 10);
  if (!end || *end != 0) throw string("Wrong number!");
  else if (number < lower || number > top) throw string("Went abroad!");
  return number;
}

int Parse::number(const char arg) {
  int number = -1;
  if (!isdigit(arg)) throw string("Wrong number!");
  else
    number = arg - '0';
  return number;
}

tCoeff Parse::value(const char* arg) {
  char* end;
  tCoeff value = strtod(arg, &end);
  if (*end) throw string("Incorrect value!");
  return value;
}
