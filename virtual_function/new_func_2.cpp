#include<iostream>
using namespace std;

void fun(int);
void fun(int &);

int main() {
    int a = 10;
    fun(a);
}

void fun(int x) {
    cout << "value of x is " << x << endl;
}
void fun(int &b) {
    cout << "value of b is " << b << endl;
}