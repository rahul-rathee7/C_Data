#include <iostream>
using namespace std;

int main()
{
	double num[] = { 11, 12, 13, 14, 15, 16 };
	double add = 0;
	double count = 0;
	double avg;
	cout << "The number is=";

	for (const double& n : num) {
		cout << n << " " <<endl;

		add += n;

		++count;
	}
	cout << "Addition of numbers= " << add << endl;
	avg = add / count;
	cout << "average of numbers= " << avg << endl;

	return 0;
}

