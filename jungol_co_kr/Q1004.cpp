#include <iostream>
#include <math.h>
using namespace std;
int arr[4001] = { 0, };
int sum = 0;
double avg = 0;
double sd = 0;	//표준편차

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	avg = (double)sum / N;
	for (int i = 0; i < N; i++) {
		sd += (arr[i] - avg) * (arr[i] - avg);
	}
	sd = sqrt(sd / N);

	avg = ((int)((avg + 0.05) * 10)) / 10.0;
	sd = ((int)((sd + 0.05)*10)) / 10.0;

	printf("%d\n", sum);
	printf(((int)(avg * 10) % 10 == 0) ? "%.0lf\n" : "%.1lf\n", avg);
	printf(((int)(sd * 10) % 10 == 0) ? "%.0lf\n" : "%.1lf\n", sd);

	return 0;
}