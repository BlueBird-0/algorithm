#include <iostream>
#include <vector>

using namespace std;

int arr[40] = {0,};
int N, M;
void func(int sum, int depth, int target)
{
	if (sum > target)
		return;
	if (depth == N)
	{
		if (sum == target)
		{
			for (int i=0; i<N; i++)
				cout << arr[i] << " ";
			cout << endl;
		}

		return;
	}


	for (int i = 1; i <= 6; i++)
	{
		arr[depth] = i;
		func(sum + i, depth + 1, target);
	}
}

int main()
{
	cin >> N >> M;
	vector<int> arr;

	func(0, 0, M);
}