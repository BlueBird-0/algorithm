#include <iostream>
#include <vector>
using namespace std;

int p[10001] = {0,};

struct jewel{
	int w;
	int p;
};
vector<jewel> v;

int main()
{
	int N, W;
	scanf("%d %d", &N, &W);

	for (int i = 0; i < N; i++)
	{
		jewel temp;
		scanf("%d %d", &temp.w, &temp.p);
		v.push_back(temp);
	}

	for (int i = 1; i <= W; i++)
	{
		for (auto e : v) {
			if (i-e.w >= 0) {
				p[i] = max(p[i - e.w] + e.p, p[i]);
			}
		}
	}

	//for (int i = 0; i <= W; i++)
	//{
	//	printf("%d ", p[i]);
	//}
	printf("%d ", p[W]);
}