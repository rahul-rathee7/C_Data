#include<iostream>


int* fun(){
static int x = 5;
return &x;
}

int main() {
	int* p = fun();
	fflush(stdin);
	std::cout << *p;
	return 0;
}
