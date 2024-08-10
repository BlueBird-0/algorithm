#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n;
	cin >> T;
	while (T--)
	{
		int arr[100001];
		string func, str;
		cin >> func >> n >> str;

		//배열입력
		stringstream ss(str.substr(1, str.size() - 2));
		for(int i=0; i<n; i++)
		{
			string num;
			getline(ss, num, ',');
			arr[i] = stoi(num);
		}
		int stt = 0;
		int end = n;

		//함수
		bool forward = true;
		bool error = false;

		int size = func.length();
		for (int i = 0; i < size; i++)
		{
			if (func[i] == 'R') {
				forward = !forward;
			}
			else if (func[i] == 'D') {
				if (stt == end) {
					error = true;
					break;
				}else
					forward? stt++ : end--;
			}
		}

		//출력
		if (error)
			cout << "error" << endl;
		else {
			cout << "[";
			if (forward)
			{
				for (int i = stt; i < end; i++) {
					if (i != stt)
						cout << ",";
					cout << arr[i];
				}
			}
			else {
				for (int i = end-1; i >= stt; i--) {
					if (i != end-1)
						cout << ",";
					cout << arr[i];
				}
			}
			cout << "]" << endl;
		}
	}
	return 0;
};