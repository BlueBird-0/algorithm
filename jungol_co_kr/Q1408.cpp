#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>> arr;
int dp[501] = { 0, };

int main()
{
	int src, dst, yMax = 0, xMax = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &src, &dst);
		arr.push_back(make_pair(src, dst));
	}
	sort(arr.begin(), arr.end());
	//LIS (최장 증가 부분 수열)
	int LIS = 0;
	dp[0] = 1;
	for (int i = 0; i < arr.size(); i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if(arr[i].second > arr[j].second)
				m = max(dp[j], m);
		}
		dp[i] = m + 1;
		LIS = max(dp[i], LIS);
	}

	printf("%d", arr.size()-LIS);

	return 0;
}