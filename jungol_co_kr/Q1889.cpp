#include <iostream>
using namespace std;

int N;
int result = 0;
bool col[13] = { 0, };      // �� ���� ���� �ִ���
bool diag1[25] = { 0, };    // �»�� -> ���ϴ� �밢�� üũ
bool diag2[25] = { 0, };    // ���� -> ���ϴ� �밢�� üũ

void check(int row) {
    if (row == N) {
        result++;
        return;
    }

    for (int x = 0; x < N; x++) {
        if (!col[x] && !diag1[row - x + N] && !diag2[row + x]) {
            // ���� ��ġ�� �� ������
            col[x] = diag1[row - x + N] = diag2[row + x] = true;
            check(row + 1);  // ���� ������ �̵�
            col[x] = diag1[row - x + N] = diag2[row + x] = false;
        }
    }
}

int main() {
    cin >> N;
    check(0);
    cout << result << endl;
    return 0;
}
