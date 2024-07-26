#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	cin>>str;
	
	for(int i=0; i<str.length(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			cout<<(char)(str.at(i) -('a'-'A'));
		else if(str[i]>='A' && str[i]<='Z')
			cout<<str.at(i);
	}
	
	return 0;
}
