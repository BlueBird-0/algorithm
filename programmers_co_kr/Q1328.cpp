#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N + 1);
    vector<int> result(N + 1);
    stack<int> s;               // 스택 (빌딩의 인덱스를 저장)

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 오른쪽에서 보이는 가장 가까운 빌딩 찾기
    for (int i = N; i >= 1; i--) {
        // 스택의 빌딩이 현재 빌딩보다 작거나 같으면 pop (보이지 않으므로)
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // 스택이 비어있지 않으면 스택의 top이 가장 가까운 빌딩
        if (!s.empty()) {
            result[i] = s.top();
        }
        else {
            result[i] = 0;  // 보이는 빌딩이 없을 경우
        }

        // 현재 빌딩을 스택에 push
        s.push(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
