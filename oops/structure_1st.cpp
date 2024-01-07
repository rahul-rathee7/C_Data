#include<iostream>
#include<string.h>
using namespace std;

struct person {
	string name;
	int age;
	int height;
};

int main() {
	person person1;
	cout << "Please enter your name: ";
	getline(cin, person1.name);
	cout << "Please enter your age: ";
	cin>>person1.age;
	cout << "Please enter your height (in meters): ";
	cin>>person1.height;
	cout << "\n-------- *  Person Details  * --------\n";
	cout << "Name " << person1.name << endl;
	cout << "Age " << person1.age << endl;
	cout << "Height " << person1.height << endl;
}
