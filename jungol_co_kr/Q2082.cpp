#include <iostream>
using namespace std;
int max_heap[500001] = { 0, };
int heapSize = 0;

void insertHeap(int &temp)
{
	int now = heapSize + 1;	//root
	max_heap[now] = temp;
	while (now > 1) {
		if (max_heap[now / 2] <= max_heap[now]) {
			swap(max_heap[now / 2], max_heap[now]);
			now = now / 2;
		}
		else {
			break;
		}
	}

	heapSize++;
}

void sortHeap() 
{
	int lastIdx = heapSize;
	while (lastIdx > 1) {
		swap(max_heap[lastIdx], max_heap[1]);
		
		int now = 1;
		while (1) {
			if (now * 2+1 >= lastIdx)
				break;
			int* left = &max_heap[now * 2 + 0];
			int* right = &max_heap[now * 2 + 1];

			if (* left > *right && *left>max_heap[now]) {
				swap(max_heap[now], *left);
				now = now * 2 + 0;
			}
			else if(*right > max_heap[now]){
				swap(max_heap[now], *right);
				now = now * 2 + 1;
			}
			else {
				break;
			}

		}
		lastIdx--;
	}
}

int main()
{
	int N;
	cin >> N;
	int newTemp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &newTemp);
		
		insertHeap(newTemp);
	}
	for (int i = 1; i <= N; i++) {
		printf("%-2d", max_heap[i]);
	}
	printf("\n");
	sortHeap();
	for (int i = 1; i <= N; i++) {
		printf("%-2d", max_heap[i]);
	}


	return 0;
}