#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CostCount {
public :
	int cost;
};
int main()
{
	int N, S;
	cin >> N >> S;
	vector<int> cost;
	int buyCount = 0;
	long long result = 0;
	for (int week = 1; week <= N; week++)
	{
		int c;
		cin >> c >> buyCount;
		cost.push_back(c);

		sort(cost.begin(), cost.end());
		if(cost.size() >= 2)
			cost.pop_back();

		result += cost[0] * buyCount;

		for (auto& temp : cost)
			temp += S;
	}
	cout << result;


}