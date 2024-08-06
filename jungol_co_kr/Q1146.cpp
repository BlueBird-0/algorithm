#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	for (int j = 0; j < n-1; j++)
	{
		//find minimum
		int mI = j;
		for (int i = j+1; i < n; i++)
		{
			if (arr[i] < arr[mI])
				mI = i;
		}
		swap(arr[j], arr[mI]);
		//print
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	

	return 0;
}