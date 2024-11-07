#include <iostream>
#include <vector>
#include <memory.h>
#include <limits.h>
using namespace std;

int V, E;

int arr[401][401] = { 0, };
int main()
{

    cin >> V >> E;
    int stt, dst, val;
    //init
    for (int i = 0; i <= V; i++)
        for (int j = 0; j <= V; j++)
            arr[i][j] = 10000 * 401;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &stt, &dst, &val);
        arr[stt][dst] = val;
    }

    //floyd warshall
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                arr[i][k] = min(arr[i][k], arr[i][j] + arr[j][k]);
            }
        }
    }

    int result = 10000 * 401;
    for (int i = 1; i <= V; i++)
        result = min(result, arr[i][i]);

    printf("%d", result == 10000 * 401 ? -1 : result);
}