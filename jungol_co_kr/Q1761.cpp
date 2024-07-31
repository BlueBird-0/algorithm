#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToStr(int i)
{
	if (i == 0)
		return "0";
	if (i == 1)
		return "1";
	if (i == 2)
		return "2";
	if (i == 3)
		return "3";
	if (i == 4)
		return "4";
	if (i == 5)
		return "5";
	if (i == 6)
		return "6";
	if (i == 7)
		return "7";
	if (i == 8)
		return "8";
	if (i == 9)
		return "9";
}

class Rule
{
public:
	string str;
	int S;
	int B;
	bool compare(string result)
	{
		int strike = 0, ball = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = result.find(str[i]);
			if (index >= 0)
			{
				if (str[index] == result[index])
					strike++;
				else
					ball++;
			}
		}

		//비교
		if (S == strike && B == ball)
			return true;
		return false;
	}
};

vector<Rule> rules;
bool ruleCheck(string str)
{
	//str이 정답이라 가정할 때, 규칙이 맞는지 확인
	for (auto rule : rules)
	{
		if (!rule.compare(str))
		{
			return false;
		}
	}
	return true;
}

int result = 0;
void permutation(bool check[], string str, int choice)
{
	if (choice == 3)
	{
		if (ruleCheck(str))
		{
			//cout << str << endl;
			result++;
		}
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == true)
			continue;

		check[i] = true;
		permutation(check, str + intToStr(i), choice + 1);
		check[i] = false;
	}
}

int main()
{
	bool check[10] = { false, };
	
	//규칙 체크
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Rule rule;
		cin >> rule.str >> rule.S >> rule.B;
		rules.push_back(rule);
	}

	permutation(check, "", 0);

	//출력
	cout << result;
	return 0;
}
