#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	if (b > a)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	//greatest common divisor (GCD)
	int GCD = 1;
	for (int i = b; ; i--)
	{
		if (a%i == 0 && b%i == 0 )
		{
			GCD = i;
			break;
		}
	}

	//least common multiple (LCM)
	int LCM = a;
	for (int i = a; ; i++)
	{
		if (i%a == 0 && i%b == 0)
		{
			LCM = i;
			break;
		}
	}

	printf("%d\n%d", GCD, LCM);
	return 0;
}