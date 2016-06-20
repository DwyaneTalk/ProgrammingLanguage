#include <iostream>
#include "ProgrammingCh9.h"
#include "ProgrammingCh10.h"
#include "ProgrammingCh11.h"
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

void  Sample10_Complex() {
	Ch10::Complex com1;
	Ch10::Complex com2(10.0f, 10.0f);
	Ch10::Complex com3(com2);
	Ch10::Complex com4 = com2 + com3;
	com1 = com4;
	Ch10::Complex com5 = com2 + 10.0f;
	Ch10::Complex com6 = 10.0f + com2;
	Ch10::Complex com7 = com2 * com3;
	Ch10::Complex com8 = double(com5) + double(com6);
	cin >> com1 >> com2;
	cout << com1 << com2;
	com2 = com1++;
	com2 = com1--;
	com2 = ++com1; 
	com2 = --com1;
}

void Sample10_String() {
	Ch10::String str1;
	Ch10::String str2("hello world");
	Ch10::String str3(str1);
	Ch10::String str4(str2);
	Ch10::String str5 = str3 + str4;
	str1 = str2;
	bool ans1 = str1 == str2;
	bool ans2 = str1 >  str2;
	bool ans3 = str1 <  str2;
}

void Sample11_basicInherit() {
	Ch11_base::Person	father(45, "father", 'm');
	Ch11_base::School	peking("peking university");
	Ch11_base::Student	myself(20, "myself", 'm', "peking university", 1000, father);
	Ch11_base::Teacher	iamteaher(30, "teacher", 'm', "CS", "professor");
	father.show();
	peking.show();
	myself.show();
	iamteaher.show();
}
void Sample11_virtualInherit() {
	Ch11_virtual::Person	person(20, 'm', "myself");
	Ch11_virtual::Student	student(20, 'm', "myself", 90);
	Ch11_virtual::Teacher	teacher(20, 'm', "myself", "professor");
	Ch11_virtual::Graduate	gratuade(20, 'm', "myself", 90, "professor", 500);
	person.show();
	student.show();
	teacher.show();
	gratuade.show();
}
void Sample11_convert() {
	Ch11_base::Student	student(20, "student", 'm', "peking", 1000);
	Ch11_base::Person	person1	= Ch11_base::Person(20, "person", 'm');
	Ch11_base::Person	person2 = student;
	Ch11_base::Person&	person3 = student;
	Ch11_base::Person*	person4 = &student;
	Ch11_base::Student*	student2 = (Ch11_base::Student*) person4;
	student.show();
	person1.show();
	person2.show();
	person3.show();
	person4->show();
	student2->show();
}

int main() {
	Sample11_convert();
	system("pause");
	return 0;
}