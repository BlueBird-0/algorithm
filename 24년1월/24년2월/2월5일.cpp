#include <iostream>
#include <math.h>
using namespace std;

namespace {
	void Swap(double& x1, double &y1, double &r1, double &x2, double &y2, double &r2)
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
	while(T--)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		//�� ū ���� 1������ �ǵ��� ����
		if (r2 > r1)
		{
			Swap(x1, y1, r1, x2, y2, r2);
		}

		//�����Ѱ�� =-1
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		//r2�� ���ο� �ִ� ���
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) < r1)
		{
			//  ���� �����Ҷ� = 1
			if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) + r2 == r1)
				cout << 1 << '\n';
			//  �����Ҷ� = 0
			else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) + r2 < r1)
				cout << 0 << '\n';
			//  �װ� �ƴϸ� = 2
			else
				cout << 2 << '\n';
		}
		//r2�� �ܺο� �ִ� ���
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) > r1)
		{
			//  ���� �����Ҷ� = 1
			if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) - r2 == r1)
				cout << 1 << '\n';
			//  �ܺο� ������ = 0
			else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) - r2 > r1)
				cout << 0 << '\n';
			//  �װ� �ƴϸ� = 2
			else
				cout << 2 << '\n';
		}
		//r2�� r1 �� ���� �ִ� ���
		else if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) == r1)
		{
			cout << 2 << '\n';
		}
		

		

	}
	return 0;
}