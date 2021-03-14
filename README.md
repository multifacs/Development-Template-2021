# Roman Numerals
A small program that contains roman and arabic numerals structs

## Functions
Contains:
* struct arabic
* struct roman
* class converter

Create numbers like structs with one field:
```
roman mynum{ "III" };
```

Converter methods:
* arabic toArabic(roman num)
* roman toRoman(arabic num)

These methods can convert one type of number to another:
```
converter conv;

roman num1{ "CDXX" };
conv.toArabic(num1);
// = 420

arabic num2{ 123 };
conv.toRoman(num2);
// = "CXXIII"
