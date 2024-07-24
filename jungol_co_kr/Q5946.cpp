#include <stdio.h>

int main()
{
	int height;
	scanf("%d", &height);
	if(height < 0 || height>50 || height%2 == 0)
	{
		printf("INPUT ERROR!\n");
		return 0;
	}
	
	for(int y=0; y<height; y++)
	{
		for(int i=0; i<y; i++)
		{
			printf("  ");
		}
		for(int i=(height*2)-2*y - 1; i>0; i--)
		{
			printf("%d ", y);
		}
		
		printf("\n");
	}
	
	return 0;
}
