#include <stdio.h>
int arr[100][100] = {0,};	
int n;
int x=0, y=0;
int num=1;

void fillRight()
{
	while(1)
	{
		if(x+1 >= n || arr[y][x+1] != 0)
			break;
		x++;
		arr[y][x] = num++;
	}
	return;
}

void fillLeft()
{
	while(1)
	{
		if(x-1 < 0 || arr[y][x-1] != 0)
			break;
		x--;
		arr[y][x] = num++;
	}
	return;
}

void fillUp()
{
	while(1)
	{
		if(y-1 < 0 || arr[y-1][x] != 0)
			break;
		y--;
		arr[y][x] = num++;
	}
	return;
}

void fillDown()
{
	while(1)
	{
		if(y+1 >= n || arr[y+1][x] != 0)
			break;
		y++;
		arr[y][x] = num++;
	}
	return;
}

int checkEnd(){
	if((x+1 >= n || arr[y][x+1] != 0) &&
		(x-1 < 0 || arr[y][x-1] != 0) &&
		(y-1 < 0 || arr[y-1][x] != 0) &&
		(y+1 >= n || arr[y+1][x] != 0))
		return 1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	x = n-1;
	arr[y][x] = num++;
	int dir = 2; // 0R 1D 2L 3U
	while(1)
	{
		if(dir == 0)
		{
			fillRight();
			dir=3;
		}
		else if(dir == 1)
		{
			fillDown();
			dir=0;
		}
		else if(dir == 2)
		{
			fillLeft();
			dir=1;
		}
		else
		{
			fillUp();
			dir=2;
		}
		if(checkEnd())
			break;
	}
	
	//Ãâ·ÂºÎ
	for(int y=0;y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			printf("%d ", arr[y][x]); 
		}
		printf("\n");
	}
	
	return 0;
}
