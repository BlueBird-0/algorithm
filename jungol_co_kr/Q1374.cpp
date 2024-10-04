#include <iostream>
#include <string>

using namespace std;

void sum(string A, string B)
{
	int Aidx = A.size() - 1;
	int Bidx = B.size() - 1;

	char result[400] = { 0, };
	int resultIdx = 0;

	int a, b, up = 0;
	while (Aidx >= 0 || Bidx >= 0)
	{
		if (Aidx >= 0) {
			a = A[Aidx--] - '0';
		}
		else
			a = 0;

		if (Bidx >= 0) {
			b = B[Bidx--] - '0';
		}
		else
			b = 0;
		int remain = (a + b + up) % 10;
		result[resultIdx++] = remain+'0';

		up = (a + b + up) / 10;
	}
	if(up != 0)
		result[resultIdx++] = up + '0';

	for (int i = resultIdx-1; i >= 0; i--) {
		printf("%c", result[i]);
	}
	printf("\n");
}

void sub(string A, string B)
{
	if (A == B) {
		printf("0");
		return;
	}

	//find bigger number
	string* big;
	string* small;
	if (A.size() != B.size()) {
		if (A.size() > B.size()) {
			big = &A;	small = &B;
		}
		else {
			big = &B;	small = &A;
		}
	}
	else {
		int idx = 0;
		while (true) {
			if (A[idx] - '0' > B[idx] - '0') {
				big = &A;	small = &B;
				break;
			}
			else if (B[idx] - '0' > A[idx] - '0') {
				big = &B;	small = &A;
				break;
			}
			idx++;
		}	
	}

	//cal
	int Aidx = big->size() - 1;	//A bigger than B.
	int Bidx = small->size() - 1;

	char result[400] = { 0, };
	int resultIdx = 0;

	int a, b, up = 0;
	while (Aidx >= 0 || Bidx >= 0)
	{
		if (Aidx >= 0) {
			a = (*big)[Aidx--] - '0';
		}
		else
			a = 0;

		if (Bidx >= 0) {
			b = (*small)[Bidx--] - '0';
		}
		else
			b = 0;

		if (up == 1) {
			a--;
			up = 0;
		}
		if (b > a) {
			up = 1;
			a += 10;
		}

		int remain = a - b;
		result[resultIdx++] = remain + '0';
	}

	bool stt = false;
	for (int i = resultIdx - 1; i >= 0; i--) {
		if (!stt) {
			if (result[i] != '0')
				stt = true;
		}

		if(stt) {
			printf("%c", result[i]);
		}
	}
	printf("\n");
}

int main()
{
	string A, B;

	while (true) {
		cin >> A >> B;
		if (A == "0" && B == "0")
			break;

		sum(A, B);
		sub(A, B);
	}
	
	
}