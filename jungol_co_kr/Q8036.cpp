#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> xMap;
	map<int, int> yMap;

	int n, x, y;
	cin >> n;
	while (n--)
	{
		cin >> y >> x;
		yMap[y]++;
		xMap[x]++;
	}

	//가로선 확인
	long long count = 0;
	for (auto dot : xMap)
	{
		long long dotCount = dot.second;
		if (dotCount >= 2) {
			count += dotCount * (dotCount - 1) * 0.5;
		}
	}
	for (auto dot : yMap)
	{
		long long dotCount = dot.second;
		if (dotCount >= 2) {
			count += dotCount * (dotCount - 1) * 0.5;
		}
	}
	cout << count;

	return 0;
}