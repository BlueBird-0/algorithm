#include <iostream>
using namespace std;

int main()
{
	//상근이가 먼저 시작
	//돌은 N 개
	//마지막 돌을 가져가야함

	/*1개일때 (상)
	2개일때 (창)
	3개일때 (상)
	4개일때 (창)
	5개 일때  (SK)
	상근 이가 1개
	창영 이가 1 or 3
	상근이가 1개 (승리)*/
	
	int N = 0;
	scanf("%d", &N);
	N = N % 4;
	if (N == 0)
		printf("CY");
	else if (N == 1)
		printf("SK");
	else if (N == 2)
		printf("CY");
	else if (N == 3)
		printf("SK");

	return 0;
}