#include<iostream>
using namespace std;

int a, b;

class A {
    public:
        A() {
            cout << "sum of a and b is " << a+b << endl;
        }
};

class B {
    public:
        B() {
            cout << "Please enter 2 numbers: ";
            cin >> a >> b;
        }  
};

class c : public A, virtual public B{
    public:
        c() {
            cout << "multiplication of a and b is " << a*b << endl;
        }
};

int main() {
    c o;
}