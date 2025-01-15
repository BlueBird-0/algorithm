#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

bool graph[1001][1001] = { 0, };
bool visited[1001] = { 0, };

void DFS(int point, int n)
{
	if (!visited[point]) {
		visited[point] = true;
		printf("%d ", point);
	}

	for (int i = 1; i <= n; i++) {
		if (graph[point][i] && !visited[i]) {
			DFS(i, n);
		}
	}
}

void BFS(int point, int n) {
	queue<int> stt;
	stt.push(point);
	while (!stt.empty()) {
		int current = stt.front();
		stt.pop();

		if (!visited[current]) {
			visited[current] = true;
			printf("%d ", current);
		}
		for (int i = 1; i <= n; i++) {
			if (graph[current][i] && !visited[i]) {
				stt.push(i);
			}
		}
	}
}

int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
		graph[b][a] = true;
	}

	DFS(v, n);
	memset(visited, 0, sizeof(bool)*(n+1));
	printf("\n");
	BFS(v, n);
}