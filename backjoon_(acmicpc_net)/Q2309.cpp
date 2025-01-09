#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 9개중 7개의 합이 100
int height[9] = { 0, };
bool checked[9] = { 0, };
vector<int> result;

void find(int sum, int checkedCnt)
{
	if (!result.empty())
		return;
	if (checkedCnt == 7 && sum == 100) {
		for (int i = 0; i < 9; i++) {
			if (checked[i])
				result.push_back(height[i]);
		}
		return;
	}
	if (sum >100 || checkedCnt >= 7) {
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			find(sum + height[i], checkedCnt + 1);
			checked[i] = false;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}
	find(0, 0);
	sort(result.begin(), result.end());
	for (auto e : result)
		printf("%d\n", e);

	return 0;
}