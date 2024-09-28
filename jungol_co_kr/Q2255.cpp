#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int mixArr[20001] = { 0, };
bool checkArr[20001] = { 0, };

//x,y 의 최소공배수 리턴
int findMul(int x, int y)
{
	if (y < x) {
		int temp = x;
		x = y;
		y = temp;
	}
	for (int i = 1; ; i++)
	{
		if ((i * y) % x == 0)
			return i * y;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &mixArr[i]);
	}

	unordered_map<int, bool> argMap;
	//원소별 사이클 찾기
	for (int i = 1; i <= N; i++) {
		int current = i;
		int cicle = 0;
		if (checkArr[i] == false) {
			while (1) {
				checkArr[current] = true;
				current = mixArr[current];
				cicle++;
				if (current == i)
					break;
			}
			argMap[cicle] = true;
		}
		
	}


	//최소공배수 찾기
	int prev = 1;
	for (auto it = argMap.begin(); it != argMap.end(); it++) {
		prev = findMul(prev, it->first);
	}
	printf("%d", prev);

}
