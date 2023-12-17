#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

int main() {
    string name;
    int age;
    ofstream o;
    o.open("test.txt");
    ifstream in("test.txt");
    cout << "Enter your name: ";
    cin >> name;
    in >> name;
    cout << "Enter your age: ";
    cin >> age;
    in >> age;
    in.close();
    ofstream out("test.txt", std::ios::app);
    out << " " << name << " " << age << endl;
    out.close();
}