#include <iostream>
using namespace std;

int main()
{
	//����̰� ���� ����
	//���� N ��
	//������ ���� ����������

	/*1���϶� (��)
	2���϶� (â)
	3���϶� (��)
	4���϶� (â)
	5�� �϶�  (SK)
	��� �̰� 1��
	â�� �̰� 1 or 3
	����̰� 1�� (�¸�)*/
	
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