#include <iostream>
#include <cmath>
using namespace std;

class Checker{
	public :
		int n;
		bool primeCheck();
		bool compositeCheck();
};

bool Checker::primeCheck()
{
	if(n == 1)
		return false;
	for(int i=2; i<= sqrt(n); i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

bool Checker::compositeCheck()
{
	for(int i=2; i<= sqrt(n); i++)
	{
		if(n%i == 0)
			return true;
	}
	return false;
}

int main()
{
	int a;
	Checker checker;
	
	for(int i=0; i<5; i++)
	{
		cin >> checker.n;
		if(checker.primeCheck())
			cout << "prime number\n";
		else if(checker.compositeCheck())
			cout << "composite number\n";
		else
			cout << "number one\n";
	}

	return 0;
}
