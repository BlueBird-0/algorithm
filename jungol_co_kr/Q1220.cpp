#include <iostream>
#include <string>
#include <limits.h>
#include <map>

using namespace std;
string origin1, origin2;
string str1, str2;
int arr1[1001] = { 0, };
int arr2[1001] = { 0, };

int main()
{

	cin >> origin1 >> origin2;
	//공통 문자열만 남도록 추출
	map<char, bool> map1, map2;
	for (int i = 0; i < origin1.size(); i++) {
		map1[origin1[i]] = true;
	}
	for (int i = 0; i < origin2.size(); i++) {
		map2[origin2[i]] = true;
	}
	char ch;
	for (int i = 0; i < origin1.size(); i++) {
		ch = origin1[i];
		if (map1[ch] && map2[ch]) {
			str1.push_back(ch);
		}
	}
	for (int i = 0; i < origin2.size(); i++) {
		ch = origin2[i];
		if (map1[ch] && map2[ch]) {
			str2.push_back(ch);
		}
	}
	

	//normal LIS
	for (int i = 0; i < str1.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (str1[j] < str1[i]) {
				arr1[i] = arr1[j] + 1;
				break;
			}
		}
	}

	for (int i = 0; i < str2.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (str2[j] < str2[i]) {
				arr2[i] = arr2[j] + 1;
				break;
			}
		}
	}



	for (int i = 0; i < str1.size(); i++) {
		printf("%2c ", str1[i]);
	}
	printf("\n");
	/*for (int i = 0; i < str1.size(); i++) {
		printf("%2d ", arr1[i]);
	}*/
	printf("\n");
	for (int i = 0; i < str2.size(); i++) {
		printf("%2c ", str2[i]);
	}
	/*printf("\n");
	for (int i = 0; i < str2.size(); i++) {
		printf("%2d ", arr2[i]);
	}*/
	printf("\n");
	
	int result = 0;
	int temp;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				temp = min(arr1[i], arr2[j]) + 1;
				result = max(temp, result);
			}
		}
	}
	printf("%d", result);
}