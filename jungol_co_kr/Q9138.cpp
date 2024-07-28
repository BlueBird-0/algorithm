#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int *p = &a;
	cout << "a = " << a << ", &a = " << &a << endl;
	cout << "*p = " << *p << ", p = " << p << endl;

	return 0;
}