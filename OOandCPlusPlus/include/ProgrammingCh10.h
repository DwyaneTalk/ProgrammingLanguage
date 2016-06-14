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
		~Complex(){
			cout << "destructor function called" << endl;
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
		friend ostream& operator <<(ostream& out, Complex& complex);
		friend istream& operator >>(istream& in,  Complex& complex);
	private:
		float real;
		float imag;
	};

	class String
	{
	public:
		String(char* p = NULL){
			cout << "constructor function called" << endl;
			if(p == NULL)	{
				bufSize = 0;
				ptr = NULL;
				size = 0;
			} else {
				bufSize = strlen(p);
				ptr = new char[bufSize + 1];
				size = strlen(p);
				memcpy(ptr, p, sizeof(char) * size);
				*(ptr + size) = '\0';
			}
		}
		String(const String& str) {
			cout << "copy constructor function called" << endl;
			if(str.size == 0) {
				bufSize = 0;
				ptr = NULL;
				size = 0;
			} else {
				bufSize = str.size;
				ptr = new char[bufSize + 1];
				size = str.size;
				memcpy(ptr, str.ptr, sizeof(char) * size);
				*(ptr + size) = '\0';
			}

		}
		~String() {
			cout << "destructor function called" << endl;
			if(ptr)	delete[] ptr;
			ptr = NULL;
			size = 0;
			bufSize = 0;
		}
		String& operator =(const String& str);
		friend String operator +(const String& str1, const String& str2);
		friend bool operator == (const String& str1, const String& str2);
		friend bool operator <  (const String& str1, const String& str2);
		friend bool operator >  (const String& str1, const String& str2);
	private:
		int newBuffer(int size) {
			if(bufSize >= size)	return bufSize;
			int newSize = bufSize + (size - bufSize - 1) / NEWSIZE * NEWSIZE + NEWSIZE;
			if(this->size) {
				char* newPtr = new char[newSize + 1];
				memcpy(newPtr, ptr, sizeof(char) * this->size);
				delete[] ptr;
				ptr = newPtr;
			} else {
				ptr = new char[newSize + 1];
			}
			return newSize;
		}
		char* ptr;
		int size;
		int bufSize;
		const static int NEWSIZE = 10;
	};
}

