#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
string strs[7];

int overlapCheck(string& A, string& B)
{
	int overlapLength = 0;
	for (int i = 1; i <= A.size() && i <= B.size(); i++)
	{
		if (A.substr(A.size() - i, i) == B.substr(0, i))
			overlapLength = i;
	}

	return overlapLength;
}

bool visit[7] = { 0, };
vector<int> permu;
int result = INT_MAX;
void makePermutation(int n, int depth, vector<int>& permu)
{
	if (depth == n) {
		//for (auto e : permu)
		//	printf("%2d ", e);
		//printf("\n");
		int i = 1, size = 0;
		for (i = 1; i < n; i++) {
			int len = overlapCheck(strs[permu[i - 1]], strs[permu[i]]);
			size += strs[permu[i - 1]].size() - len;
		}
		size += strs[permu[i-1]].size();
		result = min(result, size);
		return;
	}
	//순열 만들기
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			permu.push_back(i);
			makePermutation(n, depth + 1, permu);
			visit[i] = false;
			permu.pop_back();
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//scanf("%s", strs[i].c_str());
		cin >> strs[i];
	}

	makePermutation(n, 0, permu);
	printf("%d", result);
}