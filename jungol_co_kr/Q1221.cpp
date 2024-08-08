#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	while (n--)
	{
		char ch;
		cin >> ch;

		if (ch >= '0' && ch <= '9')
		{
			arr.push_back(ch - '0');
		}
		else
		{
			int A = *(arr.end() - 1);
			arr.pop_back();
			int B = *(arr.end() - 1);
			arr.pop_back();
			if (ch == '+') {
				arr.push_back(B + A);
			}
			else if (ch == '-') {
				arr.push_back(B - A);
			}
			else if (ch == '*') {
				arr.push_back(B * A);
			}
			else if (ch == '/') {
				arr.push_back(B / A);
			}
		}	
	}
	cout << arr[0];

}