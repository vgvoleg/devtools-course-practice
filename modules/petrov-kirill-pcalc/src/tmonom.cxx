// Copyright 2016 Petrov Kirill

#include "tmonom.h"

TMonom::TMonom(int coeff = 1, int index = 0): coeff_(coeff), index_(index) {};

tCoeff TMonom::getCoeff(void) { 
	return coeff_; 
}

int  TMonom::getIndex(void) {
	return index_;
}

TMonom& TMonom::operator=(const TMonom &tmonom) {
	coeff_ = tmonom.coeff_;
	index_ = tmonom.index_;
	return *this;
}

bool TMonom::operator==(const TMonom &tmonom) const {
	return (coeff_ == tmonom.coeff_) && (index_ == tmonom.index_);
}

bool TMonom::operator!=(const TMonom &tmonom) const {
	return (coeff_ != tmonom.coeff_) || (index_ != tmonom.index_);
}

bool TMonom::operator<(const TMonom &tmonom) const {
	return index_ < tmonom.index_;
}