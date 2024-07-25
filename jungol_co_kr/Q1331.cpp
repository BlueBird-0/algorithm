#include <iostream>

using namespace std;
int x = 0, y = 0;
char arr[200][200] = { 0, };
char ch = 'A';
char increase()
{
	char result = ch++;
	if (ch > 'Z')
		ch = 'A';
	return result;
}

void leftDown()
{
	x--;
	y++;
	arr[y][x] = increase();
}
void rightDown()
{
	x++;
	y++;
	arr[y][x] = increase();
}
void rightUp()
{
	x++;
	y--;
	arr[y][x] = increase();
}
void leftUp()
{
	x--;
	y--;
	arr[y][x] = increase();
}

int main()
{

	int N;
	cin >> N;

	x = N - 1;
	y = 0;
	arr[y][x] = increase();

	/*
	3 - 3 - 3 - 2
	2 - 2 - 2 - 1
	1 - 1 - 1 - 0
	0 - 0 - 0 - 0
	*/
	for (int i = N-1; i>=1; i--)
	{
		for (int k = 0; k < i; k++)
			leftDown();
		for (int k = 0; k < i; k++)
			rightDown();
		for (int k = 0; k < i; k++)
			rightUp();
		for (int k = 0; k < i-1; k++)
			leftUp();
		x--;
		arr[y][x] = ch++;
	}

	for (int a = 0; a < 2*N; a++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			if (arr[a][x] == 0)
				cout << "  ";
			else	
				cout << arr[a][x] << " ";
		}
		cout << endl;
	}
	return 0;
}