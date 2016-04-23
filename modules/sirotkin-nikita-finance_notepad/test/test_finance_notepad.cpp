// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/finance_notepad.h"

using std::string;

TEST(Sirotkin_Nikita_FinanceNotepadTest, unfit_number_dates_is_set_to_default) {
  // Arrange
  string number_great = date(32, months::JANUARY, 2001).toString();
  string expect = DEFAULT_DATE.toString();

  // Act

  // Assert
  EXPECT_EQ(expect.compare(number_great), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, great_year_dates_is_set_to_default) {
  // Arrange
  string year_great = date(1, months::JANUARY, 2101).toString();
  string expect = DEFAULT_DATE.toString();

  // Act

  // Assert
  EXPECT_EQ(expect.compare(year_great), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, less_year_dates_is_set_to_default) {
  // Arrange
  string year_less = date(1, months::JANUARY, 1999).toString();
  string expect = DEFAULT_DATE.toString();

  // Act

  // Assert
  EXPECT_EQ(expect.compare(year_less), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_true) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_TRUE(number_less < number_great);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_false) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_FALSE(number_less > number_great);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_months_can_compare_true) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_TRUE(month_great > month_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_months_can_compare_false) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_FALSE(month_great < month_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_year_can_compare_true) {
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_TRUE(year_great > year_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_year_can_compare_false){
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_FALSE(year_great < year_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, dates__can_compare_by_eq_true) {
  // Arrange
  date first = MIN_DATE;
  date second = MIN_DATE;

  // Act

  // Assert
  EXPECT_TRUE(first == second);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, dates__can_compare_by_eq_false) {
  // Arrange
  date first = MIN_DATE;
  date second = MAX_DATE;

  // Act

  // Assert
  EXPECT_FALSE(first == second);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, table_can_get_category_id) {
  // Arrange
  category_table table;
  std::string input("Food");
  int expect = 5;
  int result;

  // Act
  result = table.getIdOf(input);

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, table_can_get_category_name) {
  // Arrange
  category_table table;
  int input = 5;
  string expect = "Food";
  string result;

  // Act
  result = table.getNameOf(input);

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    table_can_get_default_category_by_wrong_id) {
  // Arrange
  category_table table;
  int input = table_size+1;
  string expect = "Other";
  string result;

  // Act
  result = table.getNameOf(input);

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    table_can_get_default_category_by_wrong_name) {
  // Arrange
  category_table table;
  string input = "Something";
  int expect = table_size-1;
  int result;

  // Act
  result = table.getIdOf(input);

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_category_id) {
  // Arrange
  category_table table;
  note debt(DEFAULT_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  int expect = table.getIdOf("Debt");
  int result;

  // Act
  result = debt.getCategoriesId();

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_category_name) {
  // Arrange
  category_table table;
  note debt(DEFAULT_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  string expect = "Debt";
  string result;

  // Act
  result = debt.getCategory();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_sum) {
  // Arrange
  category_table table;
  note debt(DEFAULT_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  float expect = 10.f;
  float result;

  // Act
  result = debt.getSum();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_date) {
  // Arrange
  category_table table;
  note debt(MAX_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  date expect = MAX_DATE;
  date result;

  // Act
  result = debt.getDate();

  // Assert
  EXPECT_TRUE(expect == result);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_comment) {
  // Arrange
  category_table table;
  note debt(MAX_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  string expect = "Something";
  string result;

  // Act
  result = debt.getComment();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_compare_less) {
  // Arrange
  category_table table;
  note max_note(MAX_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");
  note min_note(MAX_DATE, 10.f, table.getIdOf("Debt"), &table, "Something");

  // Act

  // Assert
  EXPECT_TRUE(min_note < max_note);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_pouch) {
  // Arrange
  notepad notes(13.f);
  float result;
  float expect = 13.f;

  // Act
  result = notes.getPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, pouch_is_sizeable) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = 20.f;

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = notes.getPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_get_sum_from_category) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = -50.f;

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), -30.f, "Food", "burger king");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.sumFromCategory("Food");

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_current_note) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016 -30 Debt For Noname";

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = (notes.getCurrentNote()).toString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_translate_notepad_to_string) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.toFormatedString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_navigte_by_notepad) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016 -30 Debt For Noname";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015),
                30.f, "Stipend", "day of VMK");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  ++notes;
  result = notes.getCurrentNote().toString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_sort_by_date) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.sortByDate();
  result = notes.toFormatedString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_potential_pouch) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = 30.f;

  // Act
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = notes.getPotentialPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_get_notes_from_category) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), 30.f, "Stipend", "day of VMK");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.notesFromCategoryToFormatedString("Debt");

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_group_by_category) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "1.12.2015\nSum: 30\nCategory: Food\n"
                       "Comment: burger king\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), 30.f, "Food", "burger king");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.formatedStringGroupedByCategories();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}
