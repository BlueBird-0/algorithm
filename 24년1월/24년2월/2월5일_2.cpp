#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {
	class Node {
	public:
		Node* parent;
		vector<Node*> childs;
		bool check;
	};

	Node nodes[1000001];
	int DFS(Node* node, bool isEarlyAdopter)
	{
		int result = 1000001;
		if (node->childs.size() == 0)//리프노드일경우
		{
			if (isEarlyAdopter)
				return 1;
			else
				return 0;
		}
		//얼리어답터인 경우 : 자식이 얼리어답터 이거나, 아닐수도 있음.
		if (isEarlyAdopter)
		{
			for (Node* child : node->childs)
			{
				int value = min(DFS(child, true), DFS(child, false)) + 1;
				if (value < result)
					result = value;
			}
			return result;
		}
		//아닌경우 : 자식이 무조건 얼리어답터 여야함.
		else
		{
			for (Node* child : node->childs)
			{
				int value = DFS(child, true);
				if (value < result)
					result = value;
			}
			return result;
		}
	}
}

int Q2533()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		nodes[u - 1].childs.push_back(&nodes[v - 1]);
		nodes[v - 1].parent = &nodes[u - 1];
	}

	int result = min(DFS(&nodes[0], true), DFS(&nodes[0], false));
	cout << result;
	return 0;
};