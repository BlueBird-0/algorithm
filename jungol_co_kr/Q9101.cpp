#include <iostream>
using namespace std;
void print(int n, int limit)
{
    if(n> limit)
        return;
        
    cout << n <<" "<<endl;
    print(n+1, limit);
}

int main()
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}
