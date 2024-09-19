#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <limits>
using namespace std;

int check(vector<int> cards)
{
    int result = 0;
    int N = cards.size();

    //same check
    map<int, int> m;
    for (auto e : cards) {
        m[e]++;
    }
    int maxC = 0;
    for (auto e : m) {
        maxC = max(e.second, maxC);
    }
    result = N - maxC;

    //increase
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = cards[j] - cards[i];
            int step = j - i;
            int d = diff / step;
            
            int count = 0;
            int start = cards[i] - i * d;
            for (int k = 0; k < N; k++) {
                if (cards[k] != start + k * d) {
                    count++;
                }
            }
            result = min(count, result);

        }
    }

    return result;
}

int main() {
    vector<int> cards;
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        cards.push_back(temp);
    }

    // 결과 출력
    cout << check(cards) ;

    return 0;
}
