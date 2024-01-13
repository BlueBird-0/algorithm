#include <iostream>

using namespace std;
namespace {
	class Node {
	public:
		char ch;
		Node * left;
		Node * right;
	};
	Node arr[26];

	void Preorder(Node* node)
	{
		cout << node->ch;
		if (node->left != nullptr)
			Preorder(node->left);
		if (node->right != nullptr)
			Preorder(node->right);
	}

	void Inorder(Node* node)
	{
		if (node->left != nullptr)
			Inorder(node->left);
		cout << node->ch;
		if (node->right != nullptr)
			Inorder(node->right);
	}

	void Postorder(Node* node)
	{
		if (node->left != nullptr)
			Postorder(node->left);
		if (node->right != nullptr)
			Postorder(node->right);
		cout << node->ch;
	}
}


int Q1991()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char ch, left, right;
		cin >> ch >> left >> right;
		arr[ch - 'A'].ch = ch;
		arr[ch - 'A'].left = (left == '.') ? nullptr : &arr[left - 'A'];
		arr[ch - 'A'].right = (right == '.') ? nullptr : &arr[right - 'A'];
	}
	Preorder(&arr[0]);
	cout << '\n';
	Inorder(&arr[0]);
	cout << '\n';
	Postorder(&arr[0]);
	return 0;
}