#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	while(true)
	{
		string str;
		getline(cin, str);
		if(str == "END")
			break;
		
		string arr[200];
		int count = 0;
		for(int i=0; ; i++)
		{
			int index = str.find(" ");
			if(index == -1){
				count = i+1;
				arr[i] = str;
				break;
			}
			arr[i] = str.substr(0, index);
			str.erase(0, index+1);
		}
		//문자열 처리
		map<string, int> stringMap;
		for(int i=0; i<count; i++)
		{
			map<string, int>::iterator item = stringMap.find(arr[i]);
			if( item != stringMap.end() )
			{
				stringMap[str]++;
			}else
				stringMap.insert(pair<string, int>(str, 1));
				
		}
		
		/*
		map<string, int>::iterator iter = stringMap.begin();
		while(true)
		{
			if(iter == stringMap.end())
				break;
			cout << iter->first << " : " << endl;
			iter++;
		} */
	}
	
	
	return 0;
}
