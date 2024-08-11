#include <cstdio>
#include <string>
#include <algorithm>

struct Student {
	char name[20];
	int score;
	bool operator<(const Student& r) const {
		if (score == r.score) {
			if (strcmp(name, r.name) > 0)
				return true;
			return false;
		}
		return score < r.score;
	}
};

using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	Student* s = (Student*)malloc(sizeof(Student) * 50001);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", s[i].name, &s[i].score);
	}

	sort(s + 0, s + n);

	reverse(s + 0, s + n);
	for (int i = 0; i < n; i++)
		printf("%s %d\n", s[i].name, s[i].score);
	free(s);
}