#include <iostream>
using namespace std;


long long fac(long long n) {
	if (n <= 1)
	{
		printf("%lld! = %lld\n", n, (long long)1);
		return 1;
	}
	
	printf("%lld! = %lld * %lld!\n", n, n, n - 1);
	return n * fac(n - 1);
};
int main()
{
	long long n;
	cin >> n;
	cout << fac(n);
}