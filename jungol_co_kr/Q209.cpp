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
	int n, count = 0;
	while (true) {	
		fin >> n;
		if (n == 0)
			break;

		if (check(n)) {
			count++;
			fout << n << " ";
		}
	}
	fout << endl << count;

	fout.close();
	fin.close();
}