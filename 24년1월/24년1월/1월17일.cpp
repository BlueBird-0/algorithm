#include <iostream>
#include <vector>
using namespace std;

namespace
{
	class Node
	{
	public:
		vector<pair<Node*, int>> links;
	};
	Node nodes[100000];

	Node* maxNode;
	int maxValue;
	void DFS(Node*startNode, Node* node, int sum) {
		if (sum > maxValue)
		{
			maxNode = node;
			maxValue = sum;
		}
		for (pair<Node*, int> link : node->links)
		{
			if (link.first != startNode)
			{
				DFS(node, link.first, sum + link.second);
			}
		}
		return; 
	}
}



int Q1167()
{
	int V;
	cin >> V;
	for (int i=0; i<V; i++)
	{
		int num;
		cin >> num;
		int node, value;
		while (true)
		{
			cin >> node;
			if (node == -1)
				break;
			cin >> value;
			nodes[num].links.push_back(make_pair(&nodes[node], value));
		}
	}

	//처리 로직
	DFS(nullptr, &nodes[1], 0);
	DFS(nullptr, maxNode, 0);
	cout << maxValue;

	return 0;
}