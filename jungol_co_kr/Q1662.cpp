#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, bool> arr;

int n;
int maxResult = 0;
int result=0;

vector<int> getList(int num) {
	vector<int> list;
	list.push_back(num);
	int y = num / n;
	int x = num % n;

	for (int xx = x-1, yy = y-1; xx >= 0 && yy >= 0; xx -= 1, yy -= 1) {
		if (arr[yy*n+xx])
			list.push_back(yy * n + xx);
	}
	for (int xx = x+1, yy = y+1; xx < n && yy < n; xx += 1, yy += 1) {
		if (arr[yy * n + xx])
			list.push_back(yy * n + xx);
	}
	for (int xx = x+1, yy = y-1; xx < n && yy >= 0; xx += 1, yy -= 1) {
		if (arr[yy * n + xx])
			list.push_back(yy * n + xx);
	}
	for (int xx = x-1, yy = y+1; xx >= 0 && yy < n; xx -= 1, yy += 1) {
		if (arr[yy * n + xx])
			list.push_back(yy * n + xx);
	}

	return list;
}

void check()
{
	if (arr.size() == 0) {
		maxResult = max(result, maxResult);
	}
	for (auto e : arr) {
		result++;
		vector<int> eraseList = getList(e.first);
		for (auto e : eraseList)
			arr.erase(e);
		check();
		for (auto e : eraseList)
			arr[e] = true;
		result--;
	}
}

int main()
{
	int temp;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &temp);
			if(temp)
				arr[y * n + x] = true;
		}
	}

	check();
	printf("%d", maxResult);
}