#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    
    cin >> str;
    cin >> n;

    for(int i=0; i<n; i++)
    {
    	int index= str.size()-i-1;
    	if(index>=0)
        	cout<<str[index];
    }
    return 0;
}
