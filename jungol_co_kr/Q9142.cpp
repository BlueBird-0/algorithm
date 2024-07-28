#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[3];
	string str;

	int *p = arr;
	string* pstr = &str;

	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> *(p+i);
		cout << *(p+i) << " ";
	}
	cout << endl;
	cin >> str;
	cout << str << endl;
	cin >> *pstr;
	cout << *pstr << endl;

	return 0;
}