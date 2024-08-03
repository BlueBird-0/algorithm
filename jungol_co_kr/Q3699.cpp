#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countCombinations(const vector<pair<string, string>>& clothes) {
	// 의상을 분류별로 그룹화
	unordered_map<string, int> clothes_map;
	for (const auto& item : clothes) {
		clothes_map[item.second]++;
	}

	// 조합 계산
	int combinations = 1;
	for (const auto& category : clothes_map) {
		// (해당 분류의 의상 수 + 1) 만큼 곱하기 (의상을 선택하지 않는 경우 포함)
		combinations *= (category.second + 1);
	}

	// 아무것도 선택하지 않는 경우를 1 빼기
	return combinations - 1;
}

int main() {
	// 예시 입력
	vector<pair<string, string>> clothes = {
		{ "hat", "headgear" },
		{ "sunglasses", "eyewear" },
		{ "turban", "headgear" },
		{ "glasses", "eyewear" },
		{ "a", "hand"},
		{ "b", "hand" },
	};

	// 함수 호출 및 결과 출력
	cout << countCombinations(clothes) << endl;  // 출력: 5

	return 0;
}