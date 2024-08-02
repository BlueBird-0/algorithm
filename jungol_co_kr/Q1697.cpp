#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue<int> que;
	char ch;
	int in;
	cin >>in;
	while(in--)
	{
		cin >> ch;
		if(ch == 'i')
		{
			int n;
			cin >> n;
			que.push(n);
		}else if(ch == 'o')
		{
			int n;
			n = que.front();
			if(que.empty())
				cout << "empty"<<endl;
			else {
				que.pop();
				cout << n << endl;
			}
		}else if(ch == 'c')
		{
			cout<< que.size()<<endl;
		}
	}
	
	return 0;
}
