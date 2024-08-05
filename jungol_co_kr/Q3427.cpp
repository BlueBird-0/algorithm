#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Ball{
public:
	char ch;
	int count;
	Ball(char c1, int c2) :ch(c1), count(c2) {}
};

int moveLeft(vector<Ball>& balls, char RB)
{
	//파란공을 모두 왼쪽으로 옮기는 경우
	int count = 0;
	for (auto ball : balls)
	{
		if (ball.ch == RB)
			count += ball.count;
	}
	if (balls.begin()->ch == RB)
		count -= balls.begin()->count;
	return count;
}

int moveRight(vector<Ball>& balls, char RB)
{
	//파란공을 모두 왼쪽으로 옮기는 경우
	int count = 0;
	for (auto ball : balls)
	{
		if (ball.ch == RB)
			count += ball.count;
	}
	if ((balls.end()-1)->ch == RB)
		count -= (balls.end() - 1)->count;
	return count;
}


int main()
{
	vector<Ball> balls;
	int ballCount;
	cin >> ballCount;


	while(ballCount--)
	{
		char ch;
		cin >> ch;
		if (balls.empty())
		{
			balls.push_back(Ball(ch, 1));
		}
		else
		{
			vector<Ball>::iterator it = balls.end() - 1;
			if (it->ch != ch)
				balls.push_back(Ball(ch, 1));
			else
				it->count++;
		}
		
	}

	
	int leftB = moveLeft(balls, 'B');
	int rightB = moveRight(balls, 'B');
	int leftR = moveLeft(balls, 'R');
	int rightR = moveRight(balls, 'R');

	/*cout << leftB << endl;
	cout << rightB << endl;
	cout << leftR << endl;
	cout << rightR << endl;*/
	
	int value = min(leftB, rightB);
	value = min(value, leftR);
	value = min(value, rightR);
	cout << value;


}