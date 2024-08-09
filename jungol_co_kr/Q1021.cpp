#include <iostream>
#include <vector>
using namespace std;

class Object {
public:
	bool isBase = false;
	vector<pair<Object*, int>> rules;
	int count = 0;
	void make()
	{
		if (rules.empty()) {
			isBase = true;
			count++;
		}
		else {
			for (auto rule : rules)
			{
				for (int i = 0; i < rule.second; i++)
				{
					rule.first->make();
				}
			}
		}
	}
};
Object arr[101] = { 0, };



int main()
{
	int N, M;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y, k; //x를 만드는데 y가 k개 필요함.
		cin >> x >> y >> k;
		arr[x].rules.push_back(make_pair(&arr[y], k));
	}

	//counting
	arr[N].make();

	//count
	for (int i = 0; i < N; i++)
	{
		if(arr[i].isBase)
			cout << i << " " << arr[i].count << endl;
	}
}