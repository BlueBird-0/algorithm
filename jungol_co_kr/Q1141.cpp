#include <iostream>
#include <stack>
using namespace std;
long long arr[80001] = { 0, };
long long sum = 0;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	stack<int> st;
	for (int i = 0; i < N; i++)
	{
		long long temp = arr[i];

		while (!st.empty() && st.top() <= temp)
		{
			st.pop();
		}
		sum += st.size();
		st.push(temp);
	}
	printf("%lld", sum);


}