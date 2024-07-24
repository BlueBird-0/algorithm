#include <iostream>
#include <memory.h>

using namespace std;
int arr[30][30] = { 0, };
int n, m;

void print1()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] != 0)
				cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

void print2()
{
	for (int y = n-1; y >= 0; y--)
	{
		for (int x = 0; x < n-y-1; x++)
		{
			cout << " ";
		}

		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] != 0)
				cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

void print3()
{
	for (int x = n - 1; x >= 0; x--)
	{
		for (int y = n-1; y >= x; y--)
		{
			if (arr[y][x] != 0)
				cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n >> m;

	//make pascal
	for (int y = 0; y < n; y++)
	{
		arr[y][0] = 1;
		for (int x = 1; x <= y; x++)
		{
			arr[y][x] = arr[y-1][x-1] + arr[y-1][x];
		}
	}


	//Ãâ·ÂºÎ
	if (m == 1)
		print1();
	else if (m == 2)
		print2();
	else
		print3();

	return 0;
}