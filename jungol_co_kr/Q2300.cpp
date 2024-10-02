#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>


using namespace std;

int getBinary(int* arr, int stt, int end, int search) {
    int closest_value = arr[stt]; // 초기값은 시작 인덱스의 값
    while (stt <= end) {
        int mid = stt + (end - stt) / 2;

        // 현재 중간 값과 비교하여 가까운 값을 업데이트
        if (abs(arr[mid] - search) < abs(closest_value - search)) {
            closest_value = arr[mid];
        }

        // search 값과 중간 값 비교
        if (arr[mid] < search) {
            stt = mid + 1; // 오른쪽으로 이동
        }
        else if (arr[mid] > search) {
            end = mid - 1; // 왼쪽으로 이동
        }
        else {
            // 정확한 값을 찾은 경우
            return arr[mid];
        }
    }

    return closest_value; // search와 가장 가까운 값 반환
}

int main() {
	int acids[100001] = { 0, };
	int alkalis[100001] = { 0, };
    int sizeA = 0;
    int sizeB = 0;

    int N, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        if (input < 0)
            acids[sizeA++] = input;
        else
            alkalis[sizeB++] = input;
    }

    int result = INT_MAX;
    pair<int, int> resultP;

	for (int i = 0; i < sizeA; i++)
    {
        int search = abs(acids[i]);

		int value = getBinary(alkalis, 0, sizeB, search);
        if (value != 0) {
            int diff = abs(acids[i] + value);

            if (diff < result) {
                result = diff;
                resultP = make_pair(acids[i], value);
            }
        }
    }
    //숫자 같은것 중 작은값 찾기
    if (sizeA > 1)
    {
        int temp = abs(acids[sizeA-2] + acids[sizeA-1]);
        if (temp <= result) { 
            result = temp;
            resultP = make_pair(acids[sizeA-2], acids[sizeA-1]);
        }
    }
    if (sizeB > 1)
    {
        int temp = abs(alkalis[0] + alkalis[1]);
        if (temp <= result) {
            result = temp;
            resultP = make_pair(alkalis[0], alkalis[1]);
        }
    }

    printf("%d %d", resultP.first, resultP.second);

    return 0;
}
