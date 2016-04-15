// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_
#define MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_

#include "tmonom.h"
#include <iostream>
#include <list>

using std::list;

enum Variable { x = 1, y = 10, z = 100 };

class TPolynom : public list <TMonom> {
public:
	TPolynom (const tCoeff monoms[][2], const unsigned length);	// конструктор полинома из массива «коэффициент-индекс»
	TPolynom (const TPolynom &tpolynom);								// конструктор копирования

	TPolynom	operator+	 (const TPolynom &tpolynom) const;				// сложение полиномов
	TPolynom	operator-	 (const TPolynom &tpolynom) const;				// сложение полиномов

	TPolynom computeDerivative(Variable variable = x);			// нахождение производной
};

#endif // MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_