#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <math.h>

using namespace std;
map<int, bool> primes;
queue<pair<int, int>> arr;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int propagation(int stt, int dst) {
	string str, eStr;
	
	arr.push(make_pair(stt, 0));
	primes[stt] = true;

	while (!arr.empty()) {
		int temp = arr.front().first;
		int visit = arr.front().second;
		if (temp == dst)
			return visit;

		//printf("%d\n", temp);

		str = to_string(temp);
		arr.pop();


		for (auto e : primes) {
			if (!e.second) {
				eStr = to_string(e.first);
				int count = 0;
				if (str[0] == eStr[0])
					count++;
				if (str[1] == eStr[1])
					count++;
				if (str[2] == eStr[2])
					count++;
				if (str[3] == eStr[3])
					count++;
				if (count == 3) {
					primes[e.first] = true;
					arr.push(make_pair(e.first, visit+1));
				}
			}
		}
	}
}

int main()
{
	int src, dst; 
	cin >> src >> dst;
	for (int i = 1000; i < 10000; i++)
	{
		if (isPrime(i))
			primes[i] = false;
	}

	//for (auto e : primes)
	//	printf("%d\n", e.first);
	//printf("%d", primes.size());

	printf("%d", propagation(src, dst));
}