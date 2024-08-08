#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> arr;
vector<int> search;
bool sameFind = false;
bool findExit = false;

bool checkSame()
{
	for (int i = 0; i < K; i++)
	{
		if (arr[i] != search[i])
			return false;
	}
	sameFind = true;
	return true;
}

void combi(int stt)
{
	if (findExit)
		return;

	if (arr.size() == K)
	{
		if (sameFind)
		{
			for (int num : arr)
			{
				cout << num << " ";
			}
			findExit = true;
			return;
		}
		checkSame();
		return;
	}
		

	for (int i = stt; i <= N; i++)
	{
		arr.push_back(i);
		combi(i + 1);
		arr.pop_back();
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		search.push_back(num);
	}
	combi(1);

	if (!findExit)
		cout << "NONE";
}