// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_

#include <string>
#include "./list.hpp"

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
};

#define MIN_YEAR 2000
#define MAX_YEAR 2100
#define MIN_DATE date(1, months::JANUARY, MIN_YEAR)
#define MAX_DATE date(31, months::DECEMBER, MAX_YEAR)
#define DEFAULT_DATE MIN_DATE

#define table_size 9
class category_table {
 private:
  string *table;
 public:
  category_table();
  ~category_table();
  int getIdOf(string name) const;
  string getNameOf(int id) const;
};

class note {
 private:
  date notes_date;
  float sum;
  int categories_id;
  string comment;
  category_table *table;
 public:
  note(date notes_date, float sum, int categories_id,
       category_table *table_of_categories, string comment = "");
  int getCategoriesId() const;
  float getSum() const;
  date getDate() const;
  string getComment() const;
  string getCategory() const;
  string toString() const;
  string toFormatedString() const;
  bool operator>(const note &right) const;
  bool operator<(const note &right) const;
};

class notepad {
 private:
  lite_list<note> notes;
  category_table table_of_categories;
  float pouch;
 public:
  explicit notepad(float pouch);
  void addNote(date notes_date, float sum, string category,
               string comment = "");
  float getPouch() const;
  float getPotentialPouch();
  string notesFromCategoryToFormatedString(string category);
  float sumFromCategory(string category);
  string toFormatedString();
  string formatedStringGroupedByCategories();
  void sortByDate();
  bool operator++();
  note getCurrentNote() const;
};

#endif  // MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
