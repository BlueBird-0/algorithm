#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	
	//!! �Ʒ� ���׿����� �ڵ�� �ٸ��� ������ : ���� ) ������ �켱������ 3�׿����ں��� << �����ڰ� �� �켱�̱� ����. ���� ��ü ������ ��ȣ�� �����ְų� �ٸ�������� ����ؾ���.
	//cout << (str1.length() > str2.length())? str1.length() : str2.length();
	
	if (str1.length() > str2.length())
		cout << str1.length() << endl;
	else
		cout << str2.length() << endl;
		

	return 0;
}