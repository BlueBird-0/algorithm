#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

//int maxN;
bool checkAble(vector<int> &stones, int &k, int people) {
    int c = 0;
    //if (people > maxN)
    //    return false;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - people < 0) {
            c++;
            if (c == k)
                return false;
        }
        else
            c = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
	int stt = 0, end = 200000000;
    int mid = (end + stt) / 2;

   // for (int i = 0; i < stones.size(); i++) {
   //     maxN = max(stones[i], maxN);
   // }


    while (stt <= end) {
        mid = (end + stt) / 2;

        if (checkAble(stones, k, mid)) {
			stt = mid + 1;
            answer = max(answer, mid);
        }
        else {
			end = mid - 1;
        }

    }
	return answer;
}

void main() {
    int k = 3;
    vector<int> stones = {2,4, 5, 3,2,1,4,2,5,1};
    cout << solution(stones, k);
}