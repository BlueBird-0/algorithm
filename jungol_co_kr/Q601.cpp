#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		string last = str.substr(str.length()-1, str.length());
		string temp = str.substr(0, str.length()-1);
		str = last + temp;
		cout << str << endl;
	}



	return 0;
}