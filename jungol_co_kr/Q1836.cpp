#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	arr.push_back(0);
	
	bool prev_isPositive = true;
	while (n--)
	{
		int num;
		cin >> num;
		if (num >= 0 && prev_isPositive)
		{
			*(arr.end() - 1) += num;
		}
		else if (num >= 0)
		{
			arr.push_back(num);
			prev_isPositive = true;
		}
		else if (num < 0 && !prev_isPositive)
		{
			*(arr.end() - 1) += num;
		}
		else
		{
			arr.push_back(num);
			prev_isPositive = false;
		}
	}

	/*for (int a : arr)
	{
		cout << a << " ";
	}*/
	//최대값 찾기
	int max = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < arr.size(); j++)
		{
			sum += arr[j];
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	cout << max;
}