#include "ProgrammingCh10.h"

namespace Ch10
{
	Complex::Complex(const Complex& other) {
		cout << "copy constructor function called" << endl;
		if(this != &other) {
			real = other.real;
			imag = other.imag;
		}
	}

	Complex& Complex::operator = (const Complex& other) {
		cout << "overload operator= called" << endl;
		if(this != &other) {
			real = other.real;
			imag = other.imag;
		}
		return *this;
	}

	Complex Complex::operator ++() {
		cout << "member front operator++ called" << endl;
		real += 1.0f;
		return *this;
	}

	Complex Complex::operator ++(int) {
		cout << "member front operator++ called" << endl;
		Complex tmp(*this);
		real += 1.0f;
		return tmp;
	}

	Complex Complex::operator --() {
		cout << "member front operator++ called" << endl;
		real -= 1.0f;
		return *this;
	}

	Complex Complex::operator --(int) {
		cout << "member front operator++ called" << endl;
		Complex tmp(*this);
		real -= 1.0f;
		return tmp;
	}

	Complex operator +(const Complex& add1, const Complex& add2) {
		cout << "friend operator+ 1 called" << endl;
		Complex complex(add1.real + add2.real, add1.imag + add2.imag);
		return complex;
	}
	
	Complex operator +(const Complex& add1, const float real2) {
		cout << "friend operator+ 2 called" << endl;
		Complex complex(add1.real + real2, add1.imag);
		return complex;
	}

	Complex operator +(const float real1, const Complex& add2) {
		cout << "friend operator+ 3 called" << endl;
		Complex complex(real1 + add2.real, add2.imag);
		return complex;
	}

	Complex operator *(const Complex& mul1, const Complex& mul2) {
		cout << "friend operator* called" << endl;
		int real = mul1.real * mul2.real - mul1.imag * mul2.imag;
		int imag = mul1.real * mul2.imag + mul1.imag * mul2.real;
		Complex complex(real, imag);
		return complex;
	}

	ostream& operator <<(ostream& out, Complex& complex) {
		cout << "friend operator << called" <<endl;
		out << "real: " << complex.real << " imag: " << complex.imag << endl;
		return out;
	}

	istream& operator >>(istream& in,  Complex& complex) {
		cout << "friend operator >> called" <<endl;
		in >> complex.real >> complex.imag;
		return in;
	}
}
