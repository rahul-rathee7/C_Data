#include<iostream>
using namespace std;

int addNumberSequence(int n){
	n = n + 1;
	n = n + 2;
	n = n + 3;
	n = n + 4;
	n = n + 5;
	return n;
}

int main() {
	int number;
	cout << "Please enter a number: ";
	cin >> number;
	cout << endl;
	addNumberSequence(number);
}
