#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> arr;
	int N;
	cin >> N;

	for (int i = N; i > 0; i--)
		arr.push_back(i);

	while (true)
	{
		if (arr.size() == 0)
			break;
		cout << *(arr.end() - 1) << " ";
		arr.pop_back();
		if (arr.size() == 0)
			break;
		arr.push_front(*(arr.end() - 1));
		arr.pop_back();
	}
}