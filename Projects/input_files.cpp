#include<iostream>
#include<string>
#include<fstream>

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
    ofstream out("input_files.txt");
    out << s.name << endl << s.rollno << endl << s.course << endl << s.grades << endl;
    out.close();
    ifstream in("input_files.txt");
    in >> s.name >> s.rollno >> s.course >> s.grades;
    in.close();
    cout << s.name << endl << s.rollno << endl << s.course << endl << s.grades << endl;
    out.close();
    return 0;
}