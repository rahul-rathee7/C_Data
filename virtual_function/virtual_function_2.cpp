#include<iostream>
using namespace std;

class Shape {
	public:
	virtual float calculateArea() = 0;
};

class Square : public Shape {
	float a;
	public:
	Square(float l) {
		a = l;
	}
	float calculatorArea() {
		return a*a;
	}
};

class Circle : public Shape {
	float r;
	public:

	Circle(float x) {
		r = x;
	}
	float calculateArea() {
		return 3.14*r*r;
	}
};

class Rectangle : public Shape {
	float l;
	float b;
	public:
	Rectangle(float x, float y) {
	l = x;
	b = y;
	}
	float CalculateArea() {
	return l*b;
	}
};

int main() {
	Shape *shape;
	Square s(3.4);
	Rectangle r (5,6);
	Circle c(7.3);
	shape = &s;
	int a1 = shape->calculateArea();
	shape = &r;
	int a2 = shape->calculateArea();
	shape = &c;
	int a3 = shape->calculateArea();
	cout << "area of square is " << a1 << endl;
	cout << "area of rectangle is " << a2 << endl;
	cout << "area of circle is " << a3 << endl;
}
