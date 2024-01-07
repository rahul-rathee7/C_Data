#include<iostream>
using namespace std;

struct student {
	int x;
	int y;
};

void modifypoint(student &s) {
	s.x *= 2;
	s.y *= 2;
}

int main() {
	student s;
	s.x = 3, s.y = 4;
	modifypoint(s);
	cout << "modified number is " << s.x << ", " << s.y << endl;
}
