#include "Polynomial.hpp"

int main() {
	//double arr[3];
	//arr[0] = 2;
	//arr[1] = 3;
	//arr[2] = 5;
	//Monomial m(4, 3, arr);

	//std::cout << m << std::endl;
	//

	//Polynomial p;

	//p += m;
	//p += m;

	//Polynomial pp(p * p);

	//std::cout << pp << std::endl;

	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;

	Monomial a(1, 3, data);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	Monomial b(2, 3, data1);

	Monomial c;
	c = a * b;

	cout << a << endl << b << endl << c << endl;

	Polynomial p1, p2;
	p1 += c;
	p1 += a;
	cout << "p1 = " << p1 << endl;

	p2 += a;
	p2 += a;
	cout << "p2 = " << p2 << endl;

	Polynomial p3 = p1 + p2;
	cout << "p1 + p2 = " << p3 << endl;

	Polynomial p4 = p1 - p2;
	cout << "p1 - p2 = " << p4 << endl;

	Polynomial p5 = p1 * p2;
	cout << "p1 * p2 = " << p5 << endl;

	return 0;
}