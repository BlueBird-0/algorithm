#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace {
	class Node {
	public :
		bool isExist = false;
		Node* number[10] = { nullptr, };
	};

	Node* current = nullptr;
	bool result = false;
	bool newNode = false;
	void Check(int num)
	{
		if (current->number[num] == nullptr)
		{
			current->number[num] = new Node();
			newNode = true;
			current = current->number[num];
		}
		else
		{
			current = current->number[num];
			if (current->isExist == true)
			{
				result = true;
			}
		}
	}

	
}

int Q5052()
{
	int T, n;
	cin >> T;
	while (T--)
	{
		//ÃÊ±âÈ­
		result = false;
		Node root;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string phoneNumber;
			cin >> phoneNumber;
			current = &root;

			newNode = false;
			for (int i = 0; i < phoneNumber.size(); i++)
			{
				int num = phoneNumber[i] - '0';
				Check(num);
			}
			current->isExist = true;
			if(newNode == false)
				result = true;
		}

		string str = result ? "NO" : "YES";
		cout << str << '\n';

	}
	return 0;
}