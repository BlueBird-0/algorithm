#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, findCh;
	cin >> str >> findCh;

	int count = str.find(findCh[0]);
	if (count < 0)
		cout << "No";
	else
		cout << count;

	return 0;
}