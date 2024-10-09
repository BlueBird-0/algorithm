#include <stdio.h>
//#define DEBUG

const int INF = 99999999;
int N, K, S, D, s, e;
bool visited[1010]; //가장 짧은 해밍 거리를 구해야 하는 것이므로, 한 번 해밍거리 1로 push된 놈을 또 방문하면 안 된다.
char arr[1010][32];
struct P {
	int idx; //마지막 방문지점
	int cnt; //방문 히스토리 개수
	short* hist;
	void operator=(const P& from) {
		idx = from.idx;
		cnt = from.cnt;
		for (int i = 0; i < from.cnt; i++) hist[i] = from.hist[i];
	}
} que[100000], * cur, ans;
void enq(const P& src, int nextidx) {
	visited[nextidx] = true;
	que[e].hist = new short[src.cnt + 2];
	que[e] = src;
	que[e].idx = nextidx;
	que[e].hist[que[e].cnt] = nextidx;
	que[e].cnt++;
#ifdef DEBUG
	printf("ENQ: Idx(%d), Cnt(%d)\n", que[e].idx, que[e].cnt);
	for (int i = 0; i < N; i++) {
		printf("%d ", que[e].hist[i]);
	}
	printf("\n");
#endif
	e++;
}
P& deq() { return que[s++]; }
bool IsHamDist1(int idx1, int idx2) {
	int dist = 0;
	for (int i = 0; i < K; i++) {
		if (arr[idx1][i] != arr[idx2][i]) dist++;
		if (dist > 1) return false;
	}
	return (dist == 1);
}
void BFS() {
	ans.hist = new short[N + 1];
	for (int i = 0; i < N + 1; i++) ans.hist[i] = 0;
	enq(ans, S);
	ans.cnt = INF;

	while (s < e) {
		cur = &deq();
		if (cur->idx == D && ans.cnt > cur->cnt) {
			ans = *cur; //D에 도착한 것이 있으면, cnt를 비교하여 정답에 넣음
			if (ans.cnt == 1) return; //한번만에 도착한거면 무조건 정답이므로
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;	//이미 push된 곳이면 skip
			if (IsHamDist1(cur->idx, i) == false) continue;	//해밍거리가 1이 아니면 skip
			enq(*cur, i); //다음 지점으로 방문할 수 있는 곳(해밍거리 1인것만 인큐됨)
		}
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%s", arr[i]);
	}
	scanf("%d%d", &S, &D);
	BFS();
	if (ans.cnt == INF) printf("-1\n"); //해밍경로 없는 경우
	else {
		for (int i = 0; i < ans.cnt; i++) //찾아야 하는 값
			printf("%d ", ans.hist[i]);
		printf("\n");
	}

	return 0;
}