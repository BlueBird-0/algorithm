#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }


    for (int i = 0; i < n; i++) {
        int temp = pq.top();
        pq.pop();
        if (temp > 0)
            pq.push(temp-1);
        else {
            pq.push(0);
        }
    }

    while (!pq.empty()) {
        int sum = pq.top();
        pq.pop();
        answer += sum * sum;
    }
    return answer;
}

using namespace std;
int main() {
    int n=4;

    vector<int> works;
    works.push_back(4);
    works.push_back(3);
    works.push_back(3);
	printf("%lld", solution(n, works));
}