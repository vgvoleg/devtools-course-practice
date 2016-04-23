// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_CATEGORY_TABLE_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_CATEGORY_TABLE_H_

#include <string>

using std::string;

#define table_size 9
class category_table {
 public:
  category_table();
  ~category_table();
  int getIdOf(string name) const;
  string getNameOf(int id) const;
 private:
  string *table;
};

#endif  // MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_CATEGORY_TABLE_H_
