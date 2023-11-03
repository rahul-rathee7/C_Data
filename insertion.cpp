#include<iostream>
using namespace std;

int main() {
	int arr[5] = { 2, 4, 1, 3, 5 };
	int newvalue = 6;
	arr[5] = newvalue;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i <= size; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
