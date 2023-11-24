#include<iostream>
using namespace std;

void func(int);
void func(float);
void func(int i) {
    cout << "value of i is " << i << endl;
}
void func(double j) {
    cout << "value of j is " << j << endl;
}

int main() {
    func(12);
    func(1.2);
}