#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt", ios::in);
	if (!fin)
	{
		cout << "오류" << endl;
		return 0;
	}
	ofstream fout("output.txt", ios::out);
	if (!fout)
	{
		cout << "오류2" << endl;
		return 0;
	}

	vector<double> nums;
	for (int i = 0; i < 10; i++)
	{
		double n;
		fin >> n;
		nums.push_back(n);
	}
	fout.setf(ios::showpoint);
	fout.precision(3);
	fout << ((*nums.begin() + *(nums.end() - 1)) / 2) << " ";
	fin.close();
	fout.close();
	return 0;
}