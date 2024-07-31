#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector< std::pair<string, int> > stringV;
void insert(string str)
{
	vector<pair<string, int> >::iterator it = stringV.begin();

	while (true)
	{
		if (it != stringV.end() && str > it[0].first)
		{
			it++;
			continue;
		}

		if (it != stringV.end() && it[0].first == str)
		{
			it[0].second++;
			break;
		}
		else {
			stringV.insert(it, std::make_pair(str, 1));
			break;
		}
	}
}

int main()
{
	string str;
	getline(cin, str);

	while (true)
	{
		int index = str.find(" ");
		if (index == -1)
		{
			insert(str);
			break;
		}
		string word = str.substr(0, index);
		insert(word);
		str.erase(0, index + 1);
	}

	//Ãâ·ÂºÎ
	for (int i = 0; i < stringV.size(); i++)
	{
		cout << stringV[i].first << endl;
	}

	return 0;
}
