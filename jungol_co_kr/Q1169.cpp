#include <iostream>
#include <vector>

using namespace std;

void func(vector<int> arr, int depth)
{
	if (depth == 0)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
		return;
	}


	for (int i = 1; i <= 6; i++)
	{
		arr.push_back(i);
		func(arr, depth - 1);
		arr.pop_back();
	}
}
void func2(vector<int> arr, int stt, int depth)
{
	if (depth == 0)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
		return;
	}


	for (int i = stt; i <= 6; i++)
	{
		arr.push_back(i);
		func2(arr, i, depth - 1);
		arr.pop_back();
	}
}

bool checkDuplicate(vector<int> arr, int a)
{
	for (int i : arr)
		if (a == i)
			return true;
	return false;
}

void func3(vector<int> arr, int depth)
{
	if (depth == 0)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
		return;
	}


	for (int i = 1; i <= 6; i++)
	{
		if (!checkDuplicate(arr, i))
		{
			arr.push_back(i);
			func3(arr, depth - 1);
			arr.pop_back();
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> arr;

	if(M == 1)
		func(arr, N);
	else if (M == 2)
		func2(arr, 1, N);
	else
		func3(arr, N);
}