#include <iostream>
#include <vector>
using namespace std;

namespace
{
	int leefCount = 0;
	class Node{
	public :
		Node* parent;
		vector <Node*> childs;

		void FindLeefCount()
		{
			if (childs.size() == 0)
			{
				leefCount++;
			}
			else
			{
				for (Node* child : childs)
				{
					child->FindLeefCount();
				}
			}
		}
	};

	Node nodes[51];
	void DeleteNode(int i)
	{
		if (nodes[i].parent != nullptr)
		{
			for (int j = 0; j < nodes[i].parent->childs.size(); j++)
			{
				if (&nodes[i] == nodes[i].parent->childs[j])
					nodes[i].parent->childs.erase(nodes[i].parent->childs.begin() + j);
			}
		}
	}
}

int Q1068()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == -1)
		{
			nodes[i].parent == nullptr;
		}
		else
		{
			nodes[i].parent = &nodes[num];
			nodes[num].childs.push_back(&nodes[i]);
		}
	}
	int deleteNum;
	cin >> deleteNum;
	DeleteNode(deleteNum);

	for (int i = 0; i < N; i++)
	{
		if(i != deleteNum && nodes[i].parent == nullptr)
		nodes[i].FindLeefCount();
	}
		
	cout << leefCount;

	return 0;
}