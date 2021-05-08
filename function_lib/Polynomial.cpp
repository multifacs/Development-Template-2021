#include "Polynomial.hpp"

Polynomial::Polynomial() : SList<MonomialData>()
{

}

Polynomial::Polynomial(const Polynomial& other) : SList<MonomialData>(other)
{
}

Polynomial::~Polynomial()
{
}

//Polynomial& Polynomial::operator=(const Monomial*& arr)
//{
//	if (this->head != nullptr)
//		clear();
//
//	Size = 0;
//	head = nullptr;
//	Iterator k = _l.begin_const();
//	while (k.CanMove())
//	{
//		push_back(*k);
//		k++;
//	}
//
//	return *this;
//}

Polynomial& Polynomial::operator+=(const Monomial& other)
{
	if (this->GetSize() == 0)
	{
		this->push_back(other.data);
		return *this;
	}

	SList::Iterator i = this->begin();
	while (i.CanMove())
	{
		if (*i == other.data)
		{
			(*i).M += other.data.M;
			return *this;
		}
		else
		{
			if (*i < other.data)
			{
				this->push_front(other.data);
				return *this;
			}
			else
			{
				this->push_back(other.data);
				return *this;
			}
		}
		i++;
	}
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other)
{
	Polynomial result;
	SList::Iterator i = this->begin();
	if (this->GetSize() == 0 && (other.GetSize() == 0))
		throw -1;
	while (i.CanMove())
	{
		SList::Iterator j = other.begin_const();
		while (j.CanMove())
		{
			result.push_back(*i * *j);
			j++;
		}
		i++;
	}
	return result;
}

Polynomial Polynomial::operator+(const Polynomial& other)
{
	if ((this->head == nullptr) || (other.head == nullptr))
		throw -1;

	Polynomial result;
	Iterator i = this->begin();
	Iterator j = other.begin_const();
	MonomialData temp;

	while (i.CanMove() && j.CanMove())
	{
		if (*i == *j)
		{
			temp = (*i + *j)[0];
			i++;
			j++;
		}
		else if (*i > *j)
		{
			temp = *i;
			i++;
		}
		else if (*i < *j)
		{
			temp = *j;
			j++;
		}

		result.push_back(temp);
	}

	if (i.CanMove())
		while (i.CanMove())
		{
			result.push_back(*i);
			i++;
		}

	if (j.CanMove())
		while (j.CanMove())
		{
			result.push_back(*j);
			j++;
		}

	return result;
}

Polynomial Polynomial::operator-(const Polynomial& other)
{
	if ((this->head == nullptr) || (other.head == nullptr))
		throw - 1;

	Polynomial result;
	Iterator i = this->begin();
	Iterator j = other.begin_const();
	MonomialData temp;

	while (i.CanMove() && j.CanMove())
	{
		if (*i == *j)
		{
			temp = (*i - *j)[0];
			i++;
			j++;
		}
		else if (*i > *j)
		{
			temp = *i;
			i++;
		}
		else if (*i < *j)
		{
			temp = *j;
			temp.M *= -1;
			j++;
		}

		result.push_back(temp);
	}

	if (i.CanMove())
		while (i.CanMove())
		{
			MonomialData temp = *i;
			temp.M *= -1;
			result.push_back(temp);
			i++;
		}

	if (j.CanMove())
		while (j.CanMove())
		{
			MonomialData temp = *j;
			temp.M *= -1;
			result.push_back(temp);
			j++;
		}

	return result;
}

ostream& operator<<(ostream& ostr, const Polynomial& p)
{
	SList<MonomialData>::Iterator i = p.begin_const();
	while (i.CanMove())
	{
		if (*i == *p.begin_const())
			ostr << *i;
		else
			ostr << (((*i).M > 0) ? " +" : " ") << *i;
		i++;
	}
	return ostr;
}
