#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	char str[101];
	fgets(str, 100, stdin);
	int count = 0;
	for (int i = 0; i<100; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	printf("%d", count+1);

	return 0;
}