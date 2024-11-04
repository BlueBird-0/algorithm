#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
stack<pair<int, unsigned long long>> arr;  // (index, height)

int main() {
    cin >> N;

    unsigned long long maxArea = 0;    // 최댓값 저장 변수
    unsigned long long newH = 0;       // 새로운 히스토그램 높이

    for (int i = 0; i <= N; i++) {
        if (i < N) {
            cin >> newH;
        }
        else {
            newH = 0;  // 마지막에 스택을 비우기 위한 높이 설정
        }

        int startIndex = i;

        while (!arr.empty() && arr.top().second > newH) {
            auto top = arr.top();
            arr.pop();
            unsigned long long area = top.second * (i - top.first);
            maxArea = max(maxArea, area);
            startIndex = top.first;  // 현재 인덱스 업데이트
        }

        // 스택에 현재 높이를 push
        arr.push(make_pair(startIndex, newH));  // emplace 대신 make_pair 사용
    }

    cout << maxArea << '\n';
    return 0;
}
