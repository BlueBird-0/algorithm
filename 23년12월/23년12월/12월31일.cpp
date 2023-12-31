//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
namespace {
	static int size = 0;
	static int siteCount = 0;
	class Position{
	public:
		int x, y;
		Position(int x, int y) {
			this->x = x;
			this->y = y;
		}
		int GetX()
		{
			if (x <= 0)
				return 0;
			if (x >= 24)
				return 24;
			return x;
		}
		int GetY()
		{
			if (y <= 0)
				return 0;
			if (y >= 24)
				return 24;
			return y;
		}
	};


	bool mapMask[25][25] = { false, };

	queue<Position> posQ;
	int InspectHouseSize(int startX, int startY)
	{
		siteCount++;
		Position startPos(startX, startY);
		posQ.push(startPos);
		size = 0;
		while (posQ.size() != 0)
		{
			Position position = posQ.front();
			posQ.pop();

			
			bool isChecked = mapMask[position.GetY()][position.GetX()];
			if (isChecked)
			{
				size++;
				mapMask[position.GetY()][position.GetX()] = false;

				Position LeftPos(position.x - 1, position.y);
				Position RightPos(position.x + 1, position.y);
				Position UpPos(position.x, position.y - 1);
				Position DownPos(position.x, position.y + 1);

				posQ.push(LeftPos);
				posQ.push(RightPos);
				posQ.push(UpPos);
				posQ.push(DownPos);
			}
		}
		return size;
	}
}

int Q2667()
{
	int N;
	cin >> N;
	cin.get();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			char ch = cin.get();
			mapMask[y][x] = ch - '0';
		}
		cin.get();
	}

	//단지 찾기
	vector<int> sizeArr;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (mapMask[y][x])
			{
				int size = InspectHouseSize(x, y);
				sizeArr.push_back(size);
			}
		}
	}
	//정렬
	sort(sizeArr.begin(), sizeArr.end());
	//출력
	cout << siteCount << endl;
	for (int i : sizeArr)
	{
		cout << i << endl;
	}

	return 0;
}