#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;
class Range{
public:
	int stt;
	int end;
	Range(int stt, int end):stt(stt),end(end) {}
	int get() { return end - stt + 1; }
};

int main()
{
	int M, C, S, num;
	cin >> M >> C >> S;

	vector<int> arr;
	for (int i = 0; i < S; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	map<int, bool> split;
	while (true)
	{
		if (M == 1)
			break;
		int maxDif = 0;
		int difIndex = 0;
		for (int i = 1; i < arr.size(); i++)
		{
			if (split.find(i) == split.end()) {
				if (arr[i] - arr[i - 1] > maxDif)
				{
					maxDif = arr[i] - arr[i - 1];
					difIndex = i;
				}
			}
		}
		split[difIndex] = true;
		if (split.size() == M-1 || split.size() >= arr.size()-1)
			break;
	}

	int result = 0;
	int stt = arr[0];
	for (auto it : split)
	{
		result += arr[it.first-1] - stt + 1;
		stt = arr[it.first];
	}
	result += *(arr.end()-1) - stt + 1;
	cout << result;
	
}