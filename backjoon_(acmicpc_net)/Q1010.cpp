#include <iostream>
#include <math.h>
using namespace std;



int main()
{
	int testCase;
	int n, m;
	scanf("%d", &testCase);

	for (int j = 0; j < testCase; j++) {
		scanf("%d %d", &n, &m);

		double x = 1;
		double y = 1;
		for (int i = m; i > m - n; i--) {
			x *= i;
		}
		for (int i = n; i > 0; i--) {
			y *= i;
		}

		/// mCn  = mPn / n!
		printf("%d\n", (int)(x / y));
	}

	return 0;
}