#include<iostream>
using namespace std;
// hello world

int insertion(int arr[], int n, int key, int cap) {
	if(n >= cap)
		return n;
	arr[n] = key;
	return (n+1);
}

int main() {
	int arr[10] = {2, 4, 1, 3, 5};
	int cap = sizeof(arr)/sizeof(arr[0]);
	int n = 5;
	int key = 26;
	n = insertion(arr, n, key, cap);
	for(int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
