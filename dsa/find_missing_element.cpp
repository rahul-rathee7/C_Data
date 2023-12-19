#include <iostream>
using namespace std;

void missingNumber(int array[], int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << array[i] << " ";
    // }
    // cout << endl;
    for(int i = 0, j = 1; i < n; i++, j++) {
        if(array[i] == j) {
            continue;
        }
        else {
            cout << "element is " << j << endl;
            exit(0);
        }
    }
    // cout << endl;
    // int i = 0, j = 1;
    // while(i < n) {
    //     if(array[i] == j) {
    //         continue;
    //     }
    //     else {
    //         cout << "element is " << j << endl;
    //         exit(0);
    //     }
    //     j++;
    //     i++;
    // }
}

int main()
{
    int n;
    cout << "Please enter how many numbers you want to enter: ";
    cin >> n;
    n = n-1;
    int array[n];
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++) {
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