#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<string, int>> arr(100);

int main()
{
	ifstream fin("input.txt", ios_base::in);
	if (!fin) {
		cout << "오류!" << endl;
		return 0;
	}
	int i = 0;
	for(i=0; i<100; i++) {
		string str;
		getline(fin, str);
		
		int fff = str.find(' ');
		arr[i].first = str.substr(0, fff);
		arr[i].second = stoi(str.substr(fff + 1, str.size()));

		if (fin.eof())
			break;
	}
	sort(&arr[0], &arr[i+1], [](pair<string, int>& a, pair<string, int>& b)->bool {return a.second > b.second; });

	printf("  이름 점수 등수\n");
	int rank = 0, prev_point = 101;
	for (int j = 0; j <= i; j++) {
		if (prev_point != arr[j].second) {
			rank = j + 1;
		}
		prev_point = arr[j].second;
		printf("%s%5d%5d\n", arr[j].first.c_str(), arr[j].second, rank);
	}

	fin.close();
	return 0;
}