#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	double *ptr = new double[n];

	for (int i = 0; i<n; i++)
	{
		cin >> *(ptr + i);
	}

	double hap=0;
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", *(ptr + i));
		hap += ptr[i];
	}

	cout << endl;
	printf("hap : %.2lf\n", hap);
	printf("avg : %.2lf\n", hap/n);

	delete[] ptr;

	return 0;
}