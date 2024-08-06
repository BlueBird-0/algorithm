#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	//문자 변경
	int last = str.length() -1;
	for (int i = 0; i < last; i++)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			str.replace(i, 2, "*");
			last--;
		}
	}
	cout << str;
	
	int n = 0;
	char ch;
	char prevCh= ' ';
	int depth = 0;
	int result = 0;

	while (n < str.length())
	{
		ch = str[n];
		if (ch == '*')
		{
			result += depth;
		}
		if (ch =='(')
		{
			depth++;
		}
		else if (ch == ')') {
			result += 1;
			depth--;
		}
		prevCh = ch;
		n++;
	}
	cout << result;
	return 0;
}