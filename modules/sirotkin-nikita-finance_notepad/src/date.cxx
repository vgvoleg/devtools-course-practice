// Copyright 2016 Sirotkin_Nikita

#include <sstream>
#include <string>
#include "include/date.h"

using std::string;
using std::ostringstream;

template <class TYPE>
string to_string(TYPE value) {
  ostringstream oss;
  oss << value;
  return oss.str();
}

date::date() {
  this->number = 1;
  this->month = months::JANUARY;
  this->year = MIN_YEAR;
}

date::date(char number, months month, int year) {
  if (number > 31 || number < 0 || year < MIN_YEAR || year > MAX_YEAR) {
    this->number = 1;
    this->month = months::JANUARY;
    this->year = MIN_YEAR;
  } else {
    this->number = number;
    this->month = month;
    this->year = year;
  }
}

string date::toString() const {
  string result;
  result = to_string<int>(number) + "." +
          to_string<int>(static_cast<int>(month)) +
           "." + to_string<int>(year);
  return result;
}

bool date::operator>(const date &other_date) const {
  if (year > other_date.year)
    return true;
  else if (year < other_date.year)
    return false;
  else if (month > other_date.month)
    return true;
  else if (month < other_date.month)
    return false;
  else if (number > other_date.number)
    return true;
  else
    return false;
}

bool date::operator<(const date &other_date) const {
  return (other_date > (*this));
}

bool date::operator==(const date &other_date) const {
  return (number == other_date.number) &&
    (month == other_date.month) &&
    (year == other_date.year);
}
