#include <iostream>
using namespace std;

int w, h;
int p, q;
int t;

int main()
{
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	//xº¯È­
	int tmpX = ((t + p) % (w * 2));
	int tmpY = ((t + q) % (h * 2));

	tmpX = (tmpX <= w) ? tmpX : w - (tmpX - w);
	tmpY = (tmpY <= h) ? tmpY : h - (tmpY - h);

	printf("%d %d", tmpX, tmpY);
}