#include "ProgrammingCh12.h"

namespace Ch12 
{
	ostream& operator << (ostream& out, Student& student) {
		out << "age: " << student.age << endl;
		out << "sex: " << student.sex << endl;
		out << "name: " << student.name << endl;
		return out;
	}

	ostream& operator << (ostream& out, Graduate& graduate) {
		Student& student = graduate;
		out << student;
		out << "wage: " << graduate.wage << endl;
		return out;
	}

	void Student::show() {
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "name: " << name << endl;
	}

	void Graduate::show() {
		Student::show();
		cout << "wage: " << wage << endl;
	}

	float Circle::area() const{
		return PI * r * r;
	}

	float Cylinder::area() const{
		return 2 * Circle::area() + 2 * PI * h;
	}

	float Cylinder::volume() const{
		return Circle::area() * h;
	}
}