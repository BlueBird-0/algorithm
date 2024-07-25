#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	string KOI("KOI");
	string IOI("IOI");
	
	int koiCount = 0;
	int ioiCount = 0;
	
	for(int i=0; i< str.length()-2; i++)
	{
		string temp;
		//temp+=str[i];
		//temp+=str[i+1];
		//temp+=str[i+2];
		
		//temp.append(str, i, 3);	// apeend i index 3alpha.
		
		temp = str.substr(i, 3);	// str split i index 3alpha.
		
		if(temp == KOI)
			koiCount++;
		else if(temp == IOI)
			ioiCount++;
	}
	
	cout << koiCount<<endl<<ioiCount;
	return 0;
}
