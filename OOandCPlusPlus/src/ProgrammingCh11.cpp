#include "ProgrammingCh11.h"

namespace Ch11_base {
	void Person::show() {
		cout << "age: " << age << endl;
		cout << "name: " << name << endl;
		cout << "gender: " << gender << endl;
	}

	void School::show() {
		cout << "name: " << name << endl; 
	}

	void Student::show() {
		cout << "num: " << num << endl;
		Person::show();
		School::show();
		cout << "contact information: " << endl;
		contact.show();
	}

	void Teacher::show() {
		Student::show();
		cout << "major:" << major << endl;
		cout << "title:" << title << endl;
	}
}

namespace Ch11_virtual {
	void Person::show() {
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "name " << name << endl;
	}
	void Student::show() {
		Person::show();
		cout << "score: " << score << endl;
	}
	void Teacher::show() {
		Person::show();
		cout << "title: " << title << endl;
	}

	void Graduate::show() {
		Person::show();
		Student::show();
		Teacher::show();
		cout << "wage: " << wage << endl;
	}
}