#include <iostream>

using namespace std;

bool checkPrimeNumber(int n)
{
	if(n == 1)
		return false;
	for(int i=n-1; i>1; i--)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int M, N;
	cin >> M >> N;
	
	int firstPrime = -1;
	int sum = 0;
	for(int i=M; i<=N; i++)
	{
		if(checkPrimeNumber(i))
		{
			if(firstPrime == -1)
				firstPrime = i;
			sum += i;
		}
	}
	if(firstPrime == -1)
		cout << -1;
	else {
		cout << sum <<endl<<firstPrime;
	}
	
	return 0;
}
