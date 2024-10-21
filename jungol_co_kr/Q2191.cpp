#include <iostream>
#include <string>
#include <limits.h>

using namespace std;
char a[1001] = { 0, }, b[1001] = { 0, };
int sizeA = 0, sizeB = 0;
int dp[1001][1001] = { 0, };

int main()
{
	cin >> sizeA >> a >> sizeB >> b;
	
	for (int i = 0; i <= sizeA; i++)
		dp[0][i] = i;
	for (int i = 0; i <= sizeB; i++)
		dp[i][0] = i;

	//a->b
	for (int y = 1; y <= sizeB; y++)
	{
		for (int x = 1; x <= sizeA; x++) {
			if (a[x-1] == b[y-1]) {
				dp[y][x] = dp[y-1][x-1];
			}
			else {
				int ivalue = dp[y][x - 1] + 1;
				int evalue = dp[y - 1][x - 1] + 1;
				int dvalue = dp[y - 1][x] + 1;

				dp[y][x] = min(min(ivalue, evalue), dvalue);
			}
		}
	}

	printf("%d", dp[sizeB][sizeA]);

	return 0;
}