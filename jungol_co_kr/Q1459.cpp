#include <iostream>
#include <vector>
#include <map>
using namespace std;

int line2[100];
bool choice[100] = { false, };
int n;

bool hasNum(vector<int> arr, int num) {
	for (int a : arr) {
		if (num == a)
			return true;
	}
	return false;
}

void roopCheck(vector<int>arr , int num, int targetNum) {
	
	int newNum = line2[num-1];
	if (hasNum(arr, newNum)) {	//vector에 순환이 있는지 확인.
		if (*arr.begin() == newNum) {
			for (int a : arr)
				choice[a-1] = true;
		}
		return ;
	}
	else {
		arr.push_back(newNum);
		roopCheck(arr, newNum, targetNum);
	}
}

int main()
{
	cin >> n;
	int num;
	for (int i = 0; i < n; i++){
	//	line1[i] = i + 1;
		cin >> num;
		line2[i] = num;
	}

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		if (!choice[i]) {
			arr.push_back(i + 1);
			roopCheck(arr, i + 1, i + 1);
			arr.pop_back();
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (choice[i])
			count++;
	}
	cout << count << endl;
	for (int i = 0; i < n; i++) {
		if (choice[i])
			cout << i + 1 << endl;
	}
	
}