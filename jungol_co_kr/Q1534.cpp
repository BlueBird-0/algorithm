#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, format;
    cin >> n >> format;
    
    string str;
    
    while(n>0)
    {
    	int temp = n%format;
    	if(temp >= 10)
    	{
    		str += 'A' + (temp-10);
		}else
		{
			str += '0' + temp;
		}
		n = n/format;
	}
	
	reverse(str.begin(), str.end());	// #include <algorithm>
	cout << str;
    
    return 0;
}
