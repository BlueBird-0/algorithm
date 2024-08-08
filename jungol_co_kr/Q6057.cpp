#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> arr;
	int P, N;
	cin >> P >> N;
	int result = 0;
	while (N--)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			int p, m;
			cin >> p >> m;
			arr.push_back(make_pair(p, m));
		}
		else if (cmd == 1) {
			int p;
			cin >> p;
			for (auto it = arr.begin(); it != arr.end(); it++)
			{
				if (p == (*it).first)
				{
					//cout << "----" << (*it).second << endl;
					result += (*it).second;
					arr.erase(it);
					break;
				}
			}
		}
	}
	cout << result;
}