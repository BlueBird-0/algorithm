#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	for (int i = 0; i<str.length(); i++)
	{
		char ch = str[i];
		if (ch >= 'A' && ch <= 'Z')
			cout << (char)(ch + ('a' - 'A'));
		if (ch >= 'a' && ch <= 'z')
			cout << ch;
		if (ch >= '0' && ch <= '9')
			cout << ch;
	}
	return 0;
}