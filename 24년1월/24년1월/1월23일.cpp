#include <iostream>
using namespace std;
namespace {
};

int Q9372()
{
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			//map[a][b] = true;
			//map[b][a] = true;
		}

		//최소 스패닝 트리 (간선 가중치가 1일 경우, 노드의 수-1)
		cout << N - 1 << '\n';
	}


	return 0;
}