#include<iostream>
using namespace std;

int duplicate(int arr[], int n){
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                c++;
            }
        }
        if(c > 0) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Please enter how many elements you want to enter: ";
    cin >> n;
    int arr[n];
    cout << "Please enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = duplicate(arr,n);
    cout << "answer is " << ans << endl;
}