#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> arr[1000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int count, num;
		scanf("%d", &count);
		for (int j = 0; j < count; j++)
		{
			scanf("%d", &num);
			arr[i].push_back(num);
		}
	}
	//out
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		for (int element : arr[num])
			printf("%d ", element);
		printf("\n");
	}
}