#include <iostream>
#include <string>

using namespace std;

int main()
{
	double arr[5];
	double *ptr = arr;
	for (int i = 0; i<sizeof(arr) / sizeof(double); i++)
	{
		cin >> *(ptr + i);
	}
	for (int i = 0; i<sizeof(arr) / sizeof(double); i++)
	{
		printf("%.1lf ", *(ptr + i));
	}

	return 0;
}