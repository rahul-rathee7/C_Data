#include<iostream>
using namespace std;

int main() {
    string str;
    string str1;
    cout << "Please enter your name: ";
    cin >> str;
    int i = 0; 
    while(str[i] != '\0')
        i++;
    while(i >= 0) {
        cout << str[i] << " ";
        i--;
    }
}