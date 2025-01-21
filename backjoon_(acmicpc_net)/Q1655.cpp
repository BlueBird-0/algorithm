#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, num;
    scanf("%d", &n);

    map<int, int> numbers;
    int count = 0; // �� �Էµ� ������ ����
    auto mid = numbers.end(); // �߾Ӱ��� ����ų �ݺ���

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        numbers[num]++;
        count++;

        if (count == 1) {
            // ù ��° ��Ұ� ������ �߾Ӱ��� �� ��� ��ü
            mid = numbers.begin();
        }
        else {
            // ��Ұ� Ȧ������ ���� ¦������ �� mid�� �̵� ������ �޶���
            if (num < mid->first && count % 2 == 0) {
                mid--;
            }
            else if (num >= mid->first && count % 2 == 1) {
                if (count % 2 == 1 && mid->second == 1) {
                    mid++;
                }
            }
        }

        // ������ �߾Ӱ� ���
        printf("Median: %d\n", mid->first);
    }

    return 0;
}
