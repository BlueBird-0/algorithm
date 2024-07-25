#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	cin>>str;
	
	char priv =  str[0]=='(' ? '(' : ')';	//1(, 2)
	int height = 10;
	
	for(int i=1; ; i++)
	{
		if(str[i] == '\0')
			break;
		if (str[i] == priv)
			height+= 5;
		else
		{
			height+= 10;
			priv = str[i];
		}
	}
	
	cout << height;
	
	return 0;
}
