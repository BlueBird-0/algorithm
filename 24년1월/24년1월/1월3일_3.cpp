#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Q2587()
{
	int N = 5;
	vector<int> vectorArr;
	int sum = 0;
	for (int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		sum += x;
		vectorArr.push_back(x);
	}
	//Æò±Õ
	cout << (int)(sum / vectorArr.size()) << '\n';
	//Áß¾Ó°ª
	sort(vectorArr.begin(), vectorArr.end());
	cout << (int)(vectorArr[N/2]) << '\n';


	return 0;
}