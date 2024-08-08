#include <iostream>
#include <memory>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	int* arr = new int[n+1] {};
	memset(arr, 2147483647, sizeof(int) * n + 1);
	int arrCount = 0;

	int moveCount = 0;
	while(n--)
	{
		int num;
		cin >> num;
		//find insertPosition
		int index = 0;
		while (true)
		{
			if (index < arrCount && num > arr[index])
				index++;
			else
				break;
		}
		//insert
		for (int i = arrCount; i > index; i--)
		{
			arr[i] = arr[i - 1];
			moveCount++;
		}
		arr[index] = num;
		arrCount++;
	}
	cout << moveCount;
	delete[] arr;
}