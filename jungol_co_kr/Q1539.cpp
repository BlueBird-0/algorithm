#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Block {
    int num;
    int area;
    int height;
    int weight;
};

int main() {
    int N;
    cin >> N;

    vector<Block> arr(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &arr[i].area, &arr[i].height, &arr[i].weight);
        arr[i].num = i + 1;
    }

    // 밑면 면적을 기준으로 오름차순 정렬
	sort(arr.begin(), arr.end(), [](Block& a, Block& b) {return a.area < b.area; });

    // DP 배열: 각 블록을 마지막에 쌓았을 때의 최대 높이
    vector<int> dp(N);
    vector<int> prev(N, -1);  // 최적 경로를 추적하기 위한 배열

    int maxHeight = 0;
    int lastIndex = 0; // 최대 높이에서의 마지막 블록 인덱스

    // DP 테이블 채우기
    for (int i = 0; i < N; i++) {
        dp[i] = arr[i].height;
        for (int j = 0; j < i; j++) {
            if (arr[i].weight > arr[j].weight && arr[i].area > arr[j].area) {
                if (dp[i] < dp[j] + arr[i].height) {
                    dp[i] = dp[j] + arr[i].height;
                    prev[i] = j;
                }
            }
        }

        // 최대 높이와 인덱스 갱신
        if (maxHeight < dp[i]) {
            maxHeight = dp[i];
            lastIndex = i;
        }
    }


    vector<int> result;
    for (int i = lastIndex; i != -1; i = prev[i]) {
        result.push_back(arr[i].num);
    }
    reverse(result.begin(), result.end());

    printf("%d\n", result.size());
    for (int num : result) {
        printf("%d\n", num);
    }

    return 0;
}
