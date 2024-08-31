#include <iostream>
#include <queue>

struct st {
	int x, y, z;
};
using namespace std;
queue <st> q;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin.ignore();
		char ch;
		scanf("%c", &ch);

		if (ch == 'i') {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			q.push({ x,y,z });
		}
		else if (ch == 'o') {
			if (q.empty()) {
				printf("empty\n");
			}
			else {
				st* ptr = &q.front();
				printf("%d %d %d\n", ptr->x, ptr->y, ptr->z);
				q.pop();
			}
		}
		else if (ch == 'c') {
			printf("%d\n", q.size());
		}
		else if (ch == 'z') {
			int a;
			scanf("%d", &a);
			if (q.empty()) {
				printf("no\n");
			}
			else {
				printf("%s\n", q.front().z == a ? "yes" : "no");
			}
		}
	}
}