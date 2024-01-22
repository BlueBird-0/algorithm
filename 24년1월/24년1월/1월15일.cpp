#include <iostream>
#include <vector>
using namespace std;
namespace {
	class Node {
	public:
		int num;
		pair<Node*, int> parent;
		vector<pair<Node*, int>> childs;
	};
	Node nodes[100001];

	int maxx = 0;
	bool checked[100001] = { false, };
	
}

int main()
{
	int V; 
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int num;
		cin >> num;
		while (true)
		{
			int node, value;
			cin >> node;
			if (node == -1)
			{
				break;
			}
			cin >> value;
			if (node != nodes[num].parent.first->num)
			{
				nodes[num].num = num;
				nodes[num].childs.push_back(make_pair(&nodes[node], value));
				nodes[node].parent = make_pair(nodes[num], value);
			}
		}
	}

	for (int i = 0; i <= V; i++)
	{
		for (int j = 0; j <= V ; j++)
		{
			checked[j] = false;
		}
	}
	cout << maxx;
	
	return 0;
}