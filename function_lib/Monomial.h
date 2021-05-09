#pragma once
#include "SList.h"
#include "MonomialData.h"
#include <initializer_list>


class Monomial : public Node<MonomialData>
{
protected:

public:
	Monomial();
	Monomial(double mul, int size, double* x);
	Monomial(double mul, std::initializer_list<double> x);
	Monomial(const Monomial& other);
	~Monomial();

	double GetMul();
	void SetMul(double mul);
	int GetDim();
	void SetDim(int dim);

	double& operator [] (int i);
	MonomialData& operator * ();

	Monomial& operator = (const Monomial& other);

	Monomial* operator + (const Monomial& other);
	Monomial* operator - (const Monomial& other);
	Monomial operator * (const Monomial& other);
	Monomial operator / (const Monomial& other);

	bool operator > (const Monomial& other);
	bool operator < (const Monomial& other);
	bool operator == (const Monomial& other);

	friend ostream& operator << (ostream& ostr, const Monomial& m);
	friend istream& operator >> (istream& ostr, Monomial& m);
};