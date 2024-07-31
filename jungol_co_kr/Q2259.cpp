#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class line
{
public:
	int dir;
	int distance;
	line(int d, int dis) { dir = d; distance = dis; }
};

int n = 6;
vector<line*> lines;
bool isok(int index)
{
	int next = (index + 1) % 6;
	int prev = (index - 1 + 6) % 6;

	if (lines[index]->dir == 0 && lines[next]->dir == 3 && lines[prev]->dir == 2)
		return true;
	else if (lines[index]->dir == 1 && lines[next]->dir == 2 && lines[prev]->dir == 3)
		return true;
	else if (lines[index]->dir == 2 && lines[next]->dir == 0 && lines[prev]->dir == 1)
		return true;
	else if (lines[index]->dir == 3 && lines[next]->dir == 1 && lines[prev]->dir == 0)
		return true;
	return false;
}

int main()
{
	vector< vector<int> > vec;
	vector<int> zero;
	vec.push_back(zero);
	vec.push_back(zero);
	vec.push_back(zero);
	vec.push_back(zero);

	int squareCount;
	cin >> squareCount;

	int maxWidth = 0;
	int maxHeigt = 0;
	line* prev = NULL;
	while (n--)
	{
		int dir, distance;
		cin >> dir >> distance;
		if ((dir == 1 || dir == 2))
			maxWidth = distance > maxWidth ? distance : maxWidth;
		else
			maxHeigt = distance > maxHeigt ? distance : maxHeigt;
		line* obj = new line(dir - 1, distance);

		lines.push_back(obj);
	}

	int width=0 , height=0;
	for (int i = 0; i < 6; i++)
	{
		if (!isok(i))
		{
			if (lines[i]->dir == 0 || lines[i]->dir == 1)
				width = lines[i]->distance;
			else
				height = lines[i]->distance;
		}
	}


	//cout << maxWidth << endl;
	//cout << maxHeigt << endl;

	cout << ((maxWidth*maxHeigt) - (width*height)) * squareCount << endl;

	return 0;
}
