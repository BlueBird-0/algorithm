#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Meeting{
public:
	int id;
	int stt;
	int end;
	bool ableAdd(bool useTime[]) {
		for (int i = stt; i < end; i++) {
			if (useTime[i] == true)
				return false;
		}
		return true;
	}
};

vector<Meeting> mList;
bool useTime[501] = { false, };

int main()
{
	int N;
	cin >> N;
	Meeting m;
	for (int i=0; i<N; i++)
	{
		scanf("%d %d %d", &m.id, &m.stt, &m.end);
		mList.push_back(m);
	}

	sort(mList.begin(), mList.end(), [](Meeting a, Meeting b)->bool {return a.end < b.end; });
	
	vector<Meeting> result;
	for (auto m : mList) {
		if (m.ableAdd(useTime)) {
			result.push_back(m);
			for (int i = m.stt; i < m.end; i++)
				useTime[i] = true;
		}
	}

	cout << result.size() << endl;
	for (auto &m : result) {
		cout << m.id << " ";
	}

}