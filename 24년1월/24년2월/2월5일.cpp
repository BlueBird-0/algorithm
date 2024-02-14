#include <iostream>
#include <math.h>
using namespace std;

namespace {
	void Swap(double& x1, double& y1, double& r1, double& x2, double& y2, double& r2)
	{
		double tempX = x1;
		double tempY = y1;
		double tempR = r1;
		x1 = x2;
		y1 = y2;
		r1 = r2;
		x2 = tempX;
		y2 = tempY;
		r2 = tempR;
	};
}

int Q1002()
{
	int T;
	cin >> T;
	while (T--)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		//더 큰 원이 1번이이 되도록 스왑
		if (r2 > r1)
		{
			Swap(x1, y1, r1, x2, y2, r2);
		}

		//동일한경우 =-1
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		//r2가 내부에 있는 경우
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) < r1)
		{
			//  완전 내접할때 = 1
			if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) + r2 == r1)
				cout << 1 << '\n';
			//  내포할때 = 0
			else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) + r2 < r1)
				cout << 0 << '\n';
			//  그게 아니면 = 2
			else
				cout << 2 << '\n';
		}
		//r2가 외부에 있는 경우
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) > r1)
		{
			//  완전 외접할때 = 1
			if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) - r2 == r1)
				cout << 1 << '\n';
			//  외부에 있을때 = 0
			else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) - r2 > r1)
				cout << 0 << '\n';
			//  그게 아니면 = 2
			else
				cout << 2 << '\n';
		}
		//r2가 r1 선 위에 있는 경우
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) == r1)
		{
			cout << 2 << '\n';
		}
	}
	return 0;
}