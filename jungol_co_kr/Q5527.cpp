#include <iostream>
#include <string>
#include <queue>
using namespace std;
class People{
public:
	int time;
	People(int t):time(t) {}
};

void wait(queue<People>& peoples, int &time)
{
	if (peoples.empty())
		return;
	else if (peoples.front().time > 1) {
		peoples.front().time--;
		time--;
	}
	else if (peoples.front().time <= 1)
	{
		peoples.pop();
		time--;
	}
}

int main()
{
	int N;
	cin >> N;

	int totalTime = 0;
	string str;
	queue<People> peoples;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "call") 
		{
			int time;
			cin >> time;
			peoples.push(People(time));
			totalTime += time;
		}
		else if (str == "check")
		{
			cout << peoples.size() << " people " << totalTime << " minutes" << endl;
		}else if(str == "wait")
		{
			int time;
			cin >> time;
			for (int t = 0; t < time; t++)
				wait(peoples, totalTime);
		}
	}
}