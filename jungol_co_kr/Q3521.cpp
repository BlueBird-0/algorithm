#include <iostream>
using namespace std;

int main()
{
	//greedy �˰����� �ΰ��� Ư��
	// 1. ���� ������ ������ ���� ���� ���ÿ� ������ ���� ����. (����X)
	// 2. �����κ� ����. (ū ������ �����ش� �����κ��� �����ظ� �����Ѵ�)
	int a, b, c, d, e, N;
	cin >> a >> b >> c >> d >> e >> N;
	int count = 0;

	while (e--) {
		if (N < 16)
			break;
		N -= 16;
		count++;
	}
	while (d--) {
		if (N < 8)
			break;
		N -= 8;
		count++;
	}
	while (c--) {
		if (N < 4)
			break;
		N -= 4;
		count++;
	}
	while (b--) {
		if (N < 2)
			break;
		N -= 2;
		count++;
	}
	while (a--) {
		if (N < 1)
			break;
		N -= 1;
		count++;
	}
	if (N != 0)
		cout << "impossible";
	else
		cout << count;
}