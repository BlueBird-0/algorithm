#include <iostream>
#include <deque>

using namespace std;



int main()
{
	int n, num;
	string str;
	deque<int> temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push_back") {
			scanf("%d", &num);
			temp.push_back(num);
		}
		else if (str == "push_front") {
			scanf("%d", &num);
			temp.push_front(num);
		}
		else if (str == "pop_back") {
			if (temp.empty())
				printf("-1\n");
			else {
				num = temp.back();
				temp.pop_back();
				printf("%d\n", num);
			}
		}
		else if (str == "pop_front") {
			if (temp.empty())
				printf("-1\n");
			else {
				num = temp.front();
				temp.pop_front();
				printf("%d\n", num);
			}
		}
		else if (str == "size") {
			printf("%d\n", temp.size());
		}
		else if (str == "empty") {
			printf("%d\n", temp.empty()? 1:0);
		}
		else if (str == "front") {
			if (temp.empty())
				printf("-1\n");
			else {
				num = temp.front();
				printf("%d\n", num);
			}
		}
		else if (str == "back") {
			if (temp.empty())
				printf("-1\n");
			else {
				num = temp.back();
				printf("%d\n", num);
			}
		}
	}

	return 0;
}