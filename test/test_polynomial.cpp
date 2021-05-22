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
	//cout << p;
	auto i = p.begin();
	EXPECT_EQ(3, (*i).M);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_add_monomials_of_diff_lengths)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	ASSERT_NO_THROW(p += Monomial(3, { 3, 5, 4, 6 }));
	auto i = p.begin();
	EXPECT_EQ(3, (*i).M);
	EXPECT_EQ(4, (*i).dim);
	i++;
	EXPECT_EQ(2, (*i).M);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_copy_polynomial)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 5, 4, 6 });
	ASSERT_NO_THROW(Polynomial p2(p));
	Polynomial p2(p);
	EXPECT_EQ(2, p2.GetSize());

	auto i = p2.begin();
	EXPECT_EQ(3, (*i).M);
	EXPECT_EQ(4, (*i).dim);

	i++;
	EXPECT_EQ(2, (*i).M);
	EXPECT_EQ(3, (*i).dim);
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
	Polynomial p3 = p * p2;
	EXPECT_EQ(4, p3.GetSize());

	//cout << p3;
	auto i = p3.begin();
	EXPECT_EQ(15, (*i).M);
	EXPECT_EQ(3, (*i).dim);

	i++;
	EXPECT_EQ(12, (*i).M);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_add)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 4, 6 });

	Polynomial p2;
	p2 += Monomial(4, { 3, 4, 6 });
	p2 += Monomial(5, { 6, 3, 1 });

	ASSERT_NO_THROW(p + p2);

	Polynomial p3 = p + p2;
	EXPECT_EQ(3, p3.GetSize());

	//cout << p3;
	auto i = p3.begin();
	EXPECT_EQ(5, (*i).M);
	EXPECT_EQ(3, (*i).dim);

	i++;
	EXPECT_EQ(7, (*i).M);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_subtract)
{
	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 3, 4, 6 });

	Polynomial p2;
	p2 += Monomial(4, { 3, 4, 6 });
	p2 += Monomial(5, { 6, 3, 1 });

	ASSERT_NO_THROW(p - p2);

	Polynomial p3 = p - p2;
	EXPECT_EQ(3, p3.GetSize());

	//cout << p3;
	auto i = p3.begin();
	EXPECT_EQ(-5, (*i).M);
	EXPECT_EQ(3, (*i).dim);

	i++;
	EXPECT_EQ(-1, (*i).M);
	EXPECT_EQ(3, (*i).dim);
}
