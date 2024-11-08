#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));

// ������ ��Ģ�� ���� ���ڰ� ��ȿ���� Ȯ���ϴ� �Լ�
bool isValid(int row, int col, int num) {
    // ���� �� üũ
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;
    }
    // ���� �� üũ
    for (int y = 0; y < 9; y++) {
        if (board[y][col] == num) return false;
    }
    // 3x3 �ڽ� üũ
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == num) return false;
        }
    }
    return true;
}

// ��Ʈ��ŷ�� ���� ������ �ذ��ϴ� �Լ�
bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {  // �� ĭ ã��
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {  // ��ȿ�� ���ڶ��
                        board[row][col] = num;     // ���ڸ� �ְ�
                        if (solveSudoku()) return true;  // ��� ȣ��� �ذ� �õ�
                        board[row][col] = 0;       // ���� �� ��Ʈ��ŷ
                    }
                }
                return false;  // ������ ���ڰ� ���ٸ� ����
            }
        }
    }
    return true;  // ��� ĭ�� ä���ٸ� ����
}

int main() {
    // �Է� �ޱ�
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    // ������ Ǯ��
    if (solveSudoku()) {
        // ��� ���
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
