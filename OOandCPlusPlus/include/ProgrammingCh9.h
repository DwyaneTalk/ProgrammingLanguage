#include <string>
#include <iostream>
using namespace std;

class Date;
class Time;
void display(Time& time);

class Time 
{
public:
	Time() {
		hour = 0;
		minute = 0;
		second = 0;
	}
	void inputTime();
	void outputTime();
	friend void display(Time& time);
	void displayData(Date& date);
private:
	int hour;
	int minute;
	int second;
};

class Box
{
public:
	Box(): length(10), width(10), height(10){}
	Box(int l, int w, int h) {
		length = l;
		width = w;
		height = h;
	}
	int volume();
private:
	int length;
	int width;
	int height;
};

class Student
{
public:
	Student(int n, string nam, char s) {
		num = n;
		name = nam;
		sex = s;
		cout << "Constructor called for num: " << num << endl;
	}
	Student(int n, string nam, float s):num(n), name(nam), score(s){
		cout << "Constructor called for num: " << num << endl;
	}
	~Student() {
		cout << "Desctructor called for num:" << num << endl;
	}
	void dislay();
	void total();
	static float average();
private:
	int num;
	string name;
	char sex;
	float score;
	static int count;
	static float sum;
};

class Date
{
public:
	Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d){};
	friend void Time::displayData(Date& date);
private:
	int year;
	int month;
	int day;
};

template <class compareType>
class Compare
{
public:
	Compare(compareType n1, compareType n2): num1(n1), num2(n2) {}
	compareType min() {
		return num1 > num2 ? num2 : num1;
	}
	compareType max() {
		return num1 > num2 ? num1 : num2;
	}
private:
	compareType num1;
	compareType num2;
};