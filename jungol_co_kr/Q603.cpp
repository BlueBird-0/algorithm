#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> arr;
	string str;
	getline(cin, str);
	while (true)
	{
		int find = str.find(" ");
		if (find < 0)
		{
			arr.push_back(str);
			break;
		}
		arr.push_back(str.substr(0, find));
		str.erase(0, find + 1);
	}

	int i = 0;
	for (string str : arr) {
		if (i % 2 == 0)
			cout << str << endl;
		i++;
	}

}