#include <iostream>
#include <string>
using namespace std;
string str;
int arr[41] = { 0, };
int result = 0;
void check(string str, int stt) {
	if (stt >= str.size()) {
		result++;
		//printf("%s\n", str.c_str());
		return;
	}
	if (stt + 1 < str.size()) {
		int a = atoi(str.substr(stt, 2).c_str());
		if (a >= 10 && a <= 34) {
			check(str, stt + 2);
		}
	}
	if (stt < str.size()) {
		int b = atoi(str.substr(stt, 1).c_str());
		if (b != 0 && b <= 9) {
			check(str, stt + 1);
		}
	}
}

int main()
{
	cin >> str;
	int stt = 0;

	check(str, stt);
	printf("%d", result);
}