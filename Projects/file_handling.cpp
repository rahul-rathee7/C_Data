#include<iostream>
#include<fstream>
using namespace std;

int main() {
    //open a file in write mode
    char data[100];
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "writing to the file" << endl;
    cout << "Enter you name: ";
    cin.getline(data,100);
    
    //write inputted data into the file 

    outfile << data << endl;

    cout << "Enter your age:";
    cin >> data;
    cin.ignore();

    //again write inputted data into the file 
    outfile << data << endl;

    //close the opened file
    outfile.close();

    //open a file in read mode
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file " << endl;
    infile >> data;

    //write the data at the screen
    cout << data << endl;

    //again read the data from the file and display it.
    infile >> data;
    cout << data << endl;
}