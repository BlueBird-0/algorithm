#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	
	//!! 아래 삼항연산자 코드는 다르게 동작함 : 이유 ) 연산자 우선순위가 3항연산자보다 << 연산자가 더 우선이기 때문. 따라서 전체 구문을 괄호로 묶어주거나 다른방법으로 사용해야함.
	//cout << (str1.length() > str2.length())? str1.length() : str2.length();
	
	if (str1.length() > str2.length())
		cout << str1.length() << endl;
	else
		cout << str2.length() << endl;
		

	return 0;
}