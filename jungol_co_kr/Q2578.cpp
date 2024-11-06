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
    vector<int> linked; // ����� ���� �ε��� ����
};

Bus arr[5000];

// �� ������ �����ϰų� ����Ǵ��� Ȯ���ϴ� �Լ�
bool checkCross(const Bus& b1, const Bus& b2) {
    // b1�� �������̰� b2�� ������ ���
    if (b1.x1 == b1.x2 && b2.y1 == b2.y2) {
        return (b1.x1 >= min(b2.x1, b2.x2) && b1.x1 <= max(b2.x1, b2.x2)) &&
            (b2.y1 >= min(b1.y1, b1.y2) && b2.y1 <= max(b1.y1, b1.y2));
    }
    // b1�� �����̰� b2�� �������� ���
    else if (b1.y1 == b1.y2 && b2.x1 == b2.x2) {
        return (b1.y1 >= min(b2.y1, b2.y2) && b1.y1 <= max(b2.y1, b2.y2)) &&
            (b2.x1 >= min(b1.x1, b1.x2) && b2.x1 <= max(b1.x1, b1.x2));
    }
    // �� ������ �������� ���
    else if (b1.x1 == b1.x2 && b2.x1 == b2.x2 && b1.x1 == b2.x1) {
        return max(b1.y1, b1.y2) >= min(b2.y1, b2.y2) &&
            max(b2.y1, b2.y2) >= min(b1.y1, b1.y2);
    }
    // �� ������ ������ ���
    else if (b1.y1 == b1.y2 && b2.y1 == b2.y2 && b1.y1 == b2.y1) {
        return max(b1.x1, b1.x2) >= min(b2.x1, b2.x2) &&
            max(b2.x1, b2.x2) >= min(b1.x1, b1.x2);
    }
    return false;
}

// ����� �Ǵ� �������� ���ԵǴ� ���� ã��
bool isPointOnBus(const Bus& bus, int x, int y) {
    if (bus.x1 == bus.x2) // ������
        return bus.x1 == x && y >= min(bus.y1, bus.y2) && y <= max(bus.y1, bus.y2);
    else if (bus.y1 == bus.y2) // ����
        return bus.y1 == y && x >= min(bus.x1, bus.x2) && x <= max(bus.x1, bus.x2);
    return false;
}

// BFS�� ����Ͽ� �ּ� ȯ�� �� ���
int findMinBuses(int startX, int startY, int destX, int destY, int busCount) {
    queue<pair<int, int>> q; // {���� �ε���, ��� ����}
    vector<bool> visited(busCount, false);
    vector<int> startBuses, destBuses;

    // ������� �������� ���ԵǴ� ���� ��� ã��
    for (int i = 0; i < busCount; i++) {
        if (isPointOnBus(arr[i], startX, startY))
            startBuses.push_back(i);
        if (isPointOnBus(arr[i], destX, destY))
            destBuses.push_back(i);
    }

    // BFS �ʱ�ȭ
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

    return -1; // ��θ� ã�� �� ���� ��
}

int main() {
    cin >> m >> n; // ���ο� ���� ũ�� �Է�
    int busCount;
    cin >> busCount;

    for (int i = 0; i < busCount; i++) {
        scanf("%d %d %d %d %d", &arr[i].num, &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
        for (int j = 0; j < i; j++) {
            if (checkCross(arr[i], arr[j])) { // ���� �� ����� ����
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
