// Copyright 2016 Petrov Kirill

#include "tpolynom.h"


TPolynom::TPolynom(const tCoeff monoms[][2], const unsigned length) {
	PTMonom ptmonom = nullptr;
	for (unsigned i = 0; i < length; i++) {
		ptmonom = new TMonom( static_cast<int> ( monoms[i][0] ), monoms[i][1] );
		push_back(*ptmonom);
	}
	sort([](const TMonom& a, const TMonom& b) {return a > b; });
}

TPolynom::TPolynom(const TPolynom & tpolynom) {
	PTMonom ptmonom = nullptr;
	for (auto const monom: tpolynom) {
		ptmonom = monom.getCopyMonom();
		push_back(*ptmonom);
	}
}

TPolynom TPolynom::operator+(const TPolynom & tpolynom) const {
	const double nullMonom[][2] = { 0.0,0 };
	TPolynom result (nullMonom,1);
	PTMonom tmp;

	auto this_monom = this->begin();
	auto tpolynom_monom = tpolynom.begin();

	while ( this_monom != this->end() || tpolynom_monom !=tpolynom.end() ) {

		if ( this_monom == this->end() ) {
			tmp = tpolynom_monom->getCopyMonom();
			++tpolynom_monom;
		}
		else if ( tpolynom_monom == tpolynom.end() ) {
			tmp = this_monom->getCopyMonom();
			++this_monom;
		}
		else if ( *this_monom > *tpolynom_monom ) {
			tmp = this_monom->getCopyMonom();
			++this_monom;
		}
		else if ( *tpolynom_monom > *this_monom ) {
			tmp = tpolynom_monom->getCopyMonom();
			++tpolynom_monom;
		}
		else if ( this_monom->comparisonIndex(*tpolynom_monom) ) {
			tmp = (*this_monom + *tpolynom_monom ).getCopyMonom();
			++tpolynom_monom;
			++this_monom;
		}
		if (!tmp->equalsZero())
			result.push_back(*tmp);
	}
	if (result.size() != 1)
		result.pop_front();
	return result;
}

TPolynom TPolynom::operator-(const TPolynom & tpolynom) const {
	const double nullMonom[][2] = { 0.0,0 };
	TPolynom result(nullMonom, 1);
	PTMonom tmp;

	auto this_monom = this->begin();
	auto tpolynom_monom = tpolynom.begin();

	while (this_monom != this->end() || tpolynom_monom != tpolynom.end()) {

		if (this_monom == this->end()) {
			tmp = tpolynom_monom->getCopyMonom()->comparisionBack();
			++tpolynom_monom;
		}
		else if (tpolynom_monom == tpolynom.end()) {
			tmp = this_monom->getCopyMonom();
			++this_monom;
		}
		else if (*this_monom > *tpolynom_monom) {
			tmp = this_monom->getCopyMonom();
			++this_monom;
		}
		else if (*tpolynom_monom > *this_monom) {
			tmp = tpolynom_monom->getCopyMonom()->comparisionBack();
			++tpolynom_monom;
		}
		else if (this_monom->comparisonIndex(*tpolynom_monom)) {
			tmp = (*this_monom - *tpolynom_monom).getCopyMonom();
			++tpolynom_monom;
			++this_monom;
		}
		if (!tmp->equalsZero())
			result.push_back(*tmp);
	}
	if (result.size() != 1)
		result.pop_front();
	return result;
}
