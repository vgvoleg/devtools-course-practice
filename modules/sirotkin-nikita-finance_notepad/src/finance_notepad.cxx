// Copyright 2016 Sirotkin_Nikita

#include <sstream>
#include <string>
#include "include/finance_notepad.h"

using std::string;
using std::ostringstream;

template <class TYPE>
string to_string(TYPE value) {
  ostringstream oss;
  oss << value;
  return oss.str();
}

// date
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
  return !((*this) > other_date);
}

// category_table
category_table::category_table() {
  table = new string[table_size];
  table[0] = "Debt";
  table[1] = "Stipend";
  table[2] = "Salary";
  table[3] = "Gift";
  table[4] = "Transport";
  table[5] = "Food";
  table[6] = "Entertainment";
  table[7] = "Taxes";
  table[table_size-1] = "Other";
}

category_table::~category_table() {
  delete[] table;
}

int category_table::getIdOf(string name) const {
  for (int i = 0; i < table_size; ++i)
    if (name == table[i])
      return i;
  return table_size-1;
}

string category_table::getNameOf(int id) const {
  if (id >= 0 && id < table_size) {
    return table[id];
  } else {
     return table[table_size-1];
  }
}

// note
note::note(date notes_date, float sum, int categories_id,
           category_table *table_of_categories, string comment) {
  this->notes_date = notes_date;
  this->sum = sum;
  this->categories_id = categories_id;
  this->table = table_of_categories;
  this->comment = comment;
}

int note::getCategoriesId() const {
  return categories_id;
}

float note::getSum() const {
  return sum;
}

date note::getDate() const {
  return notes_date;
}

string note::getComment() const {
  return comment;
}

string note::getCategory() const {
  return table->getNameOf(categories_id);
}

string note::toString() const {
  string result;
  result = notes_date.toString() + " " + to_string<float>(sum)
    + " " + table->getNameOf(categories_id) + " " + comment;
  return result;
}
string note::toFormatedString() const {
  string result;
  result = notes_date.toString() + "\nSum: " + to_string<float>(sum)
           + "\nCategory: " + table->getNameOf(categories_id)
           + "\nComment: " + comment +  "\n___________\n";
  return result;
}

bool note::operator>(const note &right) const {
  return (notes_date > right.notes_date);
}

bool note::operator<(const note &right) const {
  return (notes_date < right.notes_date);
}

// notepad
notepad::notepad(float pouch) {
  this->pouch = pouch;
}
void notepad::addNote(date notes_date, float sum, string categoriy,
                      string comment) {
  notes.addElement(note(notes_date, sum,
                        table_of_categories.getIdOf(categoriy),
                        &table_of_categories, comment));
  pouch += sum;
}

float notepad::getPouch() const {
  return pouch;
}

float notepad::getPotentialPouch() {
  return pouch - sumFromCategory("Debt");
}

string notepad::notesFromCategoryToFormatedString(string category) {
  string result;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag) {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().toFormatedString();
    flag = ++notes;
  }
  return result;
}

float notepad::sumFromCategory(string category) {
  float result = 0.f;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag) {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().getSum();
    flag = ++notes;
  }
  return result;
}

string notepad::toFormatedString() {
  string result;
  notes.reset();
  bool flag = !(notes.isEmpty());
  while (flag) {
    result += notes.getValue().toFormatedString();
    flag = ++notes;
  }
  return result;
}

string notepad::formatedStringGroupedByCategories() {
  string result;
  bool flag;
  for (int category_id = 0; category_id < 9; ++category_id) {
    notes.reset();
    flag = !(notes.isEmpty());
    while (flag) {
      if (notes.getValue().getCategoriesId() == category_id)
        result += notes.getValue().toFormatedString();
      flag = ++notes;
    }
  }
  return result;
}

void notepad::sortByDate() {
  notes.sort();
}

bool notepad::operator++() {
  return ++notes;
}

note notepad::getCurrentNote() const {
  return notes.getValue();
}
