#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i+1;
	}

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int choice;
		scanf("%d", &choice);

		for (int k = 0; k < choice; k++)
		{
			swap(&arr[i-k], &arr[i-k-1]);
		}
	}


	//Ãâ·ÂºÎ
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}