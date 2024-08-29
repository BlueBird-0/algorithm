#include <iostream>
using namespace std;

class People{
public:
	int sum = 0;
	int p[3] = { 0, };
	bool operator < (People &b) {
		if (sum < b.sum)
			return true;
		else if (sum == b.sum) {
			if (p[2] < b.p[2])
				return true;
			else if (p[2] == b.p[2]) {
				if (p[1] < b.p[1])
					return true;
			}
		}
		return false;
	};
};
int main()
{
	People point[3] = { 0, };
	int N;
	cin >> N;

	int a, b, c;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		point[0].sum += a;
		point[0].p[a-1]++;
		point[1].sum += b;
		point[1].p[b-1]++;
		point[2].sum += c;
		point[2].p[c-1]++;
	}

	int m = max (max(point[0].sum, point[1].sum), point[2].sum);

	if (point[1] < point[0] && point[2] < point[0])
		printf("%d %d", 1, point[0]);
	else if(point[0] < point[1] && point[2] < point[1])
		printf("%d %d", 2, point[1]);
	else if (point[0] < point[2] && point[1] < point[2])
		printf("%d %d", 3, point[2]);
	else
		printf("%d %d", 0, m);
}