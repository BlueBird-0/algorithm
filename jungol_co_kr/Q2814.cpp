#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    
    cin >> str;
    unsigned int num=0;
    for(int i=0; i<str.length(); i++)
    {
        num += str[str.length()-1-i]-'0' << i;
    }
    cout << num;

    return 0;
}
