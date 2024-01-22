#include <iostream>
using namespace std;

namespace {
	class Node{
	public :
		int value;
		Node *left = nullptr;
		Node *right = nullptr;
	};

	Node* root = nullptr;
	Node nodes[10000];
	int index = 0;
	void InputNode(int value)
	{
		if (root == nullptr)
		{
			root = &nodes[index++];
			root->value = value;
			return;
		}

		Node* current = root;
		while (true)
		{
			if (value < current->value)
			{
				if (current->left == nullptr)
				{
					current->left = &nodes[index++];
					current->left->value = value;
					return;
				}
				else
				{
					current = current->left;
				}
			}
			else {
				if (current->right == nullptr)
				{
					current->right = &nodes[index++];
					current->right->value = value;
					return;
				}
				else
				{
					current = current->right;
				}
			}
		}
		
	}

	void DFS(Node* node)
	{
		if (node->left != nullptr)
		{
			DFS(node->left);
		}
		if (node->right != nullptr)
		{
			DFS(node->right);
		}
		cout << node->value << '\n';
	}
}

int Q5639()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int i;
	while (cin >> i)
	{
		InputNode(i);
	}
	DFS(root);
	return 0;
};