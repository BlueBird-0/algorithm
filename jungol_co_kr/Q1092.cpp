#include <iostream>
<<<<<<< HEAD
using namespace std;

long long mul(int x, int y)
{
	if (y == 1)
		return x;
	else if(y%2 == 0){
		return mul(x, y / 2) * mul(x, y / 2) % 20091024;
	}
	else if (y % 2 == 1) {
		return mul(x, y / 2) * mul(x, y / 2 + 1) % 20091024;
	}
=======
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
>>>>>>> refs/rewritten/main
}

int main()
{
<<<<<<< HEAD
	int X, Y;
	cin >> X >> Y;
	if (Y == 0)
		printf("1");
	else 
		printf("%lld", mul(X, Y));
=======
	int i;
	long long X, Y;
	scanf("%lld %lld", &X, &Y);
	if (Y == 0)
		printf("1");
	else
		printf("%lld", divide(X, Y));
>>>>>>> refs/rewritten/main
}