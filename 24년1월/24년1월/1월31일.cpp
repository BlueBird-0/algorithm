#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace {
	class Node{
	public:
		Node* parent;
		int value;
		int depth;
		vector<Node*> links;
		Node() {
			parent = nullptr;
			depth = 0;
		}
	};
	Node nodes[100001];
	

	void MakeDepth(Node* current)
	{
		queue <Node*>Q;
		for (Node* link : current->links)
		{
			if (link->parent == nullptr && link->value != 1)
			{
				link->parent = current;
				link->depth = current->depth + 1;
				Q.push(link);
			}
		}
		while (Q.size() > 0)
		{
			MakeDepth(Q.front());
			Q.pop();
		}
	}

	int Find(int NodeA, int NodeB)
	{
		Node *a = &nodes[NodeA];
		Node *b = &nodes[NodeB];
		int result;
		while (true)
		{
			if (a->depth > b->depth)
			{
				a = a->parent;
			}
			else if (b->depth > a->depth)
			{
				b = b->parent;
			}
			else
			{
				if (a->value == b->value)
				{
					return a->value;
				}
				a = a->parent;
				b = b->parent;
			}
		}
	}
}

int Q11437()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int N, M;
	cin >> N;
	for (int i=0; i<=N; i++)
	{
		nodes[i].value = i;
	}

	for (int i=0; i<N-1; i++)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;
		nodes[nodeA].links.push_back(&nodes[nodeB]);
		nodes[nodeB].links.push_back(&nodes[nodeA]);
	}


	MakeDepth(&nodes[1]);

	cin >> M;
	for (int i=0; i<M; i++)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;

		cout <<Find(nodeA, nodeB)<<'\n';
	}

	return 0;
}