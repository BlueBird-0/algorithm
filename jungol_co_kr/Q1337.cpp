#include <stdio.h>
#include <memory.h>
int arr[100][100] = {0,};	
int n;
int x=0, y=0;
int num=0;

int increaseNum()
{
	if(num+1 == 10)
		num = 0;
	else 
		num++;
	return num;
}

void fillRight()
{
	while(1)
	{
		if(x+1 >= n || arr[y][x+1] != -1)
			break;
		x++;
		arr[y][x] = increaseNum();
	}
	return;
}

void fillRightDown()
{
	while(1)
	{
		if(x+1 >= n || y+1 >= n || arr[y+1][x+1] != -1)
			break;
		x++;
		y++;
		arr[y][x] = increaseNum();
	}
	return;
}

void fillLeft()
{
	while(1)
	{
		if(x-1 < 0 || arr[y][x-1] != -1)
			break;
		x--;
		arr[y][x] = increaseNum();
	}
	return;
}

void fillUp()
{
	while(1)
	{
		if(y-1 < 0 || arr[y-1][x] != -1)
			break;
		y--;
		arr[y][x] = increaseNum();
	}
	return;
}

void fillDown()
{
	while(1)
	{
		if(y+1 >= n || arr[y+1][x] != -1)
			break;
		y++;
		arr[y][x] = increaseNum();
	}
	return;
}

int checkEnd(){
	if((x+1 >= n || arr[y][x+1] != -1) &&
		(x-1 < 0 || arr[y][x-1] != -1) &&
		(y-1 < 0 || arr[y-1][x] != -1) &&
		(y+1 >= n || arr[y+1][x] != -1))
		return 1;
	return 0;
}

int main()
{
	memset(arr, -1, sizeof(int)*100*100);
	scanf("%d",&n);
	arr[y][x] = num;
	int dir = 4; // 0R 1D 2L 3U 4RD
	
	
	for(int k=0; k<n; k++)
	{
//		if(dir == 0)
//		{
//			fillRight();
//			dir=3;
//		}
//		else if(dir == 1)
//		{
//			fillDown();
//			dir=0;
//		}
		if(dir == 2)
		{
			fillLeft();
			dir=3;
		}
		else if(dir == 3)
		{
			fillUp();
			dir=4;
		}
		else if(dir ==4)
		{
			fillRightDown();
			dir=2;
		}
	}
	
	//Ãâ·ÂºÎ
	for(int y=0;y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			if(arr[y][x] != -1)
				printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	
	return 0;
}
