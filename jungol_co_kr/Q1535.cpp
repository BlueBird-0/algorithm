#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isExist(vector<string>& strs, string str)
{
	for (string it : strs)
	{
		if (it == str)
			return true;
	}
	return false;
}

vector<string> split(string str)
{
	vector<string> result;
	while (true)
	{
		int find = str.find(" ");
		if (find < 0)
			break;
		result.push_back(str.substr(0, find));
		str.erase(0, find + 1);
	}
	result.push_back(str);
	return result;
}

int main()
{
	vector <string> strs;
	while (true)
	{
		string str;
		std::getline(cin, str);
		if (str == "END")
			break;

		vector<string> words = split(str);
		for (string word : words)
		{
			if (!isExist(strs, word))
			{
				strs.push_back(word);
			}
		}

		//print
		for (auto str : strs)
			cout << str << " ";
		cout << endl;
	}
	return 0;
}
