#include "roman.h"

#include <gtest.h>

TEST(roman, can_create_roman)
{
	ASSERT_NO_THROW(roman num{ "III" });
}

TEST(roman, can_create_arabic)
{
	ASSERT_NO_THROW(arabic num{ 123 });
}

TEST(roman, toArabic_1)
{
	roman num1{ "I" };
	converter conv;

	EXPECT_EQ(1, conv.toArabic(num1).value);
}

TEST(roman, toArabic_9)
{
	roman num1{ "IX" };
	converter conv;

	EXPECT_EQ(9, conv.toArabic(num1).value);
}

TEST(roman, toArabic_11)
{
	roman num1{ "XI" };
	converter conv;

	EXPECT_EQ(11, conv.toArabic(num1).value);
}

TEST(roman, toArabic_19)
{
	roman num1{ "XIX" };
	converter conv;

	EXPECT_EQ(19, conv.toArabic(num1).value);
}

TEST(roman, toRoman_1)
{
	arabic num{ 1 };
	converter conv;

	EXPECT_EQ("I", conv.toRoman(num).value);
}

TEST(roman, toRoman_3)
{
	arabic num{ 3 };
	converter conv;

	EXPECT_EQ("III", conv.toRoman(num).value);
}

TEST(roman, toRoman_500)
{
	arabic num{ 500 };
	converter conv;

	EXPECT_EQ("D", conv.toRoman(num).value);
}

TEST(roman, toRoman_2694)
{
	arabic num{ 2694 };
	converter conv;

	EXPECT_EQ("MMDCXCIV", conv.toRoman(num).value);
}

TEST(roman, check_true)
{
	roman num{ "VIII" };
	converter conv;

	EXPECT_EQ(true, conv.check(num));
}

TEST(roman, check_false)
{
	roman num{ "IIIIIIII" };
	converter conv;

	EXPECT_EQ(false, conv.check(num));
	EXPECT_EQ("VIII", num.value);
}