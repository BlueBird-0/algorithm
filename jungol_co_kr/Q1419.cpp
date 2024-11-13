#include <iostream>
using namespace std;

int main()
{
	unsigned int input;
	cin >> input;
	char* ptr = (char*)(&input);
	unsigned int result = 0;
	for (int i = 0; i < 4; i++) {
		*((char*)&result + (3 - i)) = *(ptr + i);
	}
	printf("%u", result);
}