	#include <iostream>

	using namespace std;
	long long sumX[1001] = { 0, };
	long long sumYX[1001][1001] = { 0, };

	long long map[1001][1001] = { 0, };

	int main()
	{
		cin.tie(NULL);
		int N, sum, M;
		cin >> N;
		for (int y = 1; y <= N; y++) {
			sum = 0;
			for (int x = 1; x <= N; x++) {
				scanf("%lld", &map[y][x]);
				sum += map[y][x];
				sumX[x] = sum;

				sumYX[y][x] = sumYX[y - 1][x] + sumX[x - 1] + map[y][x];
			}
		}
		cin >> M;
		int x1, y1, x2, y2;
		for (int i = 0; i < M; i++) {
			cin >> y1 >> x1 >> y2 >> x2;
			//scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		
			printf("%lld\n", sumYX[y2][x2] - sumYX[y2][x1-1] - sumYX[y1-1][x2] + sumYX[y1-1][x1-1]);
		}
	}