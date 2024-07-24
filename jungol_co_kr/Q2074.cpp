#include <iostream>

using namespace	std;
int x = 0, y = 0;
int num = 0;

int arr[100][100] = { 0, };
int n;

void fill()
{
	arr[y][x] = num + 1;
	num++;
}
void move()
{
	if (num % n == 0)
	{
		y++;
		if (y > n - 1)
			y = 0;
	}
	else
	{
		x--;
		y--;
		if (x < 0)
			x = n - 1;
		if (y < 0)
			y = n - 1;
	}
}

int main()
{
	cin >> n;
	x = n / 2;
	for (int i = 0; i < n*n; i++)
	{
		fill();
		move();
	}
	//Ãâ·ÂºÎ
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}