#include <iostream>
#include "ProgrammingCh9.h"
#include "ProgrammingCh10.h"
using namespace std;

void Sample9_1() {
	Ch9::Time t1;
	t1.inputTime();
	t1.outputTime();
	Ch9::Time t2;
	t2.outputTime();
}
void Sample9_2() {
	Ch9::Box box1(12, 25, 30);
	cout << "box1(12, 25, 30): volume is " << box1.volume() << endl;
	Ch9::Box box2(15, 30, 21);
	cout << "box2(15, 30, 21): volume is " << box2.volume() << endl;
}
void Sample9_5() {
	Ch9::Student stu1(10010, "Wang Li", 'f');
	stu1.dislay();
	Ch9::Student stu2(10011, "Zhang fun", 'm');
	stu2.dislay();
}
void Sample9_11() {
	Ch9::Student stu[3] = {
		Ch9::Student(1, "stu1", 100.0f),
		Ch9::Student(2, "stu2", 101.0f),
		Ch9::Student(3, "stu3", 98.73f)
	};
	for(int i = 0; i < 3; ++i)	stu[i].total();
	cout << "The average score: " << Ch9::Student::average() << endl;
}
void Sample9_1213() {
	Ch9::Time time;
	display(time);
	Ch9::Date date(2016, 6, 13);
	time.displayData(date);
};
void Sample9_14() {
	Ch9::Compare<int>	comInt(3, 7);
	Ch9::Compare<float>	comFloat(3.0f, 7.0f);
	Ch9::Compare<char>	cmChar('A', 'B');
	cout <<"For int comparison, min :"<< comInt.min() << " max :" << comInt.max() << endl;
	cout <<"For float comparison, min :"<< comFloat.min() << " max :" << comFloat.max() << endl;
	cout <<"For char comparison, min :"<< cmChar.min() << " max :" << cmChar.max() << endl;
}

void Sample10_Complex() {
	Ch10::Complex com1;
	Ch10::Complex com2(10.0f, 10.0f);
	Ch10::Complex com3(com2);
	Ch10::Complex com4 = com2 + com3;
	com1 = com4;
	Ch10::Complex com5 = com2 + 10.0f;
	Ch10::Complex com6 = 10.0f + com2;

}

int main() {
	Sample10_Complex();
	system("pause");
	return 0;
}