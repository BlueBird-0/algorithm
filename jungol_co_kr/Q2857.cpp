#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[5];
	int maxLength = 0;
	for(int i=0; i<5; i++)
	{
		cin >> str[i];
		maxLength = max((int)str[i].length(), maxLength);
	}
	
	for(int x=0; x<maxLength; x++)
	{
		for(int y=0; y<5; y++)
		{
			if(x < str[y].length())	
			{
				cout<< str[y][x];
			}
		}
	}
	
	
	return 0;
}
