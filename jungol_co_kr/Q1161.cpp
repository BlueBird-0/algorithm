#include <iostream>

using namespace std; 

int next(int src, int dest)
{
	bool arr[3] = {false,};
	arr[src - 1] = true;
	arr[dest - 1] = true;
	for (int i = 0; i < 3; i++)
		if (arr[i] == false)
			return i+1;
}

void move(int depth, int src, int dest) 
{
	if (depth == 0) {
		return;
	}
	move(depth - 1, src, next(src, dest));
	printf("%d : %d  -> %d\n", depth, src, dest);
	move(depth - 1, next(src, dest), dest);
}
int main()
{
	int N;
	cin >> N;
	move(N, 1, 3);
}