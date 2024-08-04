#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	string str1, str2;
	getline(fin, str1);
	getline(fin, str2);
	fout << (str1.length() < str2.length() ? str1 : str2) << endl;
	fout << (str1.length() < str2.length() ? str2 : str1) << endl;

	fin.close();
	fout.close();
	return 0;
}