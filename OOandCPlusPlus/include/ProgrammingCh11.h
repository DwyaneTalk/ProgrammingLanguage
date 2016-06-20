#include <iostream>
#include <string>
using namespace std;

namespace Ch11_base {
	class Person
	{
	public:
		Person(int age = 0, char* name = "", char gender = 'm') : age(age), name(name), gender(gender){
			cout << "Person Construct Function Called!" <<endl;
		};
		~Person() {
			cout << "Person Destruct Function Called!" << endl;
		}
		void show();
	protected:
		int		age;
		string	name;
		char	gender;
	};

	class School
	{
	public:
		School(char* name = "") : name(name) {
			cout << "School Construct Function Called!" << endl;
		};
		~School() {
			cout << "School Destruct Function Called!" << endl;
		}
		void show();
	private:
		string	name;
	};

	class Student : public Person, public School
	{
	public:
		Student(int age = 0, char* name = "", char gen = 'm', char* s_name = "", int num = 0, Person contact = Person()) 
			: Person(age, name, gen), School(s_name), contact(contact), num(num){
				cout << "Student Construct Function Called!" << endl;
		};

		~Student() {
			cout << "Student Destruct Function Called!" << endl;
		}
		void show();
	protected:
		int		num;
		Person	contact;
	};

	class Teacher : public Student
	{
	public:
		Teacher(int age = 0, char* name = "", char gender = 'm', char* major = "", char* title = "")
			: Student(age, name, gender), major(major), title(title) {
			cout << "Teacher Construct Function Called!" << endl;
		};
		~Teacher() {
			cout << "Teacher Destruct Function Called!" << endl;
		}
		void show();
	protected:
		string	major;
		string	title;
	};
}

namespace Ch11_virtual 
{
	class Person 
	{
	public: 
		Person(int age = 0, char sex = 'm', char* name = "") : age(age), sex(sex), name(name) {
			cout << "Person Construct Function Called!" << endl;
		}
		~Person() {
			cout << "Person Destruct Function Called!" << endl;
		}
		void show();
	protected:
		int		age;
		char	sex;
		string	name;
	};

	class Student : virtual public Person
	{
	public:
		Student(int age = 0, char sex = 'm', char* name = "", float score = 0.0f) : Person(age, sex, name), score(score) {
			cout << "Student Construct Function Called!" << endl;
		}
		~Student() {
			cout << "Student Destruct Function Called!" << endl;
		}
		void show();
	protected:
		float	score;
	};

	class Teacher : virtual public Person
	{
	public:
		Teacher(int age = 0, char sex = 'm', char* name = "", char* title = "") : Person(age, sex, name), title(title) {
			cout << "Teacher Construct Function Called!" << endl;
		}
		~Teacher() {
			cout << "Teacher Destruct Function Called!" << endl;
		}
		void show();
	protected:
		string	title;
	};

	class Graduate : public Student, public Teacher
	{
	public:
		Graduate(int age = 0, char sex = 'm', char* name = "", float score = 0.0f, char* title = "", float wage = 0.0f)
			: Person(age, sex, name), Student(age, sex, name, score), Teacher(age, sex, name, title), wage(wage) {
			cout << "Graduate Construct Function Called!" << endl;
		}
		~Graduate() {
			cout << "Graduate Destruct Function Called!" << endl;
		}
		void show();
	protected:
		float	wage;
	};
}