#include <iostream>
#include <memory.h>

using namespace std;
int x = 0, y = 0;
int num = 0;
int arr[100][100];
int increse()
{
	if (num + 1 == 10)
		num = 0;
	else
		num++;
	return num;
}

void moveDown()
{
	y++;
	arr[y][x] = increse();
}
void moveRight()
{
	x++;
	arr[y][x] = increse();
}
void moveLeftUp()
{
	x--;
	y--;
	arr[y][x] = increse();
}

int main()
{
	memset(arr, -1, sizeof(int)*100*100);
	int N;
	cin >> N;

	arr[y][x] = 0;

	//처음 내리기
	for (int i = 0; i < N-1; i++)
	{
		moveDown();
	}

	int dir = 1;	//0 Down, 1Right, 2LeftUP
	for (int i = 0; i < N; i++)
	{
		
		for (int count = i; count < N-1; count++)
		{
			if (dir %3 == 0)
				moveDown();
			else if (dir %3 == 1)
				moveRight();
			else
				moveLeftUp();
		}
		dir++;
	}

	//출력부 
	for (int y = 0; y < N; y++)
	{
		for (int x = N - 1; x > y; x--)
		{
			cout << " ";
		}

		for (int x = 0; x < N; x++)
		{
			if(arr[y][x] != -1)
				cout << arr[y][x] << " ";
		}
		cout << endl;
	}
	
	return 0;
}