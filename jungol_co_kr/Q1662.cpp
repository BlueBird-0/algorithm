#include <iostream>
#include <algorithm>
using namespace std;

int board[10][10];
bool diag1[20], diag2[20]; // 대각선 체크 배열
int n;
int maxBishops = 0;

void dfs(int y, int x, int count, bool color) {
    if (x >= n) { // 현재 행의 끝까지 검사했으면 다음 행으로 이동
        y++;
        x = (y % 2 == color) ? 0 : 1; // 다음 행의 시작 열 위치
    }
    if (y >= n) { // 마지막 행까지 도달한 경우
        maxBishops = max(maxBishops, count);
        return;
    }

    if (board[y][x] && !diag1[y + x] && !diag2[y - x + n - 1]) {
        diag1[y + x] = diag2[y - x + n - 1] = true;
        dfs(y, x + 2, count + 1, color); // 다음 위치로 이동 (홀짝 행 간격 유지)
        diag1[y + x] = diag2[y - x + n - 1] = false;
    }
    dfs(y, x + 2, count, color); // 비숍을 놓지 않고 다음 위치로 이동
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    dfs(0, 0, 0, 0); // 홀수 열부터 시작 (검은색 칸)
    int blackMax = maxBishops;

    maxBishops = 0;
    dfs(0, 1, 0, 1); // 짝수 열부터 시작 (흰색 칸)
    int whiteMax = maxBishops;

    cout << blackMax + whiteMax << endl;
    return 0;
}
