#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long divide(long long x, long long y)
{
	if (y == 1) return x;
	if (y % 2 == 0)
		return (divide(x, y / 2) * divide(x, y / 2)) % 20091024;
	else
		return (divide(x, y / 2) * divide(x, y / 2 + 1)) % 20091024;
}

int main()
{
	int i;
	long long X, Y;
	scanf("%lld %lld", &X, &Y);
	if (Y == 0)
		printf("1");
	else
		printf("%lld", divide(X, Y));
}