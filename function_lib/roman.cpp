#include "roman.h"

arabic converter::toArabic(roman num)
{
    std::map<char, int> m
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    arabic result{ 0 };

    for (int i = 0; i < num.value.length() - 1; i++)
    {
        if (m[num.value[i]] < m[num.value[static_cast<unsigned __int64>(i) + 1]])
            result.value -= m[num.value[i]];
        else if (m[num.value[i]] >= m[num.value[static_cast<unsigned __int64>(i) + 1]])
            result.value += m[num.value[i]];
    }

    result.value += m[num.value[num.value.length() - 1]];

	return result;
}

roman converter::toRoman(arabic num)
{
	std::map <int, std::string> symbol =
	{
		{1000,"M"},
		{900, "CM"},
		{500, "D"},
		{400, "CD"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{40, "XL"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{4, "IV"},
		{1, "I"}
	};

	int levels[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

	std::string result = std::string();

	for (const int& level : levels)
	{
		if (num.value >= level)
		{
			do
			{
				result += symbol[level];
				num.value -= level;
			}
			while (num.value >= level);
		}
	}
	return roman{ result };
}

bool converter::check(roman& num)
{
	roman checked = toRoman(toArabic(num));

	if (num.value == checked.value)
		return true;
	else
	{
		num.value = checked.value;
		return false;
	}
}
