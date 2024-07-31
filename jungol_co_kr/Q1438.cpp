#include <iostream>

using namespace std;

void fill(bool map[100][100], int x, int y)
{
	for(int j=y; j<y+10 || j<100; j++)
	{
		for(int i=x; i<x+10 || x<100; i++)
		{
			map[j][i] = true;
		}
	}
	
}

int main()
{
	bool map[100][100] = {0,};

	int paper;
	cin >> paper;
	for(int i=0; i<paper; i++)
	{
		int x, y;
		cin >> x >> y;
		
		fill(map, x, y);
	}
	
	//Ãâ·ÂºÎ
	int count = 0;
	for(int y=0; y<100; y++)
	{
		for(int x=0; x<100; x++)
		{
			if(map[y][x] == true)
				count++;
		}
	}
	cout<<count;
	return 0; 
}
