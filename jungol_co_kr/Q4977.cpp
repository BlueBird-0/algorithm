#include <iostream>
#include <string>
using namespace std;

int main()
{
	double n;
	cin >> n;
	int decimal = (int)n;	//������ 
	double min = n- decimal;	//�Ǽ��� 
	
	string str1;
	while(decimal>0)
	{
		if(decimal % 2 == 1)
			str1.insert(0, "1");
		else
			str1.insert(0, "0");
		decimal /= 2;
	}
	if(str1.empty())
		str1 = "0";
	
	string str2;
	for(int i=0; i<4; i++)
	{
		//cout << min << endl;
		if(min * 2 >= 1 )
		{
			str2 += "1";
			min = (min*2)-1;
		}
		else
		{
			str2 += "0";
			min = (min*2);
		}
	}
	cout << str1 << "."<<str2;
	
	return 0 ;
}
