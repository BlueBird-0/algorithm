#include <iostream>
#include <vector>
using namespace std;
bool has(vector<int> &arr, int x)
{
	for (auto num : arr)
	{
		if (num == x) {
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> arr;
	int N, P;
	cin >> N >> P;

	int x = N;

	while (true)
	{
		x = x * N % P;
		if (has(arr, x))
			break;
		arr.push_back(x);
	}


	if (*(arr.end() - 1) == 0)
		cout << 1;
	else
		cout << arr.size();
}