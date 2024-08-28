#include <iostream>

using namespace std;
int arr[1000001] = { 0, };
int mArr[1000001] = { 0, };
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &mArr[i]);
	}

	int mCount = M;
	int time = 0;
	while (mCount)
	{
		for (int i = 1; i <= M; i++)
		{
			bool exit = true;
			if (mArr[i] != 0)
			{
				exit = false;
				int left = max(mArr[i] - time, 1);
				int right = min(mArr[i] + time, N);

				bool fill_L = arr[left] != 0;
				if (!fill_L) {
					arr[left] = time + 1;
				}
				bool fill_R = arr[right] != 0;
				if (!fill_R) {
					arr[right] = time + 1;
				}
				if (fill_L && fill_R)
				{
					mArr[i] = 0;
					mCount--;
				}
				
			}
			if (exit)
				continue;
		}
		time++;
	}
	

	for (int i = 1; i <= N; i++) {
		printf("%d ", arr[i]-1 );
	}
}