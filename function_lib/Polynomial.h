#pragma once

#include "Monomial.h"

class Polynomial : public SList<MonomialData>
{
public:
	Polynomial();
	Polynomial(const Polynomial& other);
	~Polynomial();

	//template <typename T, size_t N>
	//Polynomial& operator = (T(&a)[N]);
	
	Polynomial& operator += (const Monomial& other);
	Polynomial operator * (const Polynomial& other);
	Polynomial operator + (const Polynomial& other);
	Polynomial operator - (const Polynomial& other);

	friend ostream& operator << (ostream& ostr, const Polynomial& p);
};

//template <typename T, size_t N>
//Polynomial& Polynomial::operator=(T(&a)[N])
//{
//	if (this->head != nullptr)
//		clear();
//
//	Size = 0;
//	head = nullptr;
//	Iterator k = a.begin_const();
//	while (k.CanMove())
//	{
//		push_back(*k);
//		k++;
//	}
//
//	return *this;
//};