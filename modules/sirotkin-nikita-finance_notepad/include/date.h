// Copyright 2016 Sirotkin_Nikita

#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_DATE_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_DATE_H_

#include <string>

using std::string;

enum class months {
  JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
  AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class date {
 private:
  char number;
  months month;
  int year;
 public:
  date();
  date(char _number, months _month, int _year);
  string toString() const;
  bool operator>(const date &other_date) const;
  bool operator<(const date &other_date) const;
  bool operator==(const date &other_date) const;
};

#define MIN_YEAR 2000
#define MAX_YEAR 2100
#define MIN_DATE date(1, months::JANUARY, MIN_YEAR)
#define MAX_DATE date(31, months::DECEMBER, MAX_YEAR)
#define DEFAULT_DATE MIN_DATE

#endif  // MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_DATE_H_
