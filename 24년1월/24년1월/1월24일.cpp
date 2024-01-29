#include <iostream>
#include <vector>
using namespace std;

namespace {
	int inOrder[100001] = { 0, };
	int postOrder[100001] = { 0, };
	void Check(pair<int, int> inorder, pair<int, int> postorder)
	{
		if (inorder.first <= inorder.second && postorder.first <= postorder.second)
		{
			for (int i = 0; i <= inorder.second - inorder.first; i++)
			{
				if (inOrder[inorder.first + i] == postOrder[postorder.second])
				{
					cout << postOrder[postorder.second] << ' ';
					pair<int, int>left1 = make_pair(inorder.first, inorder.first + i - 1);
					pair<int, int>left2 = make_pair(postorder.first, postorder.first + i - 1);
					Check(left1, left2);
					pair<int, int>right1 = make_pair(inorder.first + i + 1, inorder.second);
					pair<int, int>right2 = make_pair(postorder.first + i, postorder.second - 1);
					Check(right1, right2);
				}
			}
		}
	}
}

int Q2263()
{
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		cin >> inOrder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postOrder[i];
	}

	pair<int, int> inorder = make_pair(0, n - 1);
	pair<int, int> postorder = make_pair(0, n - 1);


	Check(inorder, postorder);

	return 0;
}