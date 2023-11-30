#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class student {
public:
    string name, grades;
    long long int rollno;
    void func() {
        cout << "Please enter your roll-no: ";
        cin >> rollno;
        cout << "Please enter your name: ";
        cin >> name;
        cout << "Please enter your grades: ";
        cin >> grades;
    }
    void show() {
        cout << "Your roll-no is " << rollno << endl;
        cout << "Your name is " << name << endl;
        cout << "Your grades is " << grades << endl;
    }
};

int main() {
    student s;
    s.func();
    // s.show();
    string roll_no;
    ifstream in("oops_marks.txt");
    in >> roll_no;
    in.close();
    cout << endl << endl << roll_no << endl << endl;
    if(s.name == roll_no) {
        cout << "sorry we can't add your data in this database file";
        exit(0);
    }
    else {
    ofstream out("oops_marks.txt", std::ios::app);
    out << s.name << " " << s.rollno << " " << s.grades << endl;
    out.close();
    ifstream in("oops_marks.txt");
    while(in.eof()==0) {
        getline(in,s.name);
        cout << s.name << endl;
    }
    }
    return 0;
}
