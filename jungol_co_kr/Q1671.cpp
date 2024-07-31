#include <iostream>

using namespace std;

void fill(bool map[102][102], int x, int y)
{
	for(int j=y; j<y+10 && j<101; j++)
	{
		for(int i=x; i<x+10 && x<101; i++)
		{
			map[j][i] = true;
		}
	}
	
}

int main()
{
	bool map[102][102] = {0,};

	int paper;
	cin >> paper;
	for(int i=0; i<paper; i++)
	{
		int x, y;
		cin >> x >> y;
		
		fill(map, x+1, y+1);
	}
	
	//°è»ê
	int length = 0;
	for(int y=0; y<101; y++)
	{
		for(int x=0; x<101; x++)
		{
			if(map[y][x] != map[y][x+1])
				length++;
			if(map[y][x] != map[y+1][x])
				length++;
		}
	}
	cout<<length;
	return 0; 
}
