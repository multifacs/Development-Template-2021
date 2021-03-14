#include <iostream>
#include "roman.h"

using namespace std;

int main() {

	arabic num = { 1 };
	roman num2 = { "IIIIIIII" };

	converter conv;

	cout << num.value << endl;
	cout << conv.toArabic(num2).value << endl;
	cout << conv.check(num2) << endl;
	cout << num2.value << endl;
	return 0;
}