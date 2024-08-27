#include <iostream>
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
}

int main()
{
	int X, Y;
	cin >> X >> Y;
	if (Y == 0)
		printf("1");
	else 
		printf("%lld", mul(X, Y));
}