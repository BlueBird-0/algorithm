#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countCombinations(const vector<pair<string, string>>& clothes) {
	// �ǻ��� �з����� �׷�ȭ
	unordered_map<string, int> clothes_map;
	for (const auto& item : clothes) {
		clothes_map[item.second]++;
	}

	// ���� ���
	int combinations = 1;
	for (const auto& category : clothes_map) {
		// (�ش� �з��� �ǻ� �� + 1) ��ŭ ���ϱ� (�ǻ��� �������� �ʴ� ��� ����)
		combinations *= (category.second + 1);
	}

	// �ƹ��͵� �������� �ʴ� ��츦 1 ����
	return combinations - 1;
}

int main() {
	// ���� �Է�
	vector<pair<string, string>> clothes = {
		{ "hat", "headgear" },
		{ "sunglasses", "eyewear" },
		{ "turban", "headgear" },
		{ "glasses", "eyewear" },
		{ "a", "hand"},
		{ "b", "hand" },
	};

	// �Լ� ȣ�� �� ��� ���
	cout << countCombinations(clothes) << endl;  // ���: 5

	return 0;
}