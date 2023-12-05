#include<iostream>
using namespace std;

class A {
    public:
    void func_1() {
        cout << "base-1\n";
    }
    virtual void func_2() {
        cout << "base-2\n";
    }
    virtual void func_3() {
        cout << "base-3\n";
    }
    virtual void func_4() {
        cout << "base-4\n";
    }
};

class B : public A{
    void func_1(){
        cout << "derived-1\n";
    }  
    void func_2(){
        cout << "derived-2\n";
    }  
    void func_3(){
        cout << "derived-3\n";
    }  
    void func_4(int x){
        cout << "derived-4\n";
    }  
};

int main() {
    A* p;
    B obj1;
    p = &obj1;

    p->func_1();
    p->func_2();
    p->func_3();
    p->func_4(10);
}