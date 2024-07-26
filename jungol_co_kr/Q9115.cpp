#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	cin >> str;
	
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] >='a' && str[i] <= 'z')
			cout<< (char)(str[i]-('a'-'A'));
		else if(str[i]>='A' && str[i]<='Z')
			cout<< (char)(str[i]+('a'-'A'));
		else
			cout<<str[i];
	}
	return 0;
}
