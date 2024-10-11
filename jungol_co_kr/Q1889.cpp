#include <iostream>
using namespace std;

int N;
int result = 0;
bool col[13] = { 0, };      // 각 열에 퀸이 있는지
bool diag1[25] = { 0, };    // 좌상단 -> 우하단 대각선 체크
bool diag2[25] = { 0, };    // 우상단 -> 좌하단 대각선 체크

void check(int row) {
    if (row == N) {
        result++;
        return;
    }

    for (int x = 0; x < N; x++) {
        if (!col[x] && !diag1[row - x + N] && !diag2[row + x]) {
            // 퀸을 배치할 수 있으면
            col[x] = diag1[row - x + N] = diag2[row + x] = true;
            check(row + 1);  // 다음 행으로 이동
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
