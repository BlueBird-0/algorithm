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

	int n;
	fin >> n;
	fin.ignore();
	while (n--)
	{
		string str;
		getline(fin, str);
		strs.push_back(str);
	}

	auto it = strs.end()-1;
	for (;;)
	{
		fout << *it << endl;
		if (it == strs.begin())
			break;
		it--;
	}

	fin.close();
	fout.close();
	return 0;
}