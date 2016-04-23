// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/date.h"

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
    dates_with_dif_year_can_compare_false) {
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
