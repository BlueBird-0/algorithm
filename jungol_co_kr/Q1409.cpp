#include <iostream>
#include <deque>
using namespace std;

deque<int> Q;
int minCount = 10000000;
void open(deque<int> &Q, int o1, int o2, int moveCount)
{
	if (Q.size() == 0)
	{
		if (moveCount < minCount)
			minCount = moveCount;
		return;
	}

	int target = Q.front();
	Q.pop_front();

	int newCount1 = abs(o1 - target);
	open(Q, target, o2, moveCount + newCount1);
	
	int newCount2 = abs(o2 - target);
	open(Q, o1, target, moveCount + newCount2);

	Q.push_front(target);
}

int main()
{
	int c, open1, open2;
	cin >> c >> open1 >> open2;
	int n;
	cin >> n;
	while (n--)
	{
		int target;
		cin >> target;
		Q.push_back(target);
	}

	open(Q, open1, open2, 0);
	cout << minCount;
}