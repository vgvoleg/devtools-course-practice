// Copyright 2016 Petrov Kirill

#include "include/tpolynom.h"

#include <algorithm>
#include <iterator>
#include <string>

TPolynom::TPolynom() {
  PTMonom nullMonom = new TMonom(0.0, 0);
  push_back(*nullMonom);
}

TPolynom::TPolynom(const tCoeff monoms[][2], const int length) {
  PTMonom ptmonom = nullptr;
  for (int i = 0; i < length; i++) {
    ptmonom = new TMonom(monoms[i][0], static_cast<int> (monoms[i][1]));
    push_back(*ptmonom);
  }
  regulation();
}

TPolynom::TPolynom(const TPolynom& polynom) {
  PTMonom ptmonom = nullptr;
  for (auto const monom : polynom) {
    ptmonom = monom.getCopyMonom();
    push_back(*ptmonom);
  }
}

TPolynom TPolynom::operator+(const TPolynom& polynom) const {
  TPolynom result;
  std::merge(polynom.begin(), polynom.end(), begin(), end(),
  back_inserter(result) );
  result.regulation();

  return result;
}

TPolynom TPolynom::operator-(const TPolynom& polynom) const {
  TPolynom back = polynom;
  for_each(back.begin(), back.end(), [](TMonom& monom)
  { monom.comparisionBack();});
  return operator+(back);
}

tCoeff TPolynom::operator()(const tCoeff x, const tCoeff y,
                            const tCoeff z) const {
  tCoeff sum = 0.0;
  for_each(begin(), end(), [&sum, x, y, z](const TMonom& monom) {
    sum += monom.comparisionValue(x, y, z);
  });
  return sum;
}

void TPolynom::regulation(void) {
  sort();
  for (auto i = next(begin()); i != end(); ++i)
    if (i->comparisonIndex(*prev(i))) {
      *prev(i) = *prev(i) + *i;
      i = prev(erase(i));
    }
  remove_if([](const TMonom mon) { return mon.equalsZero(); });
  if (empty())
    push_back(*new TMonom(0.0, 0));
}

std::ostream& operator<<(std::ostream& os, const TPolynom& polynom) {
  os << polynom.front();
  for_each(next(polynom.begin()), polynom.end(), [&os](const TMonom& monom) {
    os << (monom.isPositiveCoeff() ? "+" : "") << monom;
  });
  return os;
}

