// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_
#define MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_

class TMonom;
typedef double tCoeff;
typedef TMonom* PTMonom;

class TMonom {
public:
	TMonom(tCoeff coeff = 0.0, int index = 0);


	bool comparisonIndex	(const TMonom &tmonom) const;
	TMonom& operator=		(const TMonom &tmonom);
	bool	operator==		(const TMonom &tmonom) const;
	bool	operator!=		(const TMonom &tmonom) const;
	bool	operator<		(const TMonom &tmonom) const;
	bool	operator>		(const TMonom &tmonom) const;
	TMonom	operator+		(const TMonom &tmonom) const;
	TMonom	operator-		(const TMonom &tmonom) const;
	PTMonom comparisionBack	(void);


	bool equalsZero(void) const;
	PTMonom getCopyMonom	(void) const;
	
private:
	tCoeff coeff_;						// коэффициент монома
	int index_;							// индекс (свертка степеней)				
};


#endif // MODULES_PETROV_KIRILL_ZCALC_INCLUDE_TMONOM_H_