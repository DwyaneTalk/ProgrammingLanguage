#include <iostream>
#include <string>
using namespace std;
#define PI 3.141592654

namespace Ch12 {
	class Student
	{
	public:
		Student(int age = 0, char sex = 'm', char* name = "") : age(age), sex(sex), name(name){
			cout << "Student Construct Function Called!" << endl;
		};
		virtual ~Student(){
			cout << "Student Destruct Function Called!" << endl;
		}
		friend ostream& operator << (ostream& out, Student& student);
		virtual void show();
	protected:
		int		age;
		char	sex;
		string	name;
	};

	class Graduate : public Student
	{
	public:
		Graduate(int age = 0, char sex = 'm', char* name = "", float wage = 0.0f) : Student(age, sex, name), wage(wage){
			cout << "Graduate Construct Function Called!" << endl;
		};
		~Graduate() {
			cout << "Graduate Destruct Function Called!" << endl;
		}
		friend ostream& operator << (ostream& out, Graduate& graduate);
		void show();
	protected:
		float	wage;
	};

	class Shape
	{
	public:
		Shape(int hi = 0) : hidden(hi) {
			cout << "Shape Construct Function Called!" << endl;
		}
		virtual ~Shape() {
			cout << "Shape Destruct Function Called!" << endl;
		}
		virtual int		getHiddden() const { return hidden; };
		virtual void	showName() const = 0;
		virtual float	area() const { return 0;};
		virtual	float	volume() const {return 0;};
	protected:
		int	hidden;
	};

	class Point : public Shape
	{
	public:
		Point(int hi = 0, float x = 0.0f, float y = 0.0f) : Shape(hi), x(x), y(y) {
			cout << "Point Construct Function Called!" << endl;
		}
		virtual ~Point() {
			cout << "Point Destruct Function Called!" << endl;
		}
		void	setPoint(float x, float y) {this->x = x; this->y = y;};
		float	getX() const {return x;};
		float	getY() const {return y;};
		virtual void showName() const {cout << "this is a Point!" << endl;};
	protected:
		float	x, y;
	};

	class Circle : public Point
	{
	public:
		Circle(int hi = 0, float x = 0.0f, float y = 0.0f, float r = 0.0f) : Point(hi, x, y), r(r) {
			cout << "Circle Construct Function Called!" << endl;
		}
		virtual ~Circle() {
			cout << "Circle Destruct Function Called!" << endl;
		}
		void	setRadius(float r) { this->r = r; };
		float	getRadius() const { return r;}
		virtual float area() const;
		virtual void  showName() const {cout << "this is a circle" << endl;};
	protected:
		float	r;
	};

	class Cylinder : public Circle 
	{
	public:
		Cylinder(int hi = 0, float x = 0.0f, float y =0.0f, float r = 0.0f, float h = 0.0f)
			: Circle(hi, x, y, r), h(h) {
				cout << "Cylinder Construct Function Called!" << endl;
		}
		virtual ~Cylinder() {
			cout << "Cylinder Destruct Function Called!" << endl;
		}
		void	setHeight(float h) { this->h = h;};
		float	getHeight() const { return h;};
		virtual float area() const;
		virtual float volume() const;
		virtual void  showName() const { cout << "this is a Cylinder" << endl;};
	protected:
		float	h;
	};
}