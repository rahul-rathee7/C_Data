#include<iostream>
using namespace std;

class poly {
    public:
    void func(int x) {
        cout << "value of x is " << x << endl;
    }
    void func(double x) {
        cout << "value of x in double is " << x << endl;
    }
    void func(int x, int y) {
        cout << "addition of x and y is " << x+y << endl;
    }
};

int main() {
    poly r;
    r.func(10);
    r.func(20.30);
    r.func(30,50);
}