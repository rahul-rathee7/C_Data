#include<iostream>
using namespace std;

struct point {
	int x;
	int y;
};

void modifypoint(point &p) {
	p.x *= 2;
	p.y *= 2;
}

int main() {
	point mypoint = {3, 4};
	modifypoint(mypoint);
	cout << "modifypoint is (" << mypoint.x << ", " << mypoint.y << ")" << endl;
}
