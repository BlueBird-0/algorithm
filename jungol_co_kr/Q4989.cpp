#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	int n, num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (m.find(num) != m.end())
			m[num]++;
		else
			m[num] = 1;
	}

	for (auto [key, value] : m) {
		printf("%d : %d\n", key, value);
	}

	return 0;
}