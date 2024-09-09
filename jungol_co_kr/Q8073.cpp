#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack <int> s;

int main()
{
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
			s.push(num);
		}
		else if (c == 'c')
		{
			cout << s.size() << endl;
		}
		else
		{
			if (s.size() > 0) {
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << "empty" << endl;
		}
	}
	return 0;
}