#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string arr[100];

	for (int i = 0; ; i++)
	{
		int find = 0;
		/*
		for (int j = 0; j<str.length(); j++)
		{
			if (str[j] == ' ')
			{
				find = j;
				break;
			}
		}*/
		find = str.find(" ");	//위 코드와 동일한 기능
		if (find <= 0)
		{
			cout << i + 1 << ". " << str << endl;
			break;
		}
		arr[i] = str.substr(0, find);
		str = str.substr(find+1, str.length());
		cout << i + 1 << ". " << arr[i] << endl;
	}


	return 0;
}