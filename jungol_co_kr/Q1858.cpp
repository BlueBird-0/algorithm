#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int la, lb;
    string a, b;
    cin >> la >> a >> lb >> b;

    // dp �迭 �ʱ�ȭ
    vector<vector<int>> dp(la + 1, vector<int>(lb + 1, 0)); //null�� �߰�

    // LCS ���絵 ���
    for (int y = 1; y <= la; y++) {
        for (int x = 1; x <= lb; x++) {
            if (a[y - 1] == b[x - 1]) {
                dp[y][x] = dp[y - 1][x - 1] + 3;
            }
            else {
                dp[y][x] = max({ dp[y - 1][x - 1] - 2, dp[y - 1][x] - 2, dp[y][x - 1] - 2, 0 });
            }
        }
    }

    // �ִ� ���絵 �� �ִ� ������ ���� ã��
    int max_score = INT_MIN;
    int x = 0, y = 0;

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if (dp[i][j] > max_score) {
                max_score = dp[i][j];
                y = i;
                x = j;
            }
        }
    }

    // �ִ� ������ ������ ã��
    int inity = y;
    int initx = x;

    while (dp[y][x] != 0) {
        if (dp[y - 1][x] == dp[y][x] + 2) {
            y--;
        }
        else if (dp[y][x - 1] == dp[y][x] + 2) {
            x--;
        }
        else {
            x--;
            y--;
        }
    }

    // ���
    cout << max_score << endl;
    for (int i = y + 1; i <= inity; i++) {
        cout << a[i - 1];
    }
    cout << endl;
    for (int i = x + 1; i <= initx; i++) {
        cout << b[i - 1];
    }
    cout << endl;

    return 0;
}
