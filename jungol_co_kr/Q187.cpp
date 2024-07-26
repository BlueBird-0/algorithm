#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;

	while (true)
	{
		int i;
		cin >> i;
		
		if (i >= str.length())
		{
			str.erase(str.length()-1);
		}
		else {
			string templeft = str.substr(0, i-1);
			string tempright = str.substr(i, str.length());
			str = templeft + tempright;
		}

		cout << str << endl;
		if (str.length() == 1)
			break;
	}
	return 0;
}