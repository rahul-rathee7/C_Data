#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class student {
public:
    string name, grades;
    long long int rollno;
    void func() {
        cout << "Please enter your name: ";
        cin >> name;
        cout << "Please enter your roll-no: ";
        cin >> rollno;
        cout << "Please enter your grades: ";
        cin >> grades;
    }
    void show() {
        cout << "Your name is " << name << endl;
        cout << "Your roll-no is " << rollno << endl;
        cout << "Your grades is " << grades << endl;
    }
};

int main() {
    student s;
    s.func();
    s.show();
    ofstream out("oops_marks.txt", std::ios::app);
    out << s.name << " " << s.rollno << " " << s.grades << endl;
    out.close();
    return 0;
}
