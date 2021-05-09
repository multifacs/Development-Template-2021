#include "polynomial.h"
#include <gtest.h>

TEST(polynomial, can_create_polynomial)
{
	ASSERT_NO_THROW(Polynomial p);
}

TEST(polynomial, can_add_monomials)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	ASSERT_NO_THROW(p += Monomial(3, { 3, 4, 6 }));
}

TEST(polynomial, can_add_monomials_of_diff_lengths)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	ASSERT_NO_THROW(p += Monomial(3, { 3, 5, 4, 6 }));
}

TEST(polynomial, can_copy_polynomial)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 5, 4, 6 });
	ASSERT_NO_THROW(Polynomial p2(p));
	Polynomial p2(p);
}

TEST(polynomial, can_multiply)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 4, 6 });

	Polynomial p2;
	p2 += Monomial(4, { 3, 5, 2 });
	p2 += Monomial(5, { 6, 3, 1 });

	ASSERT_NO_THROW(p * p2);
}

TEST(polynomial, can_add)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 4, 6 });

	Polynomial p2;
	p2 += Monomial(4, { 3, 5, 2 });
	p2 += Monomial(5, { 6, 3, 1 });

	ASSERT_NO_THROW(p + p2);
}

TEST(polynomial, can_subtract)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 4, 6 });

	Polynomial p2;
	p2 += Monomial(4, { 3, 5, 2 });
	p2 += Monomial(5, { 6, 3, 1 });

	ASSERT_NO_THROW(p - p2);
}
