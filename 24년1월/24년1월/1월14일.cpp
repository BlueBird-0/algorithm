#include <iostream>
#include <vector>
using namespace std;

namespace {
	class Node {
	public :
		int value;
		vector<Node*> parent;
		vector<Node*> child;
		vector<Node*> linked;

		void SetParent(int value) {
			for (Node* node : linked)
			{
				if (node->value == value)
					parent.push_back(node);
				else
					child.push_back(node);
			}
			
			//propagation
			for (Node* node : child)
			{
				node->SetParent(this->value);
			}
		};
	};
}

int Q11725()
{
	int N;
	cin >> N;
	Node *nodes = new Node[N+1];
	for (int i = 1; i < N; i++)
	{
		int linkA, linkB;
		cin >> linkA >> linkB;
		nodes[linkA].linked.push_back(&nodes[linkB]);
		nodes[linkB].linked.push_back(&nodes[linkA]);
	}
	for (int i = 0; i<=N; i++)
	{
		nodes[i].value = i;
	}

	//링크연결
	nodes[1].SetParent(1);


	for (int i = 1; i <= N; i++)
	{
		Node* parent = nodes[i].parent.empty()? nullptr : nodes[i].parent.front();
		if(parent != nullptr)
			cout << parent->value << '\n';
	}
	return 0;
}