#include <iostream>
#include <string>

using namespace std; 
int main()
{
	while(true)
	{
		string ch;
		cin >> ch;
		
		if((ch>= 'A'&&ch<='Z' || (ch>='a'&&ch<='z'))
		{
			cout<< ch<<endl;
		}
		else if(ch>='0' && ch<='9')
		{
			cout<< (char)ch<<endl;
		}else
		{
			break;
		}
	}
	
	return 0;
}
