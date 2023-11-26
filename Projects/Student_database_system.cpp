#include<iostream>
#include<string>
using namespace std;

class student {
public:
    string name, grades, course;
    long long int rollno;
    void func() {
        cout << "Please enter your name: ";
        cin >> name;
        cout << "Please enter your roll-no: ";
        cin >> rollno;
        cout << "Please enter your course: ";
        cin >> course;
        cout << "Please enter your grades: ";
        cin >> grades;
    }
    void show() {
        cout << "Your name is " << name << endl;
        cout << "Your roll-no is " << rollno << endl;
        cout << "Your course is " << course << endl;
        cout << "Your grades is " << grades << endl;
    }
};

int main() {
    student s;
    s.func();
    s.show();
    return 0;
}
