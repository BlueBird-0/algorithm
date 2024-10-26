#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n;

int main()
{
	cin >> n; 
	vector<pair<int, int>> arr;
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a>b)
			arr.push_back(make_pair(a, b));
		else
			arr.push_back(make_pair(b, a));
		
	}
	//�������� ����
	sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b)->bool {return a.first * a.second < b.first* b.second; });


	int stack[100] = {0,};

	for(int i=0; i<n; i++)
	{
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i].first >= arr[j].first && arr[i].first >= arr[j].second) {
				stack[i] = max(stack[j] + 1, stack[i]);
			}
		}
	}
	printf("%d", stack[n-1]);
}