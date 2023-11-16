#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[5] = {3,-10,4,2,30};
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < 5; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min) 
            min = arr[i];
    }
    cout << "maximum of element is: " << max << endl;
    cout << "minimum of element is: " << min << endl;
    return 0;
}