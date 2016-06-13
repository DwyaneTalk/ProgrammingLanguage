#include "ProgrammingCh9.h"
namespace Ch9
{
	void Time::inputTime() {
		cout << "please input the time:" << endl;
		cin >> hour >> minute >> second;
	}

	void Time::outputTime() {
		cout << "time is : " << hour << "H/" << minute << "M/" << second << "S" << endl;
	}

	void Time::displayData(Date& date) {
		cout << "date is : " << date.year << "Y/" << date.month << "M/" << date.day << "D" << endl;
	}

	int Box::volume() {
		return length * width * height;
	}

	void Student::dislay() {
		cout << "Student -> num: " << num << " name: " << name << " sex: " << sex << endl;
	}

	int   Student::count	= 0;
	float Student::sum	= 0.0f;
	void Student::total() {
		sum += score;
		++count;
	}

	float Student::average() {
		return sum / count;
	}

	void display(Time& time) {
		cout << "time is : " << time.hour << "H/" << time.minute << "M/" << time.second << "S" << endl;
	}
}

