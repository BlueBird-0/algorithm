#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    
    cin >> str;
    cin >> n;

    for(int i=str.size()-1; i>=str.size()-n;i--)
    {
    	if(i>=0)
        	cout<<str[i];
    }
    return 0;
}
