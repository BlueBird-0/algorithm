#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> switches(N);
    vector<int> lights(N);

    // 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> switches[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> lights[i];
    }

    // 스위치 번호를 전구 번호의 위치로 매핑
    map<int, int> lightPosition;
    for (int i = 0; i < N; i++) {
        lightPosition[lights[i]] = i;
    }

    // 각 스위치의 전구 매핑 위치를 담는 배열
    vector<int> mappedSwitches(N);
    for (int i = 0; i < N; i++) {
        mappedSwitches[i] = lightPosition[switches[i]];
    }

    // 최장 증가 부분 수열 찾기
    vector<int> lis, idx;
    vector<int> trace(N, -1); // 추적을 위한 배열
    for (int i = 0; i < N; i++) {
        auto pos = lower_bound(lis.begin(), lis.end(), mappedSwitches[i]);
        int index = pos - lis.begin();

        if (pos == lis.end()) {
            lis.push_back(mappedSwitches[i]);
            idx.push_back(i);
        }
        else {
            *pos = mappedSwitches[i];
            idx[index] = i;
        }

        // 이전 위치 추적
        if (index > 0) trace[i] = idx[index - 1];
    }

    // 결과 경로 추적
    vector<int> result;
    for (int i = idx[lis.size() - 1]; i != -1; i = trace[i]) {
        result.push_back(switches[i]);
    }

    // 오름차순 정렬
    sort(result.begin(), result.end());

    // 결과 출력
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
