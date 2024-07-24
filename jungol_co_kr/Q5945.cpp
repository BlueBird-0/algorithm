#include <stdio.h>

int main()
{
	int arr[50][50] = {0,};
	int n;
	scanf("%d", &n);
	if(n < 0 || n>50 || n%2 == 0)
	{
		printf("INPUT ERROR!");
		return 0;
	}
	
	// [0,0]
	
	// [1,1]
	// [1,0]
	
	// [2,0]
	// [2,1]
	// [2,2]
	
	// [3,3]
	// [3,2]
	// [3,1]
	// [3,0]
	
	// [4,0]
	// [4,1]
	// [4,2]
	// [4,3]
	// [4,4]
	int num = 1;
	
	for(int y=0; y<n; y++)
	{
		if(y%2 == 0)
		{
			for(int i=0; i<=y; i++)
			{
				arr[y][i] = num++;
			}
		}else
		{
			for(int i=y; i>=0; i--)
			{
				arr[y][i] = num++;
			}
		}
	}
	
	//Ãâ·ÂºÎ
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			if(arr[y][x] != 0)
			{
				printf("%d ", arr[y][x]);	
			}
		}
		printf("\n");
	}
	
	return 0;
}
