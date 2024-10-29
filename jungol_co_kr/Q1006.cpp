#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int map[101][101];
bool visited[101][101][5];  // ��ġ(x, y)�� ����(dir) ���� �湮 ���θ� ����

// ���� �̵� (��, ��, ��, ��)
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

// ���¸� ������ ����ü
struct State {
    int x, y, dir, cnt;
};

// ���� ȸ�� (1:��, 2:��, 3:��, 4:��)
int turnLeft(int dir) {
    if (dir == 1) return 4;  // �� -> ��
    if (dir == 2) return 3;  // �� -> ��
    if (dir == 3) return 1;  // �� -> ��
    return 2;  // �� -> ��
}

int turnRight(int dir) {
    if (dir == 1) return 3;  // �� -> ��
    if (dir == 2) return 4;  // �� -> ��
    if (dir == 3) return 2;  // �� -> ��
    return 1;  // �� -> ��
}

// ���� ��ġ���� �־��� �������� kĭ ������ �� �ִ��� Ȯ��
bool canGoK(int dir, int k, int x, int y) {
    for (int i = 1; i <= k; i++) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (nx < 1 || nx > N || ny < 1 || ny > M || map[ny][nx] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> M >> N;
    for (int y = 1; y <= M; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> map[y][x];
        }
    }

    int nowy, nowx, nowD, endy, endx, endD;
    cin >> nowy >> nowx >> nowD;
    cin >> endy >> endx >> endD;

    queue<State> q;
    q.push({ nowx, nowy, nowD, 0 });
    visited[nowy][nowx][nowD] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // ��ǥ ������ ���⿡ �������� ��� ��� Ƚ�� ��� �� ����
        if (current.x == endx && current.y == endy && current.dir == endD) {
            cout << current.cnt << endl;
            return 0;
        }

        // Go ��� (1, 2, 3 ĭ)
        for (int k = 1; k <= 3; k++) {
            if (canGoK(current.dir, k, current.x, current.y)) {
                int nx = current.x + dx[current.dir] * k;
                int ny = current.y + dy[current.dir] * k;
                if (!visited[ny][nx][current.dir]) {
                    visited[ny][nx][current.dir] = true;
                    q.push({ nx, ny, current.dir, current.cnt + 1 });
                }
            }
            else break;  // �߰��� ������ �� �̻� �̵��� �ʿ䰡 ����
        }

        // ��ȸ��
        int leftDir = turnLeft(current.dir);
        if (!visited[current.y][current.x][leftDir]) {
            visited[current.y][current.x][leftDir] = true;
            q.push({ current.x, current.y, leftDir, current.cnt + 1 });
        }

        // ��ȸ��
        int rightDir = turnRight(current.dir);
        if (!visited[current.y][current.x][rightDir]) {
            visited[current.y][current.x][rightDir] = true;
            q.push({ current.x, current.y, rightDir, current.cnt + 1 });
        }
    }

    return 0;
}
