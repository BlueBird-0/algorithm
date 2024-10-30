#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> canMeasureWeights(const vector<int>& weights, const vector<int>& marbles) {
    int maxWeight = 15000;
    vector<bool> dp(maxWeight * 2 + 1, false);
    dp[maxWeight] = true;

    for (int weight : weights) {
        vector<bool> new_dp(dp);
        for (int i = 0; i <= maxWeight * 2; ++i) {
            if (dp[i]) {
                new_dp[i + weight] = true; // 왼쪽에 추 추가
                new_dp[i - weight] = true; // 오른쪽에 추 추가
            }
        }
        dp = new_dp; // DP 배열 업데이트
    }

    // 구슬 무게 확인
    vector<char> result;
    for (int marble : marbles) {
        if (marble > maxWeight || !dp[marble + maxWeight]) {
            result.push_back('N'); // 무게를 만들 수 없음
        }
        else {
            result.push_back('Y'); // 무게를 만들 수 있음
        }
    }

    return result;
}
int n, m;

int main() {
    int temp;
    vector<int> weights;
    vector<int> marbles;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        weights.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        marbles.push_back(temp);
    }

    vector<char> result = canMeasureWeights(weights, marbles);
    for (char res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
