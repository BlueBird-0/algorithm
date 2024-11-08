#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));

// 스도쿠 규칙에 따라 숫자가 유효한지 확인하는 함수
bool isValid(int row, int col, int num) {
    // 가로 줄 체크
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;
    }
    // 세로 줄 체크
    for (int y = 0; y < 9; y++) {
        if (board[y][col] == num) return false;
    }
    // 3x3 박스 체크
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == num) return false;
        }
    }
    return true;
}

// 백트래킹을 통해 스도쿠를 해결하는 함수
bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {  // 빈 칸 찾기
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {  // 유효한 숫자라면
                        board[row][col] = num;     // 숫자를 넣고
                        if (solveSudoku()) return true;  // 재귀 호출로 해결 시도
                        board[row][col] = 0;       // 실패 시 백트래킹
                    }
                }
                return false;  // 가능한 숫자가 없다면 실패
            }
        }
    }
    return true;  // 모든 칸을 채웠다면 성공
}

int main() {
    // 입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    // 스도쿠 풀이
    if (solveSudoku()) {
        // 결과 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "Solution does not exist\n";
    }

    return 0;
}
