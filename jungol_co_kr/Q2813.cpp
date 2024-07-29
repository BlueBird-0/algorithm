#include <iostream>
#include <cmath>

//eratosthenes prime
bool isComposit[3000001] = {0, };
using namespace std;

bool isPrime(int num)
{
	if(num==1)
		return false;
	for(int i=2; i<=sqrt(num) ; i++)
		if(num%i ==0)
			return false;
	return true;
}

int main()
{
	int M, N;
	cin>> M >> N;
	
	isComposit[0] = true;
	isComposit[1] = true;
	
	for(int i=2; i<=N; i++)
	{
		if(isComposit[i] == false)
		{
			int prime = i;
			for(int j=2; prime*j <=N; j++)
			{
				isComposit[prime * j] = true;
			}
		}
	}
		

	int count =0;
	for(int i=M; i<=N; i++)
	{
		if(isComposit[i] == false)
		{
			count++;	
		}
	}
	cout << count;
	
	return 0;
}
