#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <memory.h>
using namespace std;

struct Path{
	int a;
	int b;
	int v;
	int AMin = INT_MAX;
	int BMin = INT_MAX;
};

Path path[100000];
vector<Path*> Npath[100001];
int N, A, B;

bool visit[100001];
void findA(int idx, int sum)
{
	visit[idx] = true;
	for (auto& e : Npath[idx]) {
		e->AMin = min(e->AMin, sum);
		if (e->a == idx) {
			if(!visit[e->b])
				findA(e->b, sum + e->v);
		}
		else {
			if(!visit[e->a])
				findA(e->a, sum + e->v);
		}
	}
}
void findB(int idx, int sum)
{
	visit[idx] = true;
	for (auto& e : Npath[idx]) {
		e->BMin = min(e->BMin, sum);
		if (e->a == idx) {
			if(!visit[e->b])
				findB(e->b, sum + e->v);
		}
		else {
			if (!visit[e->a])
				findB(e->a, sum + e->v);
		}
	}
}

int main()
{
	cin >> N >> A >> B;
	for (int i = 1; i < N; i++) {
		scanf("%d %d %d", &path[i].a, &path[i].b, &path[i].v);
		Npath[path[i].a].push_back(&path[i]);
		Npath[path[i].b].push_back(&path[i]);
	}
	//A에서 출발
	memset(visit, 0, sizeof(visit));
	findA(A, 0);
	//B에서 출발
	memset(visit, 0, sizeof(visit));
	findB(B, 0);

	int result = INT_MAX;
	for (int i = 1; i < N; i++) {
		result = min(path[i].AMin + path[i].BMin, result);
	}

	printf("%d", N==1? 0 : result);
}