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


	String& String:: operator =(const String& str) {
		cout << "friend operator = called" <<endl;
		if(this != &str) {
			bufSize = newBuffer(str.size);
			size = str.size;
			memcpy(ptr, str.ptr, sizeof(char) * size);
			*(ptr + size) = '\0';
		}
		return *this;
	}

	String operator +(const String& str1, const String& str2) {
		cout << "friend operator + called" <<endl;
		String str(str1);
		str.bufSize = str.newBuffer(str1.size + str2.size);
		str.size = str1.size + str2.size;
		memcpy(str.ptr + str1.size, str2.ptr, sizeof(char)* str2.size);
		*(str.ptr + str.size) = '\0';
		return str;
	}

	bool operator ==(const String& str1, const String& str2) {
		cout << "friend operator == called" <<endl;
		if(str1.size != str2.size)	return false;
		char *ptr1 = str1.ptr, *ptr2 = str2.ptr;
		while(*ptr1 != '\0') {
			if(*ptr1++ != *ptr2++)	return false;
		}
		return true;
	}

	bool operator  >(const String& str1, const String& str2) {
		cout << "friend operator > called" <<endl;
		char *ptr1 = str1.ptr, *ptr2 = str2.ptr;
		while(*ptr1 != '\0' && *ptr2 != '\0') {
			if(*ptr1 > *ptr2)	return true;
			if(*ptr1++ < *ptr2++)	return false;
		}
		return *ptr1 != '\0';
	}

	bool operator  <(const String& str1, const String& str2) {
		cout << "friend operator < called" <<endl;
		char *ptr1 = str1.ptr, *ptr2 = str2.ptr;
		while(*ptr1 != '\0' && *ptr2 != '\0') {
			if(*ptr1 < *ptr2)	return true;
			if(*ptr1++ > *ptr2++)	return false;
		}
		return *ptr2 != '\0';
	}
}
