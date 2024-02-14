#include <iostream>
#include <vector>
using namespace std;

namespace {
	class Node {
	public :
		int index;
		vector<Node*> links;
	};
	int n, m;
	Node nodes[501];

	bool visited[501];
	bool isLoop = false;
	bool isSkip = false;
	bool loopChk[501];
	void DP(int index, int stt)
	{
		if (visited[index] == true)
		{
			isSkip = true;
			return;
		}
		visited[index] = true;

		if (loopChk[index] == true)
		{
			isLoop = true;
			return;
		}
		loopChk[index] = true;

		for (Node* link: nodes[index].links)
		{
			if (link->index == stt)
			{
				continue;
			}
			DP(link->index, index);
		}

	}
}

int Q4803()
{
	int T = 1;
	while (true)
	{
		for (int i = 0; i < 501; i++)
		{
			nodes[i].index = i;
			nodes[i].links.clear();
			visited[i] = false;
		}

		//입력
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= m; i++)
		{
			int stt, end;
			cin >> stt >> end;
			nodes[stt].links.push_back(&nodes[end]);
			nodes[end].links.push_back(&nodes[stt]);
		}
		//탐색
		int treeCount = 0;
		for (int i = 1; i <= n; i++)
		{
			//초기화
			isLoop = false;
			isSkip = false;
			for (int x = 0; x <= n; x++)
				loopChk[x] = false;

			DP(i, 0);
			if (!isLoop && !isSkip)
				treeCount++;
		}

		if (treeCount == 0)
			cout << "Case " << T << ": No trees." << '\n';
		else if (treeCount == 1)
			cout << "Case " << T << ": There is one tree." << '\n';
		else
			cout << "Case " << T << ": A forest of " << treeCount << " trees." << '\n';
		T++;
	}

	


	return 0;
}