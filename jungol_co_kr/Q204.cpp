#include <iostream>
//#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];


	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i<n; i++)
	{
		cin >> *(arr + i);
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	cout << "max : " << max << endl;
	cout << "min : " << min << endl;
	return 0;
}