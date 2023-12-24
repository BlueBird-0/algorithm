//https://www.acmicpc.net/problem/1260
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

int N, M, V;
bool dfsMap[1001][1001];
bool bfsMap[1001][1001];
std::queue<int> bfsQ;

void DFS(int dest) {
	printf("%d ", dest);
	for (int i = 0; i <= N; i++) {
		dfsMap[i][dest] = false;
	}
	for (int i=0; i<= N; i++)
	{
		if (dfsMap[dest][i])
			DFS(i);
	}
}


void BFS(int dest) {
	printf("%d ", dest);

	for (int i=0; i<=N; i++)
	{
		if (bfsMap[dest][i])
		{
			bfsQ.push(i);
			for (int j = 0; j <= N; j++)
			{
				bfsMap[j][i] = false;
			}
		}
	}

	while (!bfsQ.empty())
	{
		int next = bfsQ.front();
		bfsQ.pop();
		BFS(next);
	}
}

int Q1260() {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		dfsMap[p1][p2] = dfsMap[p2][p1] = true;
		bfsMap[p1][p2] = bfsMap[p2][p1] = true;
	}

	std::vector<int> path;

	//DFS
	DFS(V);


	//BSF
	printf("\n");
	for (int i = 0; i <= N; i++)
	{
		bfsMap[i][V] = false;
	}
	BFS(V);
	return 0;
}
