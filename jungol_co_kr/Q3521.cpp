#include <iostream>
using namespace std;

int main()
{
	//greedy 알고리즘의 두가지 특성
	// 1. 현재 최적을 선택한 것이 이후 선택에 영향을 주지 않음. (번복X)
	// 2. 최적부분 구조. (큰 문제의 최적해는 작은부분의 최적해를 포함한다)
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