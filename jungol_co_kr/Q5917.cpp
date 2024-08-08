#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> one, two, three;
	int N, T;
	cin >> N >> T;
	for (int i = N; i > 0; i--)
		one.push_back(i);
	while (T--)
	{
		int C, D;
		cin >> C >> D;
		while (D--)
		{
			if (C == 1)
			{
				if (one.size() == 0)
					break;
				two.push_back(*(one.end() - 1));
				one.pop_back();
			}
			else if (C == 2)
			{
				if (two.size() == 0)
					break;
				three.push_back(*(two.end() - 1));
				two.pop_back();
			}
		}
	}
	//print
	for (int i=three.size()-1; i>=0; i--)
	{
		cout << three[i] << endl;
	}
}