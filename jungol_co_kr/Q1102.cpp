#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr;
	int n;
	cin >> n;

	while (n--)
	{
		char c;
		cin >> c;
		if (c == 'i')
		{
			int num;
			cin >> num;
			arr.push_back(num);
		}
		else if (c == 'c')
		{
			cout << arr.size() << endl;
		}
		else
		{
			if (arr.size() > 0) {
				cout << *(arr.end() - 1) << endl;
				arr.pop_back();
			}
			else
				cout << "empty" << endl;
		}
	}
	return 0;
}