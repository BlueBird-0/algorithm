#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int m, n;

struct Bus {
    int num;
    int x1, y1, x2, y2;
    vector<int> linked; // 연결된 버스 인덱스 저장
};

Bus arr[5000];

// 두 버스가 교차하거나 연결되는지 확인하는 함수
bool checkCross(const Bus& b1, const Bus& b2) {
    // b1이 수직선이고 b2가 수평선인 경우
    if (b1.x1 == b1.x2 && b2.y1 == b2.y2) {
        return (b1.x1 >= min(b2.x1, b2.x2) && b1.x1 <= max(b2.x1, b2.x2)) &&
            (b2.y1 >= min(b1.y1, b1.y2) && b2.y1 <= max(b1.y1, b1.y2));
    }
    // b1이 수평선이고 b2가 수직선인 경우
    else if (b1.y1 == b1.y2 && b2.x1 == b2.x2) {
        return (b1.y1 >= min(b2.y1, b2.y2) && b1.y1 <= max(b2.y1, b2.y2)) &&
            (b2.x1 >= min(b1.x1, b1.x2) && b2.x1 <= max(b1.x1, b1.x2));
    }
    // 두 버스가 수직선일 경우
    else if (b1.x1 == b1.x2 && b2.x1 == b2.x2 && b1.x1 == b2.x1) {
        return max(b1.y1, b1.y2) >= min(b2.y1, b2.y2) &&
            max(b2.y1, b2.y2) >= min(b1.y1, b1.y2);
    }
    // 두 버스가 수평선일 경우
    else if (b1.y1 == b1.y2 && b2.y1 == b2.y2 && b1.y1 == b2.y1) {
        return max(b1.x1, b1.x2) >= min(b2.x1, b2.x2) &&
            max(b2.x1, b2.x2) >= min(b1.x1, b1.x2);
    }
    return false;
}

// 출발지 또는 목적지에 포함되는 버스 찾기
bool isPointOnBus(const Bus& bus, int x, int y) {
    if (bus.x1 == bus.x2) // 수직선
        return bus.x1 == x && y >= min(bus.y1, bus.y2) && y <= max(bus.y1, bus.y2);
    else if (bus.y1 == bus.y2) // 수평선
        return bus.y1 == y && x >= min(bus.x1, bus.x2) && x <= max(bus.x1, bus.x2);
    return false;
}

// BFS를 사용하여 최소 환승 수 계산
int findMinBuses(int startX, int startY, int destX, int destY, int busCount) {
    queue<pair<int, int>> q; // {버스 인덱스, 경로 길이}
    vector<bool> visited(busCount, false);
    vector<int> startBuses, destBuses;

    // 출발지와 목적지에 포함되는 버스 목록 찾기
    for (int i = 0; i < busCount; i++) {
        if (isPointOnBus(arr[i], startX, startY))
            startBuses.push_back(i);
        if (isPointOnBus(arr[i], destX, destY))
            destBuses.push_back(i);
    }

    // BFS 초기화
    for (int bus : startBuses) {
        q.push(make_pair(bus, 1));
        visited[bus] = true;
    }

    while (!q.empty()) {
        int busIdx = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (find(destBuses.begin(), destBuses.end(), busIdx) != destBuses.end()) {
            return dist;
        }

        for (int nextBus : arr[busIdx].linked) {
            if (!visited[nextBus]) {
                visited[nextBus] = true;
                q.push(make_pair(nextBus, dist + 1));
            }
        }
    }

    return -1; // 경로를 찾을 수 없을 때
}

int main() {
    cin >> m >> n; // 가로와 세로 크기 입력
    int busCount;
    cin >> busCount;

    for (int i = 0; i < busCount; i++) {
        scanf("%d %d %d %d %d", &arr[i].num, &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
        for (int j = 0; j < i; j++) {
            if (checkCross(arr[i], arr[j])) { // 교차 시 양방향 연결
                arr[i].linked.push_back(j);
                arr[j].linked.push_back(i);
            }
        }
    }

    int startX, startY, destX, destY;
    cin >> startX >> startY >> destX >> destY;

    int result = findMinBuses(startX, startY, destX, destY, busCount);
    cout << result << endl;

    return 0;
}
