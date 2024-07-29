#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	while(true)
	{
		int A, B;
		string S;
		cin >> A;
		if(A == 0)
			break;
		
		cin >> S >> B; 
		
		//S->10Áø¼ö
		unsigned long decimal = 0;
		unsigned long multi = 1;
		for(int i=0; i<S.length(); i++)
		{
			char ch = S[S.length()-1-i];
			if(ch>= '0' && ch<='9')
				decimal += (0 +S[S.length()-1-i]-'0') * multi;
			else
				decimal += (10+S[S.length()-1-i]-'A') * multi;
			multi *= A;
		}
		//cout << decimal;
		
		//10->B
		string translate = "";
		unsigned long n = decimal;
		while(n > 0)
		{
			int temp = n % B;
			if(temp<10)
				translate+= (char)(temp+'0');
			else
				translate+= (char)(temp-10+'A');
			
			n = n / B;
		}
		reverse(translate.begin(), translate.end());
		if(translate.empty())
			translate = "0";
		cout << translate << endl;
	}
	
	
	return 0;
}
