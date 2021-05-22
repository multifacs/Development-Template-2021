#include "MonomialData.h"

MonomialData::MonomialData(int t)
{
	if (t < 0)
		throw - 1;
	M = 0;
	dim = t;
	if (t == 0)
		data = nullptr;
	else
	{
		data = new double[dim];
		for (int i = 0; i < dim; i++)
			data[i] = 0;
	}
}

MonomialData::MonomialData(const MonomialData& other)
{
	M = other.M;
	dim = other.dim;
	if (dim == 0)
	{
		data = nullptr;
	}
	else
	{
		data = new double[dim];
		for (int i = 0; i < dim; i++)
			data[i] = other.data[i];
	}
}

MonomialData::~MonomialData()
{
	if (data != nullptr)
	{
		delete[] data;
		data = 0;
		dim = 0;
		M = 0;
	}
}

MonomialData& MonomialData::operator=(const MonomialData& other)
{
	if (*this == other)
		return *this;
	M = other.M;

	if (dim == other.dim)
	{
		for (int i = 0; i < dim; i++)
			data[i] = other.data[i];
	}
	else
	{
		if (data != nullptr)
			delete[] data;
		dim = other.dim;
		if (dim > 0)
		{
			data = new double[dim];
			for (int i = 0; i < dim; i++)
				data[i] = other.data[i];
		}
		else if (dim == 0)
			data = nullptr;
	}
	return *this;
}

bool MonomialData::operator==(const MonomialData& other)
{
	if ((dim != other.dim))
		return false;
	bool f = true;
	for (int i = 0; i < dim; i++)
	{
		if (data[i] != other.data[i])
		{
			f = false;
			break;
		}
	}
	return f;
}

bool MonomialData::operator>(const MonomialData& other)
{
	//if (dim != other.dim)
	//	throw - 1;

	if (this->dim > other.dim)
		return true;
	else if (this->dim < other.dim)
		return false;
	else
		for (int i = 0; i < dim; i++)
		{
			if (data[i] > other.data[i])
			{
				return true;
			}
			else if (data[i] < other.data[i])
			{
				return false;
			}
		}

	return false;
}

bool MonomialData::operator<(const MonomialData& other)
{
	//if (dim != other.dim)
	//	throw - 1;
	if (this->dim < other.dim)
		return true;
	else if (this->dim > other.dim)
		return false;
	else
		for (int i = 0; i < dim; i++)
		{
			if (data[i] < other.data[i])
			{
				return true;
			}
			else if (data[i] > other.data[i])
			{
				return false;
			}
		}
	return false;
}

MonomialData* MonomialData::operator+(const MonomialData& other)
{
	if (dim != other.dim)
		throw - 1;
	MonomialData* result = nullptr;
	if (*this == other)
	{
		result = new MonomialData(*this);
		result->M += other.M;
	}
	else
	{
		result = new MonomialData[2];
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

MonomialData* MonomialData::operator-(const MonomialData& other)
{
	if (dim != other.dim)
		throw - 1;
	MonomialData* result = nullptr;
	if (*this == other)
	{
		result = new MonomialData(*this);
		result->M -= other.M;
	}
	else
	{
		result = new MonomialData[2];
		result[0] = *this;
		result[1] = other;
		result[1].M *= -1;
	}
	return result;
}

MonomialData MonomialData::operator*(const MonomialData& other)
{
	MonomialData result(*this);
	if (dim != other.dim)
		throw - 1;
	result.M = M * other.M;
	for (int i = 0; i < dim; i++)
		result.data[i] = this->data[i] + other.data[i];
	return result;
}

MonomialData MonomialData::operator/(const MonomialData& other)
{
	MonomialData result(*this);
	if (dim != other.dim)
		throw - 1;
	result.M = M / other.M;
	for (int i = 0; i < dim; i++)
		result.data[i] = this->data[i] - other.data[i];
	return result;
}

std::ostream& operator<<(std::ostream& ostr, const MonomialData& m)
{
	ostr << m.M;
	char num = '1';
	for (int i = 0; i < m.dim; i++)
		ostr << "x" << num++ << "^" << m.data[i];
	return ostr;
}
