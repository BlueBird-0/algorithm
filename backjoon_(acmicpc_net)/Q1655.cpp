#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, num;
    scanf("%d", &n);

    map<int, int> numbers;
    int count = 0; // 총 입력된 숫자의 개수
    auto mid = numbers.end(); // 중앙값을 가리킬 반복자

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        numbers[num]++;
        count++;

        if (count == 1) {
            // 첫 번째 요소가 들어오면 중앙값은 그 요소 자체
            mid = numbers.begin();
        }
        else {
            // 요소가 홀수개일 때와 짝수개일 때 mid의 이동 방향이 달라짐
            if (num < mid->first && count % 2 == 0) {
                mid--;
            }
            else if (num >= mid->first && count % 2 == 1) {
                if (count % 2 == 1 && mid->second == 1) {
                    mid++;
                }
            }
        }

        // 현재의 중앙값 출력
        printf("Median: %d\n", mid->first);
    }

    return 0;
}
