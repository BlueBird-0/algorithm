#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int _div(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");


	int a, b;
	char ch;
	fin >> a >> b >> ch;

	int (*function)(int, int) = NULL;
	if (ch == '+')
		function = add;
	else if (ch == '-')
		function = sub;
	else if (ch == '*')
		function = mul;
	else if (ch == '/')
		function = _div;
	else if (ch == '%')
		function = mod;


	fout << a << " " << ch << " " << b << " = " << function(a, b);
	fin.close();
	fout.close();
	return 0;
}