#include <iostream>
#include <math.h>

using namespace std;
double length;

int main()
{
	double red[2];
	double blue[2];
	double yellow[2];
	
	cin >> length;
	cin >> red[0] >> red[1];
	cin >> blue[0] >> blue[1];
	cin >> yellow[0] >> yellow[1];

	double redMid = (red[0] + red[1]) * 0.5;

	double left = redMid;
	double right = length - redMid;
	length = max(left, right);

	blue[0] = abs(redMid - blue[0]);
	blue[1] = abs(redMid - blue[1]);

	yellow[0] = abs(redMid - yellow[0]);
	yellow[1] = abs(redMid - yellow[1]);


	//파란색 조정
	if (blue[0] != blue[1]) {
		double blueMid = (blue[0] + blue[1]) * 0.5;

		left = blueMid;
		right = length - blueMid;
		length = max(left, right);

		yellow[0] = abs(blueMid - yellow[0]);
		yellow[1] = abs(blueMid - yellow[1]);
	}
	
	//노란색 조정
	if (yellow[0] != yellow[1]) {
		double yellowMid = (yellow[0] + yellow[1]) * 0.5;

		left = yellowMid;
		right = length - yellowMid;
		length = max(left, right);
	}

	printf("%.1lf", length);
}
