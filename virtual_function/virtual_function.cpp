#include<iostream>
using namespace std;

class base {
	public:
	virtual void show()
	{
	cout << "print base class\n";
	}
};

class derived : public base {
	public:
	void show() {
	cout << "show derived class\n";
	}
};

int main() {
	base* bptr;
	derived d;
	bptr = &d;

	bptr -> show();
}
