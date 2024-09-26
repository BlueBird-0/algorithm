#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[13] = { 0, };
int arrSize;
bool check[13] = { 0, };

bool maxCheck[13] = {0,};
int maxCount = 0;

void combi(int target, int sum , int count, int stt)
{
	if (sum > target)
		return;
	if (sum == target) {
		//출력
		for (int i = 0; i < arrSize; i++) {
			printf("%3d", check[i] ? arr[i] : 0 );
		}
		printf("   count: %d\n", count);

		if (count > maxCount) {
			maxCount = count;
			memcpy(maxCheck, check, sizeof(bool) * 13);
		}
		return;
	}

	for (int i = stt; i < arrSize; i++) {
		check[i] = true;
		combi(target, sum + arr[i], count + 1, i+1);
		check[i] = false;
	}
}

int solution(int N, int capacity, vector<int> files)
{
	int result = 0;
	//불필요한 파일 제거
	int i = 0;
	for (auto e : files) {
		if (e <= capacity)
			arr[i++] = e;
	}
	arrSize = i;
	sort(arr, &arr[arrSize]);

	for (int HDD = 0; HDD < N; HDD++) {
		maxCount = 0;
		memset(maxCheck, 0, sizeof(bool) * 13);
		//제일 많이 들어가는 조합 찾기
		for (i = capacity; i >= 0; i--) {
			combi(i, 0, 0, 0);
		}
		//해당 파일 삭제
		result += maxCount;
		int pos = 0;
		for (int i = 0; i < 13; i++)
		{
			if (maxCheck[i] == false) {
				arr[pos] = arr[i];
				pos++;
			}
		}
		for (; pos < 13; pos++) {
			arr[pos] = 0;
		}

		printf("------------\n");
	}

	return result; 
}

int main() {
	int N = 3;
	int capacity = 8;
	vector<int> files = { 1,6,1,2,2,3,4,2,8 };
	printf("%d", solution(N,capacity,files));


	return 0;
}