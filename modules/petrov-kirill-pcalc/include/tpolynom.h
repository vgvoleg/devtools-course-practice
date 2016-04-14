// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_
#define MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_

#include "tmonom.h"
#include <iostream>
#include <list>

using std::list;

enum Variable { x = 1, y = 10, z = 100 };

class TPolinom : public list <TMonom> {
public:
	TPolinom(tCoeff monoms[][2] = nullptr, int length = 0);		// конструктор полинома из массива «коэффициент-индекс»
	TPolinom(TPolinom &tpolinom);								// конструктор копирования

	TPolinom	operator+	 (TPolinom &tpolinom);				// сложение полиномов
	TPolinom	operator-	 (TPolinom &tpolinom);				// сложение полиномов
	TPolinom&	operator=	 (TPolinom &tpolinom);				// присваивание
	bool		operator==	 (TPolinom &tpolinom);				// сравнение полиномов

	TPolinom computeDerivative(Variable variable = x);			// нахождение производной
};

#endif // MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TPOLYNOM_H_