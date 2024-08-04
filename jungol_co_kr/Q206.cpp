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

	int a, b, c;
	fin >> a >> b >> c;

	int sum = a + b + c;
	fout << sum << " " << (int)(sum / 3) << "..." << sum % 3;
	fin.close();
	fout.close();
	return 0;
}