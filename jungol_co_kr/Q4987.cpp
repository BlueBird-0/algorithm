#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S, T;
	cin >> S;
	cin >> T;
	
	while(true)
	{
		int index = S.find(T);
		if(index == -1)
			break;
		S.erase(index, T.length());
	}
	cout<<S<<endl;
	
	
	return 0;
}
