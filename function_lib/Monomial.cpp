#include "Monomial.h"
#include <iostream>

Monomial::Monomial()
{
	data.M = 0;
	data.dim = 0;
	data.data = nullptr;
}

Monomial::Monomial(double mul, int size, double* x)
{
	data.M = mul;
	data.dim = size;

	data.data = new double[data.dim];

	for (int i = 0; i < data.dim; i++)
		data.data[i] = x[i];
}

Monomial::Monomial(double mul, std::initializer_list<double> x)
{
	data.M = mul;
	data.dim = x.size();
	data.data = new double[data.dim];

	int count = 0;
	for (auto& element : x)
	{
		data.data[count] = element;
		count++;
	}
}

Monomial::Monomial(const Monomial& other)
{
	data.M = other.data.M;
	data.dim = other.data.dim;

	if (data.dim > 0)
	{
		data.data = new double[data.dim];
		for (int i = 0; i < data.dim; i++)
			data.data[i] = other.data.data[i];
	}
	else
		data.data = nullptr;
}

Monomial::~Monomial()
{
}

double Monomial::GetMul()
{
	return data.M;
}

void Monomial::SetMul(double mul)
{
	data.M = mul;
}

int Monomial::GetDim()
{
	return data.dim;
}

void Monomial::SetDim(int dim)
{
	if (data.dim == dim)
		return;
	else if (dim < 0)
		throw - 1;
	else if (dim == 0)
	{
		data.dim = 0;
		delete[] data.data;
		data.data = nullptr;
	}
	else
	{
		double* newData = new double[dim];

		if (dim < data.dim)
			memcpy(newData, data.data, dim * sizeof(double));
		else
			memcpy(newData, data.data, data.dim * sizeof(double));

		delete[] data.data;
		data.data = newData;

		if (dim > data.dim)
			for (int i = data.dim - 1; i < dim; i++)
				data.data[i] = 0;

		data.dim = dim;
	}
}

double& Monomial::operator[](int i)
{
	return data.data[i];
}

MonomialData& Monomial::operator*()
{
	return data;
}

Monomial& Monomial::operator=(const Monomial& other)
{
	if (*this == other)
		return *this;
	data = other.data;
	return *this;
}

Monomial* Monomial::operator+(const Monomial& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	Monomial* result = nullptr;
	if (*this == other)
	{
		result = new Monomial(*this);
		result->data.M += other.data.M;
	}
	else
	{
		result = new Monomial[2];
		if (*this > other)
		{
			result[0] = *this;
			result[1] = other;
		}
		else
		{

			result[0] = other;
			result[1] = *this;
		}
	}
	return result;
}

Monomial* Monomial::operator-(const Monomial& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	Monomial* result = nullptr;
	if (*this == other)
	{
		result = new Monomial(*this);
		result->data.M -= other.data.M;
	}
	else
	{
		result = new Monomial[2];
		result[0] = *this;
		result[1] = other;
		result[1].data.M *= -1;
	}
	return result;
}

Monomial Monomial::operator*(const Monomial& other)
{
	Monomial result(*this);
	result.data = data * other.data;
	return result;
}

Monomial Monomial::operator/(const Monomial& other)
{
	Monomial result(*this);
	result.data = data / other.data;
	return result;
}

bool Monomial::operator>(const Monomial& other)
{
	return data > other.data;
}

bool Monomial::operator<(const Monomial& other)
{
	return data < other.data;
}

bool Monomial::operator==(const Monomial& other)
{
	return data == other.data;
}

ostream& operator<<(ostream& ostr, const Monomial& m)
{
	ostr << m.data.M;
	char num = '1';
	for (int i = 0; i < m.data.dim; i++)
		ostr << "x" << num++ << "^" << m.data.data[i];
	return ostr;
}

istream& operator>>(istream& istr, Monomial& m)
{
	int dim = 0;
	if (m.data.dim != 0)
		dim = m.data.dim;
	else
	{
		istr >> dim;
		m.SetDim(dim);
	}

	istr >> m.data.M;
	for (int i = 0; i < dim; i++)
		istr >> m[i];
	return istr;
}
