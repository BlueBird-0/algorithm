#include <iostream>
using namespace std;

namespace {
	bool connected[1001][1001] = { false, };
	bool checkedNode[1001] = { false, };
	void DFS(int node)
	{
		checkedNode[node] = true;
		for (int i=0; i<1001; i++)
		{
			if (connected[node][i])
			{
				connected[node][i] = false;
				DFS(i);
			}
		}
	}
}

int Q11724()
{
	int node, line;
	cin >> node >> line;
	for (int i = 0; i < line; i++)
	{
		int stt, end;
		cin >> stt >> end;
		connected[stt][end] = connected[end][stt] = true;
	}

	int connectedComponent = 0;
	for (int i=1; i<=node; i++)
	{
		if (checkedNode[i] == false)
		{
			connectedComponent++;
			DFS(i);
		}
	}
	cout << connectedComponent;
	return 0;
}