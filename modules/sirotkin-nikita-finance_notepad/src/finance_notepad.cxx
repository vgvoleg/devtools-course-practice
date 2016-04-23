// Copyright 2016 Sirotkin_Nikita

#include <sstream>
#include "include/finance_notepad.h"

using namespace std;

#define WRONG_DATE date(1, months::JANUARY, 2000)

template <class TYPE>
string to_string(TYPE value) {
  ostringstream oss;
  oss << value;
  return oss.str();
}

//date
date::date(char _number, months _month, int _year) {
  if (_number > 31 || _year < 2000 || _year > 2100)
    *this = WRONG_DATE;
  else	{
    number = _number;
    month = _month;
    year = _year;
  }
}

string date::toString() const {
  string result;
  result = to_string<int>(number) + "." + to_string<int>(int(month) + 1) +
           "." + to_string<int>(year);
  return result;
}

bool date::operator>(date other_date) const {
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

bool date::operator<(date other_date) const {
  return !((*this) > other_date);
}

//category_table
category_table::category_table() {
  table[0] = "Debt";
  table[1] = "Stipend";
  table[2] = "Salary";
  table[3] = "Gift";
  table[4] = "Transport";
  table[5] = "Food";
  table[6] = "Entertainment";
  table[7] = "Taxes";
  table[8] = "Other";
}

int category_table::getIdOf(string name) {
  for (int i = 0; i < 8; ++i)
    if (name == table[i])
      return i;
  return 8;
}

string category_table::getNameOf(int id) {
  return table[id];
}

//note
note::note(date _notes_date, float _sum, int _categories_id,
           category_table *_table_of_categories, string _comment) :
  notes_date(_notes_date), sum(_sum), categories_id(_categories_id),
  table(_table_of_categories), comment(_comment) {

}

int note::getCategoriesId() {
  return categories_id;
}

float note::getSum() {
  return sum;
}

string note::toString() const {
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

//notepad
notepad::notepad(float _pouch): pouch(_pouch) {
}
void notepad::addNote(date _notes_date, float _sum, string _categoriy,
                      string _comment) {
  notes.addElement(note(_notes_date, _sum,
                        table_of_categories.getIdOf(_categoriy), &table_of_categories, _comment));
  pouch += _sum;
}

float notepad::getPouch() const {
  return pouch;
}

float notepad::getPotentialPouch() {
  float result = pouch - sumFromCategory("Debt");
  return result;
}

string notepad::notesFromCategoryToString(string category) {
  string result;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag)
  {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().toString();
    flag = ++notes;
  }
  return result;
}

float notepad::sumFromCategory(string category) {
  float result = 0.f;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag)
  {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().getSum();
    flag = ++notes;
  }
  return result;
}

string notepad::toString() {
  string result;
  notes.reset();
  bool flag = !(notes.isEmpty());
  while (flag)
  {
    result += notes.getValue().toString();
    flag = ++notes;
  }
  return result;
}

string notepad::stringGroupedByCategories() {
  string result;
  bool flag;
  for (int category_id = 0; category_id < 9; ++category_id)
  {
    notes.reset();
    flag = !(notes.isEmpty());
    while (flag)
    {
      if (notes.getValue().getCategoriesId() == category_id)
        result += notes.getValue().toString();
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

note notepad::getCurrentNote() {
  return notes.getValue();
}
