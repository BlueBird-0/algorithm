#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int y, x, inY, inX;
	scanf("%d %d", &y, &x);
	bool* proX = new bool[x] {false, };
	int paper, err;
	scanf("%d %d", &paper, &err);
	int size = 0;
	while (err--)
	{
		scanf("%d %d", &inY, &inX);
		proX[(inX - 1)] = true;
		if(inY > size)
			size = inY;
	}

	while (true)
	{
		bool* temp = new bool[x];
		memcpy(temp, proX, sizeof(bool) * x);

		int usePaper = 0;
		bool result = true;
		for (int i = 0; i < x; i++) {
			//색종이 붙이기
			if (temp[i]) {
				usePaper++;
				for (int j = i; j < i + size && j < x; j++) {
					temp[j] = false;
				}
			}
			if (usePaper > paper) {
				size++;	//색종이 키우기
				result = false;
				break;
			}
		}
		if (result)
		{
			printf("%d", size);
			break;
		}
		delete[] temp;
	}

	//test
	//for (int xx = 0; xx < x; xx ++) {
	//	cout << proX[xx] ? "T" : "-";
	//}

	delete[] proX;
}