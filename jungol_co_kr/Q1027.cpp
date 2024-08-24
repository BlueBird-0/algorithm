#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
bool check(string &str)
{

	for (int s = 1; s <= str.size()/2; s++)
	{
		string sub1 = str.substr(str.size() - s, s);
		string sub2 = str.substr(str.size() - 2 * s, s);
		if (sub1 == sub2)
			return true;
	}
	return false;
}

string minstr = "9";
void insertArr(string &str, int &N)
{
	if (str > minstr || check(str)) {
		return;
	}

	if (str.size() == N)
	{
		minstr = min(str, minstr);
		return;
	}

	if (str.back() != '1') {
		str.push_back('1');
		insertArr(str, N);
		str.pop_back();
	}
	if (str.back() != '2') {
		str.push_back('2');
		insertArr(str, N);
		str.pop_back();
	}
	if (str.back() != '3') {
		str.push_back('3');
		insertArr(str, N);
		str.pop_back();
	}
}

int main()
{
	int N;
	cin >> N;
	string arr;

	arr.push_back('1');

	insertArr(arr, N);
	cout << minstr << endl;
}