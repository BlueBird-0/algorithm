#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int *ptr = (int *)malloc(sizeof(int));

	for(int i=0; i<n; i++)
	{
		cin >> *(ptr + i);
	}

	for (int i = n-1; i>=0; i--)
	{
		printf("%d ", *(ptr + i));
	}

	return 0;
}