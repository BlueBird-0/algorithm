#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		string front = str.substr(0, 1);
		string temp = str.substr(1, str.length());
		str = temp + front;
		cout << str << endl;
	}

	
	
	return 0;
}