#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Refrigerator {
public :
	int low;
	int high;
	bool checkOverlap(int _low, int _high) {
		if ((_low >= low && _low <= high) || (_high >= low && _high <= high))
			return true;
		return false;
	}
	void opverlap(int _low, int _high) {
		low = max(low, _low);
		high = min(high, _high);
	}
};
int main()
{
	int N;
	cin >> N;
	vector<Refrigerator> ref;
	while (N--)
	{
		Refrigerator r;
		cin >> r.low >> r.high;
		ref.push_back(r);
	}
	sort(ref.begin(), ref.end(), [](Refrigerator a, Refrigerator b)->bool {return a.low < b.low; });

	int count = 0;
	Refrigerator temp;
	temp.low = temp.high = INT_MIN;
	for (auto r : ref)
	{
		if (r.low > temp.high) {
			temp.low = r.low;
			temp.high = r.high;
			count++;
		}
		else {
			if (r.high < temp.high)
				temp.high = r.high;
		}
	}
	cout << count;
}