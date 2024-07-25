#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[26];
	string key;
	//cin >> key;
	getline(cin, key);
	string message;
	getline(cin, message);
	
	for(int i=0; i<26; i++)
	{
		arr[i] = key[i]-('a'+i);
		//cout << arr[i] << " ";
	}
	
	//cout<<endl;
	for(int i=0; i< message.length(); i++)
	{
		char ch = message[i];
			
		int dif;
		if(ch>= 'A' && ch<='Z')
			dif = ch-'A';
		else if(ch >= 'a' && ch<= 'z')
			dif = ch-'a';
		
		if(ch == ' ')
			cout<< " ";
		else
			cout << (char)(ch+arr[dif]);
	}
	
	return 0; 
}
