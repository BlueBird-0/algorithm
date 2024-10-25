#include <iostream>
#include <algorithm>
using namespace std;

int board[10][10];
bool diag1[20], diag2[20]; // �밢�� üũ �迭
int n;
int maxBishops = 0;

void dfs(int y, int x, int count, bool color) {
    if (x >= n) { // ���� ���� ������ �˻������� ���� ������ �̵�
        y++;
        x = (y % 2 == color) ? 0 : 1; // ���� ���� ���� �� ��ġ
    }
    if (y >= n) { // ������ ����� ������ ���
        maxBishops = max(maxBishops, count);
        return;
    }

    if (board[y][x] && !diag1[y + x] && !diag2[y - x + n - 1]) {
        diag1[y + x] = diag2[y - x + n - 1] = true;
        dfs(y, x + 2, count + 1, color); // ���� ��ġ�� �̵� (Ȧ¦ �� ���� ����)
        diag1[y + x] = diag2[y - x + n - 1] = false;
    }
    dfs(y, x + 2, count, color); // ����� ���� �ʰ� ���� ��ġ�� �̵�
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    dfs(0, 0, 0, 0); // Ȧ�� ������ ���� (������ ĭ)
    int blackMax = maxBishops;

    maxBishops = 0;
    dfs(0, 1, 0, 1); // ¦�� ������ ���� (��� ĭ)
    int whiteMax = maxBishops;

    cout << blackMax + whiteMax << endl;
    return 0;
}
