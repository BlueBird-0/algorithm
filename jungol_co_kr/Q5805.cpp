#include <iostream>
using namespace std;

int main()
{
	int X, Y;
	scanf("%d %d", &X, &Y);
	double Z = Y * (double)100 / (double)X;
	int ZtoInt = (int)Z;
	int count = 1;
	while (true) {
		double newZ = (double)(Y+count) * (double)100 / (double)(X+count);
		int newZtoInt = (int)newZ;
		if (Z == 99 ||  Z == newZ) {
			printf("-1");
			return 0;
		}
		if (ZtoInt != newZtoInt) {
			printf("%d", count);
			return 0;
		}
		count++;
	}
	
}