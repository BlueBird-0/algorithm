#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#define NMAX 100010
#define PAIR pair<int, int>
using namespace std;
 
int N, M, X;
int A, B;
 
int visited[NMAX];
vector< int > ans;
vector< PAIR > graph[NMAX];
 
int search(int cur, int d) {
    int nxt, nd, cnt=0;
 
    for(PAIR p:graph[cur]) {
        nxt = p.first;
        nd = p.second;
        if(d != nd or visited[nxt]) continue;
 
        visited[nxt] = 1;
        cnt += search(nxt, d)+1;
    }
 
    return cnt;
}
 
int main() {
    scanf("%d %d %d", &N, &M, &X);
    for(int i=1;i<=M;i++) {
        scanf("%d %d", &A, &B);
 
        graph[A].push_back({B, 1});
        graph[B].push_back({A, -1});
    }
 
    // d=-1: X보다 큰 값 개수 / d=1: X보다 작은 값 개수
    for(int d=-1;d<=1;d+=2) {
        memset(visited, 0, sizeof(visited));
 
        visited[X] = 1;
        ans.push_back(search(X, d));
    }
 
    printf("%d %d", ans[0]+1, N-ans[1]);
 
}
