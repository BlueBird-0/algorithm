#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	vector<int>arr(n, x);
	char ch;
	while (true)
	{
		scanf("%c", &ch);
		if (ch == 'i') {
			int num;
			scanf("%d", &num);
			arr.insert(arr.end(), num);
		}
		else if (ch == 'r') {
			if (!arr.empty()) 
				arr.pop_back();
		}
		else if (ch == 's') {
			sort(arr.begin(), arr.end());
		}
		else if (ch == 't') {
			if(!arr.empty())
				swap(arr.front(), arr.back());
		}
		else if (ch == 'e') {
			for (int e : arr)
				printf("%d ", e);
			break;
		}
	}

}