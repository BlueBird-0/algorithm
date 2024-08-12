#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> trees;
	int height;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &height);
		trees.push_back(height);
	}
	sort(trees.begin(), trees.end());
	reverse(trees.begin(), trees.end());
	
	int increase = 0;
	int index = 0;
	int sum = 0;
	for (int i = trees[0]; i > 0; i--)
	{
		while (true) {
			if (trees[index] >= i) {
				increase++;
				index++;
			}
			else
				break;
		}
		sum += increase;
		if (sum >= M) {
			printf("%d", i-1);
			break;
		}
	}
}