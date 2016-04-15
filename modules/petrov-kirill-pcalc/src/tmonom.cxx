// Copyright 2016 Petrov Kirill

#include "tmonom.h"
#include <limits>

double eps = std::numeric_limits<double>::epsilon();

TMonom::TMonom(tCoeff coeff, int index): coeff_(coeff), index_(index) {};



TMonom& TMonom::operator=(const TMonom &tmonom) {
	coeff_ = tmonom.coeff_;
	index_ = tmonom.index_;
	return *this;
}

bool TMonom::comparisonIndex(const TMonom &tmonom) const{
	return index_ == tmonom.index_;
}

bool TMonom::operator==(const TMonom &tmonom) const {
	bool equalityCoeff = abs(coeff_ - tmonom.coeff_) < eps;
	return (index_ == tmonom.index_) && equalityCoeff;
}

bool TMonom::operator!=(const TMonom &tmonom) const {
	return !operator==(tmonom);
}

bool TMonom::operator<(const TMonom &tmonom) const {
	return index_ < tmonom.index_;
}

bool TMonom::operator>(const TMonom & tmonom) const {
	return index_ > tmonom.index_;
}

TMonom TMonom::operator+(const TMonom & tmonom) const {
	return TMonom(coeff_ + tmonom.coeff_, index_);
}

TMonom TMonom::operator-(const TMonom & tmonom) const {
	return TMonom(coeff_ - tmonom.coeff_, index_);
}

PTMonom TMonom::comparisionBack(void)
{
	coeff_ = -coeff_;
	return this;
}

PTMonom TMonom::getCopyMonom(void) const {
	return new TMonom(coeff_, index_);
}

bool TMonom::equalsZero(void) const {
	return abs(coeff_) < eps;
}