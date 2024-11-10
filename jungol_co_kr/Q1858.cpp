#include <iostream>
#include <string>
using namespace std;
string strX, strY;
int LCS[1001][1001] = { 0, };
string resultX, resultY;
int resultV = 0;

int main()
{
	int lenX, lenY;
	cin >> lenX >> strX >> lenY >> strY;
	for (int y = 1; y <= lenY; y++) {
		for (int x = 1; x <= lenX; x++) {
			if (strY[y-1] == strX[x-1]) {
				LCS[y][x] = LCS[y - 1][x - 1] + 1;

				int lcs = LCS[y][x];
				int newValue = lcs * 3 + ((x - lcs) * -2) + ((y - lcs) * -2);
				if (resultV <= newValue) {
					resultV = newValue;
					resultX = strX.substr(0, x);
					resultY = strY.substr(0, y);
				}

			}
			else {
				LCS[y][x] = max(LCS[y - 1][x], LCS[y][x - 1]);
			}

		}
	}
	printf("%d\n", resultV);
	printf("%s\n", resultX.c_str());
	printf("%s\n", resultY.c_str());
}