#include <iostream>
#include "ProgrammingCh9.h"
using namespace std;
void Sample9_1() {
	Time t1;
	t1.inputTime();
	t1.outputTime();
	Time t2;
	t2.outputTime();
}
void Sample9_2() {
	Box box1(12, 25, 30);
	cout << "box1(12, 25, 30): volume is " << box1.volume() << endl;
	Box box2(15, 30, 21);
	cout << "box2(15, 30, 21): volume is " << box2.volume() << endl;
}

void Sample9_5() {
	Student stu1(10010, "Wang Li", 'f');
	stu1.dislay();
	Student stu2(10011, "Zhang fun", 'm');
	stu2.dislay();
}

void Sample9_11() {
	Student stu[3] = {
		Student(1, "stu1", 100.0f),
		Student(2, "stu2", 101.0f),
		Student(3, "stu3", 98.73f)
	};
	for(int i = 0; i < 3; ++i)	stu[i].total();
	cout << "The average score: " << Student::average() << endl;
}

void Sample9_1213() {
	Time time;
	display(time);
	Date date(2016, 6, 13);
	time.displayData(date);
};

void Sample9_14() {
	Compare<int>	comInt(3, 7);
	Compare<float>	comFloat(3.0f, 7.0f);
	Compare<char>	cmChar('A', 'B');
	cout <<"For int comparison, min :"<< comInt.min() << " max :" << comInt.max() << endl;
	cout <<"For float comparison, min :"<< comFloat.min() << " max :" << comFloat.max() << endl;
	cout <<"For char comparison, min :"<< cmChar.min() << " max :" << cmChar.max() << endl;
}

int main() {
	//Sample9_1();
	//Sample9_2();
	//Sample9_5();
	//Sample9_11();
	//Sample9_1213();
	Sample9_14();
	system("pause");
	return 0;
}