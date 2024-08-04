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

	while (true)
	{
		double n;
		fin >> n;
		fin.ignore();
		if (n == 0)
			break;

		double r = n / 2 / 3.14;
		fout.setf(ios::showpoint);
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << r << endl;
	}

	fin.close();
	fout.close();
	return 0;
}