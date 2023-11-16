#include<iostream>
using namespace std;

float area_func(int radius){
    int area;
    area = 3.14*(radius*radius);
    return area;
}

int main() {
    int radius;
    cout << "Please enter radius of the circle: ";
    cin >> radius;
    cout << area_func(radius) << endl;
}