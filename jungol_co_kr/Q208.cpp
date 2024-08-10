#include <iostream>
#include <fstream>
using namespace std;

int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	ifstream fin("input.txt");
	int n;
	fin >> n;

	ofstream fout("output.txt");
	fout << factorial(n);
	
	fout.close();
	fin.close();
}