#include <iostream>

using namespace std;

bool check(int t1, int t2, int K, int D,int day)
{
	if(day > D)
		return false;
	
	int t3 = t1+ t2;
	if(t3 == K && day == D)
		return true;
		
	if(t3 > K)
		return false;
	if ( check(t2, t3 ,K, D, day+1) )
		return true;
	
		return false;
}
 
int main()
{
	int D, K;
	cin >> D >> K;
	
	bool find = false;
	for(int a=1; a<=K && !find;a++)
	{
		for(int b=a+1; b<=K && !find; b++)
		{
			if ( check(a, b, K, D, 3) )
			{
				cout << a <<endl<< b<<endl;
				find = true;
			}
				
		}
	}
	return 0;
}
