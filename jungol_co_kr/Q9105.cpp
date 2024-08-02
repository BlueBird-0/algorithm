#include <iostream>
#include <string>

using namespace std;
void combination(string str, int stt, int end, int n)
{
    if(n==0)
    {
        cout<< str << endl;
        return;
    }

    for(int i=stt; i<=end; i++)
    {
    	string temp = str + (char)('0'+i);
        temp+= " ";
        combination(temp, stt, end, n-1);
    }
}

int main()
{
	int n =0;
	cin >> n;
    combination("", 1, 6, n);
    return 0;
}
