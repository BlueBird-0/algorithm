#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX = 850;
const int src = 0, dest=849, work = 400;
int n, m, ans, cnt;
int c[MAX][MAX];
int f[MAX][MAX];
int pay[MAX][MAX];
vector<int> adj_list[MAX];

void mcmf()
{
	while (1)
	{
		int p[MAX], d[MAX];
		fill(p, p+MAX, -1);
		fill(d, d + MAX, INF);
		d[src] = 0;

		queue<int>q;
		bool inq[MAX];	//SPFA
		fill(inq, inq + MAX, false);

		q.push(src);
		inq[src] = true;
		p[src] = src;

		while (!q.empty()) {
			int cv = q.front(); q.pop();
			inq[cv] = false;
			
			int len = adj_list[cv].size();
			for (int i = 0; i < len; ++i) {
				int nv = adj_list[cv][i];
				int nw = pay[cv][nv];
				//유량이 남아있고, 최단거리를 갱신할 수 있다면?
				if (c[cv][nv] - f[cv][nv] > 0 && d[nv] > d[cv] + nw) {
					d[nv] = d[cv] + nw;
					p[nv] = cv;
					if (!inq[nv]) {
						inq[nv] = true;
						q.push(nv);
					}
				}
			}
		}

		if (p[dest] == -1)
			break;

		int minflow = INF;
		for (int i = dest; i != src; i = p[i])
			minflow = min(minflow, c[p[i]][i] - f[p[i]][i]);

		for (int i = dest; i != src; i = p[i])
		{
			ans += minflow * pay[p[i]][i];

			f[p[i]][i] += minflow;
			f[i][p[i]] += -minflow;
		}
		cnt++;
	}
	return;
}

int main()
{
	scanf("%d %d", &n, &m);

	//src와 사람 연결
	for (int i = 1; i <= n; ++i) {
		c[0][i] = 1;	//graph
		adj_list[0].push_back(i);	//양방향 그래프
		adj_list[i].push_back(0);
	}

	//일과 dest 연결
	for (int i = 1; i <= m; ++i) {
		c[work + i][dest] = 1;
		adj_list[dest].push_back(i + work);
		adj_list[i + work].push_back(dest);
	}

	//사람과 일 연결
	for (int i = 1; i <= n; ++i) {
		int len;
		scanf("%d", &len);

		for (int j = 0; j < len; ++j) {
			int to, weight;
			scanf("%d %d", &to, &weight);

			adj_list[i].push_back(work + to);	//사람-일 양방향 연결
			adj_list[work + to].push_back(i);

			pay[i][work + to] = weight;
			pay[work + to][i] = -weight;

			c[i][work + to] = 1;
		}
	}

	mcmf();
	printf("%d\n%d\n", cnt, ans);
	return 0;
}