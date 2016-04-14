// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_
#define MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_

typedef double tCoeff;

class TMonom {
public:
	TMonom(int coeff = 1, int index = 0);
	tCoeff  getCoeff	(void);
	int		getIndex	(void);
	TMonom& operator=	(const TMonom &tmonom);
	bool	operator==	(const TMonom &tmonom) const;
	bool	operator!=	(const TMonom &tmonom) const;
	bool	operator<   (const TMonom &tmonom) const;

	friend class TPolinom;
private:
	tCoeff coeff_;						// коэффициент монома
	tCoeff index_;						// индекс (свертка степеней)
};
typedef TMonom *PTMonom;

#endif // MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_