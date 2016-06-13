#include <iostream>
using namespace std;
namespace Ch10
{
	class Complex
	{
	public:
		Complex(float r = 0.0f, float i = 0.0f): real(r), imag(i){
			cout << "constructor function called" << endl;
		}
		Complex(const Complex& other);
		Complex& operator =(const Complex& other);
		Complex operator ++();
		Complex operator ++(int);
		Complex operator --();
		Complex operator --(int);
		friend Complex operator +(const Complex& add1, const Complex& add2);
		friend Complex operator +(const Complex& add1, const float real2);
		friend Complex operator +(const float real1, const Complex& add2);
		friend Complex operator *(const Complex& mul1, const Complex& mul2);
		friend ostream& operator <<(const ostream& out, const Complex& complex);
		friend istream& operator >>(const istream& in, const Complex& complex);
	private:
		float real;
		float imag;
	};

	class String
	{
	public:
		String(char* p = NULL){
			if(p == NULL)	{
				size = 0;
				bufSize = 0;
				ptr = NULL;
			} else {
				size = strlen(p);
				bufSize = newBuffer(size);
				memcpy(ptr, p, sizeof(char) * size);
				*(ptr + size) = '\0';
			}
		}
	private:
		int newBuffer(int size);
		char* ptr;
		int size;
		int bufSize;
		const int newSize = 10;
	};
}

