#include <iostream>
using namespace std;

string Replace(string& str, string keyword) {
	int idx = str.find(keyword, 0);
	if (idx < 0)
		return "";
	string newStr;
	newStr.append(str.substr(0, idx));
	newStr.append(str.substr(idx + keyword.size(), str.size() - idx - keyword.size()));

	return newStr;
}

int main() {
	string origin, keyword;
	cin >> origin >> keyword;
	string result = origin;

	for (int i = 0; ; i++) {
		string temp = Replace(result, keyword);
		if (temp == "")
			break;
		result = temp;
	}
	if (result == keyword)
		cout << "FRULA" << endl;
	else
		cout << result << endl;
	
	return 0;
}