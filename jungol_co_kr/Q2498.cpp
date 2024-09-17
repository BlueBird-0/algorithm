#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

//GL = AB
//Gx = A
//Gy = B
//L = xyG

int main()
{
	int G, L, A, B;
	cin >> G >> L;


	int xy = L / G;
	int x = 0, y = 0;
	for (int i = 1; i * i <= xy; i++)
	{
		if (xy % i == 0) {
			x = i;
			y = xy / i;

			if (gcd(x, y) == 1) {
				A = G * x;
				B = G * y;
			}
		}
	}
	printf("%d %d", A, B);

}