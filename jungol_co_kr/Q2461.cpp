#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m2d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int m2dSum[14] = {};
pair<int, int> date[100001];

int main()
{
	int sum = 0;
	for (int i = 1; i <= 12; i++) {
		sum += m2d[i-1];
		m2dSum[i] = sum;
	}

	int N;
	cin >> N;
	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		date[i] = make_pair( m2dSum[a] + b , m2dSum[c] + d);
	}

	int sttDate = m2dSum[3] + 1;
	int endDate = m2dSum[11] + 30;

	sort(&date[0], &date[N], [](pair<int, int>& a, pair<int, int>& b)->bool {return a.second > b.second; });

	int result = 0;
	int now = sttDate;
	int maxIdx = N;
	while (1) {
		bool found = false;
		for (int nowIdx = 0; nowIdx < maxIdx; nowIdx++) {
			if (date[nowIdx].first <= now) {
				found = true;
				maxIdx = nowIdx;
				now = date[nowIdx].second;
				result++;
			}
		}

		if (now > endDate || !found)
			break;
	}
	printf("%d", now>endDate? result : 0);

}