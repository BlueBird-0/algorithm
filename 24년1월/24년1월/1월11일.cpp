#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

namespace {
	int RGB_Map[3][1001] = { 0, };

	enum {
		R = 0,
		G, B
	};
}
int Q1149() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;

		if (i == 0)
		{
			RGB_Map[R][i] = r;
			RGB_Map[G][i] = g;
			RGB_Map[B][i] = b;
		}
		else {
			RGB_Map[R][i] = min(RGB_Map[G][i - 1], RGB_Map[B][i - 1]) + r;
			RGB_Map[G][i] = min(RGB_Map[R][i - 1], RGB_Map[B][i - 1]) + g;
			RGB_Map[B][i] = min(RGB_Map[R][i - 1], RGB_Map[G][i - 1]) + b;
		}
	}

	//ÃÖ¼Ú°ª Ã£±â
	int result = min(min(RGB_Map[R][N - 1]
		, RGB_Map[G][N - 1]), RGB_Map[B][N - 1]);
	cout << result;
	
	return 0;
}