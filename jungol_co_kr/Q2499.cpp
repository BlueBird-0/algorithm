#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int arr[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n, less<int>());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (res + 1 < arr[i])
            break;
        res += arr[i];
    }
	res += 1;

    printf("%d\n", res);

    return 0;
}