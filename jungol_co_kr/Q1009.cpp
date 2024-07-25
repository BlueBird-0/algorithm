#include <iostream>

using namespace std;
void checkDigit(int num)
{
	int sum=0;
	int result=0;
	while(true)
	{
		result += num%10;
		sum += num%10;
		num /= 10;
		if(num==0)
			break;
		result *= 10;
	}
	
	cout << result <<" "<< sum <<"\n";
}

int main()
{
	int num;
	
	while(true)
	{
		cin >> num;
		if(num == 0)
			return 0;

		checkDigit(num);
	}
	return 0;
}
