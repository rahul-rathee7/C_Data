#include<iostream>
#include<string.h>
using namespace std;

double division(int a, int b) {
    if(b == 0){
        throw "division by zero condition";
    }
    return a/b;
}

int main() {
    int a = 50;
    int b = 0;
    double z = 0;

    try {
        z = division(a,b);
        cout << z << endl;
    }
        catch (const char* msg) {
            cerr << msg << endl;
        }
}

    // int a = 2/0;
    // cout << a << endl;

    // try {
    //     throw "rathee";
    // }
    // catch (char const*) {
    //     cout << "Caught" << endl;   
    // }
    // catch (...) {
    //     cout << "Default exception\n";
    // }