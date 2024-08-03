#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main()
{
	map<string, int> stringMap;
	int n;
	cin >> n;
	while (n--)
	{
		stringMap.clear();
		int m;
		cin >> m;
		while (m--)
		{
			string accessory, category;
			cin >> accessory >> category;
			if (stringMap.find(category) == stringMap.end())
				stringMap[category] = 1;
			else
				stringMap[category]++;
		}

		//print
		int result = 1;
		for (auto it = stringMap.begin() ; it != stringMap.end(); it++)
		{
			result *= ((*it).second+1);
		}
		cout << result - 1 << endl;
	}

	return 0;
}