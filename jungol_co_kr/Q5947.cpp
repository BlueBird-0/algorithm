#include <stdio.h>

int main()
{
	int arr[50][50] = {0,};
	int height;
	scanf("%d", &height);
	if(height < 0 || height>50 || height%2 == 0)
	{
		printf("INPUT ERROR!\n");
		return 0;
	}
	
	int i=height;
	int x = 0;
	while(i>0)
	{
		for(int a=x; a<x+i; a++)
		{
			arr[a][x]= x+1;
		}
		i-=2;
		x++;
	}
	
	//Ãâ·ÂºÎ 
	for(int a=0; a<height; a++)
	{
		for(int b=0; b<height; b++)
		{
			if(arr[a][b] != 0)
				printf("%d ", arr[a][b]);
		}
		printf("\n");
	}
	
	return 0;
}
