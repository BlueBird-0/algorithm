#include <iostream>
#include <vector>
#include <memory.h>
int cnt[6];
int v[6] = { 500,100,50,10,5,1 };
using namespace std;
int checkCnt[6] = { 0, };

int maxV = 0;
int maxArr[6] = {0,};

bool findaMax = false;
void greedy(int w, int idx)
{
	if (w < 0)
		return;
	if (w == 0) {
		int sum = 0;
		for (int i = 0; i < 6; i++)
			sum += checkCnt[i];
		if (sum > maxV) {
			maxV = sum;
			memcpy(maxArr, checkCnt, sizeof(int) * 6); 
			findaMax = true;
		}
		return;
	}
		
	for (int i = idx; i < 6 && findaMax==false; i++) {
		if (w - v[i] >= 0 && cnt[i]- checkCnt[i]>0) {
			checkCnt[i]++;
			greedy(w - v[i], idx);
			checkCnt[i]++;
		}
	}
}

int main()
{
	int W;
	cin >> W;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &cnt[i]);
	}

	int maxW = 0;
	for (int i = 0; i < 6; i++)
	{
		maxW += cnt[i] * v[i];
	}

	int diff = maxW - W;
	greedy(diff, 0);

	int result = 0; 
	for (int i = 0; i < 6; i++)
	{
		result += cnt[i] - maxArr[i];
	}
	printf("%d\n", result);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", cnt[i] - maxArr[i]);
	}
}