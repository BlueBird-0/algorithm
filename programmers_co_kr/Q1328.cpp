#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N + 1);
    vector<int> result(N + 1);
    stack<int> s;               // ���� (������ �ε����� ����)

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // �����ʿ��� ���̴� ���� ����� ���� ã��
    for (int i = N; i >= 1; i--) {
        // ������ ������ ���� �������� �۰ų� ������ pop (������ �����Ƿ�)
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // ������ ������� ������ ������ top�� ���� ����� ����
        if (!s.empty()) {
            result[i] = s.top();
        }
        else {
            result[i] = 0;  // ���̴� ������ ���� ���
        }

        // ���� ������ ���ÿ� push
        s.push(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
