#include <iostream>

using namespace std;

void print1(int n)
{
	for(int y=0; y<n; y++)
	{
		for (int i = 0; i < y+1; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void print2(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int i = n-y; i> 0 ; i--)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void print3(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int i = n-y-1; i> 0; i--)
		{
			cout << " ";
		}
		for (int i = 0; i< y*2+1; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	
	if (n < 0 || n>100 || m < 1 || m>3)
	{
		cout << "INPUT ERROR!\n";
		return 0;
	}

	if (m == 1)
	{
		print1(n);
	}
	else if (m == 2)
	{
		print2(n);
	}
	else
	{
		print3(n);
	}
	
	return 0;
}