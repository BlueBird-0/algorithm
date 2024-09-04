#include <iostream>
using namespace std;
//imos 알고리즘 연습
int T[1000001] = { 0, };
int result[1000001] = { 0, };

int main()
{
	int N, Q, S, E, C;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &S, &E, &C);
		T[S] += C;
		T[E + 1] -= C;
	}
	
	int now = 0;
	for (int i = 0; i < 1000001; i++) {
		now += T[i];
		result[i] += now;
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int input;
		scanf("%d", &input);

		printf("%d\n", result[input]);
	}
}