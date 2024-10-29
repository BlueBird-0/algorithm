#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int map[101][101];
bool visited[101][101][5];  // 위치(x, y)와 방향(dir) 별로 방문 여부를 저장

// 방향 이동 (동, 서, 남, 북)
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

// 상태를 저장할 구조체
struct State {
    int x, y, dir, cnt;
};

// 방향 회전 (1:동, 2:서, 3:남, 4:북)
int turnLeft(int dir) {
    if (dir == 1) return 4;  // 동 -> 북
    if (dir == 2) return 3;  // 서 -> 남
    if (dir == 3) return 1;  // 남 -> 동
    return 2;  // 북 -> 서
}

int turnRight(int dir) {
    if (dir == 1) return 3;  // 동 -> 남
    if (dir == 2) return 4;  // 서 -> 북
    if (dir == 3) return 2;  // 남 -> 서
    return 1;  // 북 -> 동
}

// 현재 위치에서 주어진 방향으로 k칸 움직일 수 있는지 확인
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

        // 목표 지점과 방향에 도달했을 경우 명령 횟수 출력 후 종료
        if (current.x == endx && current.y == endy && current.dir == endD) {
            cout << current.cnt << endl;
            return 0;
        }

        // Go 명령 (1, 2, 3 칸)
        for (int k = 1; k <= 3; k++) {
            if (canGoK(current.dir, k, current.x, current.y)) {
                int nx = current.x + dx[current.dir] * k;
                int ny = current.y + dy[current.dir] * k;
                if (!visited[ny][nx][current.dir]) {
                    visited[ny][nx][current.dir] = true;
                    q.push({ nx, ny, current.dir, current.cnt + 1 });
                }
            }
            else break;  // 중간에 막히면 더 이상 이동할 필요가 없음
        }

        // 좌회전
        int leftDir = turnLeft(current.dir);
        if (!visited[current.y][current.x][leftDir]) {
            visited[current.y][current.x][leftDir] = true;
            q.push({ current.x, current.y, leftDir, current.cnt + 1 });
        }

        // 우회전
        int rightDir = turnRight(current.dir);
        if (!visited[current.y][current.x][rightDir]) {
            visited[current.y][current.x][rightDir] = true;
            q.push({ current.x, current.y, rightDir, current.cnt + 1 });
        }
    }

    return 0;
}
