#include <iostream>
#include <vector>
using namespace std;
int K;
vector<int> inputs;
vector<int> arr;

bool checkDuplicate(int n)
{
	for (int a : arr) {
		if (a == n)
			return true;
	}
	return false;
}

void combination(int stt)
{
	if (arr.size() == 6)
	{
		for (int i = 0; i < 6; i++)
			//cout << arr[i] << " ";
			cout << inputs[arr[i]] << " ";
		cout << endl;
		return;
	}

	for (int i = stt; i < K; i++) {
		if (!checkDuplicate(i))
		{
			arr.push_back(i);
			combination(i+1);
			arr.pop_back();
		}
	}
}

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		inputs.push_back(num);
	}
	combination(0);

}