#include <iostream>
#include <vector>
using namespace std;

int board[9][9] = { 0, };
vector<pair<int, int>> emptyCells; // �� ĭ ��ǥ ����

bool ableHorizon(int y, int value) {
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == value)
            return false;
    }
    return true;
}

bool ableVertical(int x, int value) {
    for (int i = 0; i < 9; i++) {
        if (board[i][x] == value)
            return false;
    }
    return true;
}

bool ableBox(int x, int y, int value) {
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startY; i < startY + 3; i++) {
        for (int j = startX; j < startX + 3; j++) {
            if (board[i][j] == value)
                return false;
        }
    }
    return true;
}

// �� ĭ�� Ž��
bool find(int index) {
    if (index == emptyCells.size())
        return true;

    int y = emptyCells[index].first;
    int x = emptyCells[index].second;

    for (int n = 1; n <= 9; n++) {
        if (ableHorizon(y, n) && ableVertical(x, n) && ableBox(x, y, n)) {
            board[y][x] = n;
            if (find(index + 1)) // ���� �� ĭ���� �Ѿ
                return true;
            board[y][x] = 0; // ��Ʈ��ŷ
        }
    }

    return false;
}

int main() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            scanf("%d", &board[y][x]);
            if (board[y][x] == 0) {
                emptyCells.push_back({ y, x }); // �� ĭ ����
            }
        }
    }

    find(0); // �� ĭ ù ��°���� ����

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            printf("%-2d", board[y][x]);
        }
        printf("\n");
    }

    return 0;
}