#include <iostream>
#include <fstream>
using namespace std;

bool check(int n)
{
	return n % 3 == 0 && n % 5 == 0;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;

	for (int line = 1; line <= n; line++)
	{
		for (int i = n - line; i > 0; i--)
		{
			fout << "  ";
		}
		for (int i = 1; i <= line * 2 - 1; i++)
		{
			fout << "* ";
		}
		fout << endl;
	}
	for (int line = n - 1; line >= 1; line--)
	{
		for (int i = n - line; i > 0; i--)
		{
			fout << "  ";
		}
		for (int i = 1; i <= line * 2 - 1; i++)
		{
			fout << "* ";
		}
		fout << endl;
	}

	fout.close();
	fin.close();
}