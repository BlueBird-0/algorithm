#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
stack<pair<int, unsigned long long>> arr;  // (index, height)

int main() {
    cin >> N;

    unsigned long long maxArea = 0;    // �ִ� ���� ����
    unsigned long long newH = 0;       // ���ο� ������׷� ����

    for (int i = 0; i <= N; i++) {
        if (i < N) {
            cin >> newH;
        }
        else {
            newH = 0;  // �������� ������ ���� ���� ���� ����
        }

        int startIndex = i;

        while (!arr.empty() && arr.top().second > newH) {
            auto top = arr.top();
            arr.pop();
            unsigned long long area = top.second * (i - top.first);
            maxArea = max(maxArea, area);
            startIndex = top.first;  // ���� �ε��� ������Ʈ
        }

        // ���ÿ� ���� ���̸� push
        arr.push(make_pair(startIndex, newH));  // emplace ��� make_pair ���
    }

    cout << maxArea << '\n';
    return 0;
}
