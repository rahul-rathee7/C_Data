#include<iostream>
using namespace std;

int w, x, y, z;

class A {
    public:
        A(int a) {
            cout << "A class is called" << endl;
        }
        void A_func() {
            cout << "class A function is called" << endl;
        }
};

class B {
    public:
        B(int b) {
            cout << "B class is called" << endl;
        }
        void B_func() {
            cout << "class B function is called" << endl;
        }
};

class C : public A, public B{
    public:
        C(int a, int b, int c, int d): A(a), B(b){
            y = c;
            z = b;
        }
        void C_func() {
            cout << "class C function is called" << endl;
        }
};

int main() {
    C a(1,2,3,4);
    a.A_func();
    a.B_func();
    a.C_func();
}