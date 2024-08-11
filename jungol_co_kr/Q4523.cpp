#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	/*int i;
	int arr[8] = { 1,9,9,4,1,1,0,8 };
	sort(arr + 0, arr + 8);
	for (i = 0; i < 8; i++)
		printf("%d ", arr[i]);
		*/
	int N, num;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	int s, e;
	cin >> s >> e;
	sort(arr.begin() + s, arr.begin() + e + 1);
	for (int i : arr)
		cout << i << " ";
	cout << endl;
	sort(arr.begin(), arr.end());
	// sort function change descending order.
	// sort(arr.begin(), arr.end(), [](int a, int b)->bool {return a>b; });
	for (int i : arr)
		cout << i << " ";
	cout << endl;
	return 0;
}