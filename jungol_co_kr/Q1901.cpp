#include <iostream>
#include <cmath>
using namespace std;

bool checkPrimeNumber(int n)
{
	if(n<2)
		return false;
	for(int i=2; i<= sqrt(n); i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int num;
		cin>> num;
		bool find = false;
		
		//자기 자신이 소수인지 확인
		find = checkPrimeNumber(num);
		if(!find)
		{
			for(int i=1;; i++)
			{
				bool r1 = false, r2 = false;
				if(num-1 > 1)
				{
					r1 = checkPrimeNumber(num-i);
					if(r1)
						cout<< num-i<<" ";
				}
				r2 = checkPrimeNumber(num+i);
				if(r2)
					cout<< num+i<<" ";
				if(r1||r2)
					break;
			}	
		}else
		{
			cout << num;
		}
		cout <<endl;
	}
	
	return 0;
}
