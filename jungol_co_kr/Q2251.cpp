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

    // �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        cin >> switches[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> lights[i];
    }

    // ����ġ ��ȣ�� ���� ��ȣ�� ��ġ�� ����
    map<int, int> lightPosition;
    for (int i = 0; i < N; i++) {
        lightPosition[lights[i]] = i;
    }

    // �� ����ġ�� ���� ���� ��ġ�� ��� �迭
    vector<int> mappedSwitches(N);
    for (int i = 0; i < N; i++) {
        mappedSwitches[i] = lightPosition[switches[i]];
    }

    // ���� ���� �κ� ���� ã��
    vector<int> lis, idx;
    vector<int> trace(N, -1); // ������ ���� �迭
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

        // ���� ��ġ ����
        if (index > 0) trace[i] = idx[index - 1];
    }

    // ��� ��� ����
    vector<int> result;
    for (int i = idx[lis.size() - 1]; i != -1; i = trace[i]) {
        result.push_back(switches[i]);
    }

    // �������� ����
    sort(result.begin(), result.end());

    // ��� ���
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
