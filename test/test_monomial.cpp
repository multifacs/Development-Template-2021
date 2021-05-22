#include "monomial.h"
#include <gtest.h>

TEST(monomial, can_create_monomial)
{
	ASSERT_NO_THROW(Monomial m);
}

TEST(monomial, can_initialize_monomial)
{
	Monomial m(2, 3, new double[3]{ 1, 2, 3 });
	EXPECT_EQ(2, m.GetMul());
	EXPECT_EQ(3, m[2]);
}

TEST(monomial, can_initialize_monomial_2)
{
	Monomial m(2, { 1, 2, 3 });
	EXPECT_EQ(2, m.GetMul());
	EXPECT_EQ(3, m[2]);
}

TEST(monomial, can_copy_monomial)
{
	Monomial m(2, { 1, 2, 3 });
	ASSERT_NO_THROW(Monomial m2(m));
	Monomial m2(m);
	EXPECT_EQ(2, m2.GetMul());
	EXPECT_EQ(3, m2[2]);
}

TEST(monomial, can_set_dim)
{
	Monomial m(2, { 1, 2, 3, 4, 5 });
	Monomial m2(m);
	m.SetDim(3);
	EXPECT_EQ(3, m.GetDim());
	EXPECT_EQ(3, m[2]);
	m2.SetDim(6);
	EXPECT_EQ(6, m2.GetDim());
	EXPECT_EQ(0, m2[5]);
}

TEST(monomial, can_equalize)
{
	Monomial m(5, { 1, 2, 3, 4 });
	ASSERT_NO_THROW(Monomial m2 = m);
	Monomial m2 = m;
	EXPECT_EQ(5, m2.GetMul());
	EXPECT_EQ(3, m2[2]);
}

TEST(monomial, can_add)
{
	Monomial m1(3, { 1, 2, 3 });
	Monomial m2(3, { 1, 2, 3 });
	ASSERT_NO_THROW(m1 + m2);
	Monomial* m3 = m1 + m2;
	EXPECT_EQ(6, m3[0].GetMul());
}

TEST(monomial, can_add_2)
{
	Monomial m1(3, { 1, 2, 3 });
	Monomial m2(3, { 4, 5, 6 });
	ASSERT_NO_THROW(m1 + m2);
	Monomial* m3 = m1 + m2;
	EXPECT_EQ(4, m3[0][0]);
	EXPECT_EQ(1, m3[1][0]);
}

TEST(monomial, can_subtract)
{
	Monomial m1(4, { 1, 2, 3 });
	Monomial m2(3, { 1, 2, 3 });
	ASSERT_NO_THROW(m1 - m2);
	Monomial* m3 = m1 - m2;
	EXPECT_EQ(1, m3[0].GetMul());
}

TEST(monomial, can_subtract_2)
{
	Monomial m1(3, { 1, 2, 3 });
	Monomial m2(3, { 4, 5, 6 });
	ASSERT_NO_THROW(m1 - m2);
	Monomial* m3 = m1 - m2;
	EXPECT_EQ(3, m3[0].GetMul());
	EXPECT_EQ(-3, m3[1].GetMul());
}

TEST(monomial, can_multiply)
{
	Monomial m1(4, { 1, 2, 3 });
	Monomial m2(3, { 1, 2, 3 });
	ASSERT_NO_THROW(m1 * m2);
	Monomial m3 = m1 * m2;
	EXPECT_EQ(12, m3.GetMul());
	EXPECT_EQ(4, m3[1]);
}

TEST(monomial, can_divide)
{
	Monomial m1(6, { 1, 4, 3 });
	Monomial m2(3, { 1, 2, 3 });
	ASSERT_NO_THROW(m1 / m2);
	Monomial m3 = m1 / m2;
	EXPECT_EQ(2, m3.GetMul());
	EXPECT_EQ(2, m3[1]);
}

TEST(monomial, can_compare_more)
{
	Monomial m1(6, { 1, 4, 3 });
	Monomial m2(3, { 1, 2, 3 });
	Monomial m3(3, { 5, 2, 3 });
	ASSERT_NO_THROW(m1 > m2);
	EXPECT_EQ(true, m1 > m2);
	EXPECT_EQ(false, m1 > m3);
}

TEST(monomial, can_compare_less)
{
	Monomial m1(6, { 1, 2, 3 });
	Monomial m2(3, { 1, 4, 3 });
	Monomial m3(1, { 5, 2, 3 });
	ASSERT_NO_THROW(m1 < m2);
	EXPECT_EQ(true, m1 < m2);
	EXPECT_EQ(false, m3 < m2);
}

TEST(monomial, can_compare_equal)
{
	Monomial m1(6, { 1, 2, 3 });
	Monomial m2(3, { 1, 2, 3 });
	Monomial m3(1, { 5, 2, 3 });
	ASSERT_NO_THROW(m1 == m2);
	EXPECT_EQ(true, m1 == m2);
	EXPECT_EQ(false, m3 == m1);
}