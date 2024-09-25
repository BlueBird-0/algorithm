#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;
string x, y;
int minus_x = 0, minus_y = 0;

char result[200] = { 0, };

int main()
{
	while (1) {
		cin >> x;
		if (x[0] == '0')
			break;
		cin >> y;
		if (x[0] == '0' || y[0] == '0') {
			printf("0\n");
		}
		else {
			//init
			memset(result, 0, 200);

			minus_x = (x[0] == '-');
			minus_y = (y[0] == '-');
			for (int i = 0; i < x.size() - minus_x; i++)
			{
				int digit = 0;
				int upcate = 0;
				for (int j = 0; j < y.size() - minus_y; j++) {
					digit = i + j; // 현재 수가 n의자리 를 의미
					int temp = result[digit] == 0 ? 0 : result[digit] - '0';	//원래 있던수
					int multi = (x[x.size() - 1 - i] - '0') * (y[y.size() - 1 - j] - '0');

					//printf("--%d\n", multi);
					int one = (multi + temp + upcate) % 10;
					upcate = (multi + temp + upcate) / 10;	//올림수

					result[digit] = one + '0';
				}
				if (upcate != 0)
					result[digit + 1] = upcate % 10 + '0';
				if (upcate == 10)
					result[digit + 2] = '1';
				//printf("%s\n", result);
			}
			int len = 0;
			for (;; len++) {
				if (result[len] == 0)
					break;
			}
			//printf("%s\n", result);
			//부호 출력
			if ((minus_x && !minus_y) || (!minus_x && minus_y))
				printf("-");

			for (len = len - 1; len >= 0; len--) {
				printf("%c", result[len]);
			}
			printf("\n");
		}

		
	}

	return 0;
}