#include <iostream>
#include <vector>
using namespace std;

int board[9][9] = { 0, };
vector<pair<int, int>> emptyCells; // ºó Ä­ ÁÂÇ¥ ÀúÀå

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

// ºó Ä­¸¸ Å½»ö
bool find(int index) {
    if (index == emptyCells.size())
        return true;

    int y = emptyCells[index].first;
    int x = emptyCells[index].second;

    for (int n = 1; n <= 9; n++) {
        if (ableHorizon(y, n) && ableVertical(x, n) && ableBox(x, y, n)) {
            board[y][x] = n;
            if (find(index + 1)) // ´ÙÀ½ ºó Ä­À¸·Î ³Ñ¾î°¨
                return true;
            board[y][x] = 0; // ¹éÆ®·¡Å·
        }
    }

    return false;
}

int main() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            scanf("%d", &board[y][x]);
            if (board[y][x] == 0) {
                emptyCells.push_back({ y, x }); // ºó Ä­ ÀúÀå
            }
        }
    }

    find(0); // ºó Ä­ Ã¹ ¹øÂ°ºÎÅÍ ½ÃÀÛ

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            printf("%-2d", board[y][x]);
        }
        printf("\n");
    }

    return 0;
}