#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int j = 1; j < n; j++)
	{
		//find minimum
		for (int i = j; i > 0; i--)
		{
			if (arr[i] < arr[i-1])
				swap(arr[i], arr[i-1]);
			else
				break;
		}
		
		//print
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	return 0;
}