#include <iostream>
using namespace std;
#define BIT 8

bool bits[BIT] = {0,};

int getInt()
{
	int value = 0;
	int v = 1;
	for (int i = 0; i < BIT; i++) {
		value += bits[i] * v;
		v *= 2;
	}
	return value;
}
int main()
{
	char temp;
	for (int i = 0; i < BIT; i++) {
		scanf("%c", &temp);
		bits[BIT - 1 - i] = (temp == '1');
	}

	if (bits[BIT - 1]) {	//음수일 경우
		//1의 보수
		for (int i = 0; i < BIT; i++) {
			bits[i] = !bits[i];
		}
		//2의보수
		for (int i = 0; i < BIT; i++) {
			if (bits[i] == 0) {
				bits[i] = 1;
				break;
			}
			else {
				bits[i] = 0;
			}
		}
		printf("-%d", getInt());
	}
	else {
		printf( "%d", getInt());
	}
}