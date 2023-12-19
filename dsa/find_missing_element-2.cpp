#include <iostream>
using namespace std;

void missingNumber(int array[], int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum << endl;
    int sum1 = 0;
    for(int i = 0; i < n-1; i++) {
        sum1 += array[i];
    }
    cout << sum-sum1 << endl;
}

int main()
{
    int n;
    cout << "Please enter how many numbers you want to enter: ";
    cin >> n;
    int array[n-1];
    cout << "Enter array elements:\n";
    for(int i = 0; i < n-1; i++) {
        cin >> array[i];
    }
    missingNumber(array, n);
    // if(c == 0){
    //     cout << "missing element not found\n";
    // }
    // else {
    //     cout << c << endl;
    // }
}