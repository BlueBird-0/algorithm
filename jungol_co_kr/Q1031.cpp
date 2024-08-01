#include <iostream>
using namespace std;
class Map
{
public:
	int num;
	bool checked;
	Map() :num(0), checked(false) {}
};
bool check(Map map[][5])
{
	int count = 0;
	//가로빙고 체크
	for (int i = 0; i < 5; i++)
	{
		int bingoCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j].checked)
				bingoCount++;
		}
		if (bingoCount == 5)
			count++;
	}

	//세로빙고 체크
	for (int i = 0; i < 5; i++)
	{
		int bingoCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (map[j][i].checked)
				bingoCount++;
		}
		if (bingoCount == 5)
			count++;
	}
	//대각선 체크 
	if (map[0][0].checked &&
		map[1][1].checked &&
		map[2][2].checked &&
		map[3][3].checked &&
		map[4][4].checked)
		count++;
	if (map[0][4].checked &&
		map[1][3].checked &&
		map[2][2].checked &&
		map[3][1].checked &&
		map[4][0].checked)
		count++;

	if (count >= 3)
		return true;
	return false;
}

int result =0;
int main()
{
	Map map[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j].num;
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		result++;
		//체크 
		Map* p = &map[0][0];
		while (true)
		{
			//Map* p = map;
			if (p->num == n)
			{
				p->checked = true;
				break;
			}
			p++;
		}

		if (check(map))
		{
			cout << result << endl;
			break;
		}
	}
	return 0;

}
