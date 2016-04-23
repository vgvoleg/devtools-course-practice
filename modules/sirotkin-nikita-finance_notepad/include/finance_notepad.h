// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_

#include <string>
#include "./list.hpp"

enum class months {
  JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
  AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class date {
 private:
  char number;
  months month;
  int year;
 public:
  date(char _number, months _month, int _year);
  std::string toString() const;
  bool operator>(date other_date) const;
  bool operator<(date other_date) const;
};

class category_table {
 private:
  std::string table[9];
 public:
  category_table();
  int getIdOf(std::string name);
  std::string getNameOf(int id);
};

class note {
 private:
  date notes_date;
  float sum;
  int categories_id;
  std::string comment;
  category_table *table;
 public:
  note(date _notes_date, float _sum, int _categories_id,
       category_table *_table_of_categories, std::string _comment = "");
  int getCategoriesId();
  float getSum();
  std::string toString() const;
  bool operator>(const note &right) const;
  bool operator<(const note &right) const;
};

class notepad {
 private:
  lite_list<note> notes;
  category_table table_of_categories;
  float pouch;
 public:
  explicit notepad(float _pouch);
  void addNote(date _notes_date, float _sum, std::string _category,
               std::string _comment = "");
  float getPouch() const;
  float getPotentialPouch();
  std::string notesFromCategoryToString(std::string category);
  float sumFromCategory(std::string category);
  std::string toString();
  std::string stringGroupedByCategories();
  void sortByDate();
  bool operator++();
  note getCurrentNote();
};

#endif  // MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
