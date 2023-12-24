#include <stdio.h>
#include <iostream>
#include <vector>

const static int LIMIT = 10000;

int d(int n);
int Q4673()
{
	bool result[LIMIT + 1] = { false, };
	for (int i = 0; i <= LIMIT; i++) {
		int index = d(i);
		if (index <= LIMIT)
		{
			result[index] = true;
		}
	}

	for (int i = 0; i <= LIMIT; i++) {
		if (result[i] == false)
			printf("%d\n", i);
	}
	return 0;
}

int d(int n)
{
	std::vector<int> arr;
	int position = n;
	int result = n;
	while (position > 0)
	{
		arr.push_back(position % 10);
		position /= 10;
	}

	for (int &i : arr)
	{
		result += i;
	}
	return result;
}