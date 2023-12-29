#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cout << "Please enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Please enter array's elements\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = INT_MIN;
    int max2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] > max2 && arr[i] < max)
            max2 = arr[i];
    }
    cout << "second largest elements is " << max2 << endl;
}