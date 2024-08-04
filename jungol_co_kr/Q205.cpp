#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	vector<string> strs;

	double a, b;
	fin >> a >> b;

	fout.setf(ios::showpoint);
	fout.setf(ios::fixed);
	fout.precision(2);
	fout << a << " " << b << " " << a + b;

	fin.close();
	fout.close();
	return 0;
}