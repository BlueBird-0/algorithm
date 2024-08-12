#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<int> A;
	vector<int> B;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());

	int count = 0;
	for (int b : B) {
		bool isExist = binary_search(A.begin(), A.end(), b);
		if (!isExist) {
			printf("%d ", b);
			count++;
		}
	}
	if (count == 0)
		printf("-1");


}