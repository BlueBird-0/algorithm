#include <iostream>
using namespace std;
namespace {
};

int Q9372()
{
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			//map[a][b] = true;
			//map[b][a] = true;
		}

		//�ּ� ���д� Ʈ�� (���� ����ġ�� 1�� ���, ����� ��-1)
		cout << N - 1 << '\n';
	}


	return 0;
}