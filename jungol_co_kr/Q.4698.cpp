#include <iostream>
using namespace std;

int main()
{
	char arr[26];
	for (int i = 0; i < 26; i++)
		arr[i] = i + 'A';

	for (int element : arr)
	{
		printf("%c ", element);
	}
}