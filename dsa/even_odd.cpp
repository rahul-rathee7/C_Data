#include<iostream>
using namespace std;

bool odd_even(int n) {
    if(n % 2 == 0)
        return true;
    else   
        return false;
}

int main() {
    int n;
    cout << "Please enter a number to check if number is odd or even: ";
    cin >> n;
    bool iseven = odd_even(n);
    if(iseven == true)
        cout << "number is even" << endl;
    else    
        cout << "number is odd" << endl;
    return 0;
}