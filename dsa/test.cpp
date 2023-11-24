#include<iostream>
using namespace std;

int main() {
    int n; 
    cout << "Please enter a value: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k = 0;
        for(int j = 0; j < 2*n-1; j++) {
            if(j < i+1)
                cout << "*";
            else if(k < (n-(i+1))*2-1) {
                cout << " ";
                k++;
            }
            else
                cout << "*";
        }
        cout << endl;
    }
}