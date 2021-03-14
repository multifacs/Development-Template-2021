#pragma once

#include <iostream>
#include <map>
#include <string>

struct arabic
{
	int value;
};

struct roman
{
	std::string value;
};

class converter
{
public:

	arabic toArabic(roman num);
	roman toRoman(arabic num);

	bool check(roman& num);
};