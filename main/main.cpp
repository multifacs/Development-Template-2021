#include "Polynomial.h"

int main() {

	Polynomial p;
	p += Monomial(2, { 1, 2, 3 });
	p += Monomial(3, { 6, 4, 2 });

	Polynomial p2;
	p2 += Monomial(4, { 6, 4, 2 });
	p2 += Monomial(5, { 7, 3, 1 });

	std::cout << "p = " << p << std::endl;
	std::cout << "p2 = " << p2 << std::endl;

	std::cout << "p * p2 = " << p*p2 << std::endl;
	std::cout << "p + p2 = " << p+p2 << std::endl;
	std::cout << "p - p2 = " << p-p2 << std::endl;


	//Monomial* d = a + c;
	//Polynomial f;
	//f =(d);

	//// C-style array
	//int my_array[5] = { 1, 2, 3, 4, 5 };

	//// Pass the array to a function
	//func(my_array);

	return 0;
}
