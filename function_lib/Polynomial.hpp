#pragma once

#include "Monomial.hpp"

class Polynomial : public SList<MonomialData>
{
public:
	Polynomial();
	Polynomial(const Polynomial& other);
	~Polynomial();

	//Polynomial& operator = (const Monomial*& arr);
	Polynomial& operator += (const Monomial& other);
	Polynomial operator * (const Polynomial& other);
	Polynomial operator + (const Polynomial& other);
	Polynomial operator - (const Polynomial& other);

	friend ostream& operator << (ostream& ostr, const Polynomial& p);
};
