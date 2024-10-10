#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

struct Delivery {
    int start;
    int end;
    int box;
};

bool compare(const Delivery& a, const Delivery& b) {
    return (a.end < b.end);
}

int getBox(vector<int>& capacity, int start, int end, int box) {
    int minCapacity = INT_MAX;
    for (int i = start; i <= end; i++) {
        if (capacity[i] < minCapacity) {
            minCapacity = capacity[i];
        }
    }

    int result = min(minCapacity, box);
    for (int i = start; i <= end; i++) {
        capacity[i] -= result;
    }

    return result;
}

int main() {
    int n, c, m;
    cin >> n >> c >> m;

    vector<Delivery> deliveries(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &deliveries[i].start, &deliveries[i].end, &deliveries[i].box);
    }

    // 도착지점 순서로 정렬
    sort(deliveries.begin(), deliveries.end(), compare);

    // 각 마을의 용량을 나타내는 배열
    vector<int> capacity(n + 1, c);

    int sum = 0;
    for (int i = 0; i < deliveries.size(); i++) {
        int dept = deliveries[i].start;
        int arri = deliveries[i].end;
        int box = deliveries[i].box;

        sum += getBox(capacity, dept + 1, arri, box);
    }

    cout << sum << endl;

    return 0;
}
